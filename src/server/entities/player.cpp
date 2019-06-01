#include "server/entities/player.h"

PlayerEntity::PlayerEntity() :
	Entity(TYPE_PLAYER, 0, 0, 0) {
	for(int i = 0; i < PORTALS_NB; i++) {
		this->portals[i] = nullptr;
	}
}

PlayerEntity::~PlayerEntity() {
	for(int i = 0; i < PORTALS_NB; i++) {
		if(this->portals[i] != nullptr) {
			delete this->portals[i];
		}
	}
}

PortalEntity * PlayerEntity::getPortal(PortalColor color) {
	return this->portals[color];
}

void PlayerEntity::setPortal(PortalColor color, PortalEntity * portal) {
	PortalEntity * twin = this->portals[(color+1)%PORTALS_NB];
	if(twin != nullptr) {
		twin->setTwin(portal);
		portal->setTwin(twin);
	}
	this->portals[color] = portal;
}

void PlayerEntity::handleFloorContact(bool inContact) {
	this->contactWithTheFloor += inContact ? 1 : -1;

	if(this->contactWithTheFloor > 0) {
		this->hasMovedInTheAir = false;
	}
}

void PlayerEntity::handleContactWith(Entity * other, b2Contact *, bool) {
	switch(other->getType()) {
		case TYPE_PORTAL: 
			this->goThroughPortal(other->as<PortalEntity>());
			break;
		default:
			break;
	}
}

void PlayerEntity::goThroughPortal(PortalEntity * portal) {
	PortalEntity * twin = portal->getTwin();

	if(twin != nullptr) {
		// rotation in [0, 2PI]
		float rotation = (portal->getRotationRad() + twin->getRotationRad());
		if(rotation >= 2*PI) {
			rotation -= 2*PI;
		}

		const b2Vec2 & inVelocity = this->getBody()->GetLinearVelocity();

		// Apply rotation to velocity
		b2Vec2 outVelocity(
			inVelocity.x * cos(rotation) - inVelocity.y * sin(rotation),
			inVelocity.x * sin(rotation) + inVelocity.y * cos(rotation)
			);

		// Update player velocity and position
		this->getBody()->SetLinearVelocity(outVelocity);
		this->getBody()->SetTransform(b2Vec2(twin->getX(), twin->getY()), 0);
	}
}

void PlayerEntity::keyDown(const MoveDirection direction) {
	switch(direction) {
		// If on the floor, jump
		case UP:
			if(this->contactWithTheFloor > 0) {
				// TODO load speed from file
				this->applyImpulseToCenter(0.0f, 5.0f);
			}
			break;
		case LEFT:
		case RIGHT:
			this->moveDirection = direction;
			break;
		default:
			break;
	}
}

void PlayerEntity::keyUp(const MoveDirection direction) {
	if(this->moveDirection == direction) {
		this->moveDirection = NONE;
	}
}

void PlayerEntity::applyImpulseToCenter(const float vx, const float vy) {
	b2Vec2 vector(vx, vy);
	vector *= this->getBody()->GetMass();

	this->getBody()->ApplyLinearImpulse(vector, this->getBody()->GetWorldCenter(), true);
}

void PlayerEntity::applyMovement() {
	b2Vec2 velocity = this->getBody()->GetLinearVelocity();

	// - If on the floor
	// 		- allowed to move in both direction,
	//  	- when the keyboard is released, the player
	//			stop moving imediatly
	// - If not on the floor
	// 		- can move one time in one of the two direction
	//		- after, the player will continue his movement
	//			(no resistance in the air)
	if(this->contactWithTheFloor == 0) {
		if(this->hasMovedInTheAir) {
			return;
		} else {
			this->hasMovedInTheAir = this->moveDirection > NONE;
		}
	}

	// TODO load speed from file
	float targetVelocity;
	switch(this->moveDirection) {
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
	this->applyImpulseToCenter(velocityX, 0.0f);
}
