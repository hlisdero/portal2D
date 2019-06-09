#include "server/entities/player.h"

#include "server/entities/rock.h"

PlayerEntity::PlayerEntity(b2Vec2 position, GameEventCreator& gameEventCreator) :
	TeleportableEntity(TYPE_PLAYER, position.x, position.y, 0, gameEventCreator) {
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

void PlayerEntity::resetPortals(b2World & world) {
	for(int i = 0; i < PORTALS_NB; i++) {
		if(portals[i] != nullptr) {
			world.DestroyBody(portals[i]->getBody());
			delete portals[i];
			
			portals[i] = nullptr;
		}
	}
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
	TeleportableEntity::handleContactWith(other, contact, inContact);

	switch(other->getType()) {
		case TYPE_ROCK:
			if(inContact) {
				grabRock(other->as<RockEntity>());
			}
			break;
		case TYPE_ENERGY_BAR:
		case TYPE_END_BARRIER:
			gameEventCreator.addPortalsReset(this);

			if(carriedRock != nullptr) {
				carriedRock->respawn();
				releaseRock();
			}
			break;
		case TYPE_ACID:
			gameEventCreator.addKillPlayer(this);
			break;
		default:
			break;
	}
}

void PlayerEntity::grabRock(RockEntity* rock) {
	if(rock->getHolder() == nullptr && carriedRock == nullptr) {
		carriedRock = rock;
		rock->grab(this);
	}
}

void PlayerEntity::releaseRock() {
	carriedRock->release();
	carriedRock = nullptr;
}

void PlayerEntity::move(const MoveDirection direction, bool pressed) {
	if(pressed) {
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
	} else if(moveDirection == direction) {
		moveDirection = NONE;
	}
}

void PlayerEntity::applyImpulseToCenter(const float vx, const float vy) {
	b2Vec2 vector(vx, vy);
	vector *= getBody()->GetMass();

	getBody()->ApplyLinearImpulse(vector, getBody()->GetWorldCenter(), true);
}

void PlayerEntity::applyMovement() {
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
