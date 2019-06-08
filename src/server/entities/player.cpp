#include "server/entities/player.h"

PlayerEntity::PlayerEntity() :
	Entity(TYPE_PLAYER, 0, 0, 0) {
	for(int i = 0; i < PORTALS_NB; i++) {
		portals[i] = nullptr;
	}
}

PlayerEntity::~PlayerEntity() {
	for(int i = 0; i < PORTALS_NB; i++) {
		if(portals[i] != nullptr) {
			delete portals[i];
		}
	}
}

bool PlayerEntity::waitingForResetPosition() {
	return resetPosition;
}

PortalEntity * PlayerEntity::getPortal(PortalColor color) {
	return portals[color];
}

void PlayerEntity::setPortal(PortalColor color, PortalEntity * portal) {
	PortalEntity * twin = portals[(color+1)%PORTALS_NB];
	if(twin != nullptr) {
		twin->setTwin(portal);
		portal->setTwin(twin);
	}
	portals[color] = portal;
}

void PlayerEntity::handleFloorContact(b2Contact * contact, bool) {
	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);

	bool oldContact = false;

	auto it = floorsContacts.begin();
	while(!oldContact && it != floorsContacts.end()) {
		oldContact = (*it == contact);

		if(oldContact) {
			floorsContacts.erase(it);
		}

		it++;
	}

	if(!oldContact) {
		if(contact->GetFixtureA()->GetBody()->GetUserData() == this) {
			if(worldManifold.normal.y < -0.707) {
				floorsContacts.push_back(contact);
			}
		} else if(worldManifold.normal.y > 0.707) {
			floorsContacts.push_back(contact);
		}
	}

	if(floorsContacts.size() > 0) {
		hasMovedInTheAir = false;
	}
}

void PlayerEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	handleFloorContact(contact, inContact);

	switch(other->getType()) {
		case TYPE_PORTAL: 
			if(inContact) {
				goThroughPortal(other->as<PortalEntity>());
			} else if(goingTroughPortal > 0) {
				goingTroughPortal--;	
			}
			break;
		default:
			break;
	}
}

void PlayerEntity::goThroughPortal(PortalEntity * inPortal) {
	// Do not go through the portal if already going through the portal
	if(goingTroughPortal > 0) {
		return;
	}

	PortalEntity * outPortal = inPortal->getTwin();

	if(outPortal != nullptr) {
		float rotation =  outPortal->getRotationRad() - (PI + inPortal->getRotationRad());
		const b2Vec2 & inVelocity = getBody()->GetLinearVelocity();

		// Apply rotation to velocity
		b2Vec2 outVelocity(
			inVelocity.x * cos(rotation) - inVelocity.y * sin(rotation),
			inVelocity.x * sin(rotation) + inVelocity.y * cos(rotation)
			);

		b2Vec2 outVector = outPortal->getOutVector();

		// Avoid beeing trapped in portals
		outVelocity += outVector;

		outVector *= 0.1;

		// Update player velocity and position
		getBody()->SetLinearVelocity(outVelocity);

		resetPosition = true;
		setX(outPortal->getX() + outVector.x);
		setY(outPortal->getY() + outVector.y);
		goingTroughPortal = 2;
		hasMovedInTheAir = true;
	}
}

void PlayerEntity::keyDown(const MoveDirection direction) {
	switch(direction) {
		// If on the floor, jump
		case UP:
			if(floorsContacts.size() > 0) {
				// TODO load speed from file
				applyImpulseToCenter(0.0f, 5.0f);
			}
			break;
		case LEFT:
		case RIGHT:
			moveDirection = direction;
			break;
		default:
			break;
	}
}

void PlayerEntity::keyUp(const MoveDirection direction) {
	if(moveDirection == direction) {
		moveDirection = NONE;
	}
}

void PlayerEntity::applyImpulseToCenter(const float vx, const float vy) {
	b2Vec2 vector(vx, vy);
	vector *= getBody()->GetMass();

	getBody()->ApplyLinearImpulse(vector, getBody()->GetWorldCenter(), true);
}

void PlayerEntity::applyMovement() {
	if(resetPosition) {
		getBody()->SetTransform(b2Vec2(getX(), getY()), 0);
		resetPosition = false;
	}

	// - If on the floor
	// 		- allowed to move in both direction,
	//  	- when the keyboard is released, the player
	//			stop moving imediatly
	// - If not on the floor
	// 		- can move one time in one of the two direction
	//		- after, the player will continue his movement
	//			(no resistance in the air)
	if(floorsContacts.size() == 0) {
		if(hasMovedInTheAir || moveDirection == NONE) {
			return;
		} else {
			hasMovedInTheAir = true;
		}
	}

	b2Vec2 velocity = getBody()->GetLinearVelocity();

	// TODO load speed from file
	float targetVelocity;
	switch(moveDirection) {
		case RIGHT:
			targetVelocity = 5.0f;
			break;
		case LEFT:
			targetVelocity = -5.0f;
			break;
		default:
			targetVelocity = 0.0f;
			break;
	}

	float velocityX = (targetVelocity - velocity.x);
	applyImpulseToCenter(velocityX, 0.0f);
}
