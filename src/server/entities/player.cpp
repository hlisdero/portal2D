#include "server/entities/player.h"

PlayerEntity::PlayerEntity() :
	Entity(TYPE_PLAYER, 0, 0, 0) {}

void PlayerEntity::handleFloorContact(b2Contact * contact, bool inContact) {
	float direction = (contact->GetFixtureA()->GetBody()->GetUserData() == this) ? -1.0f : 1.0f;

	if(contact->GetManifold()->localNormal == b2Vec2(0.0f, direction)) {
		this->isOnTheFloor = inContact;
		
		if(inContact) {
			this->hasMovedInTheAir = false;
		}
	}
}

void PlayerEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	this->handleFloorContact(contact, inContact);

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
		float rotation = (portal->getAngle() + twin->getAngle());
		if(rotation >= TwoPI) {
			rotation -= TwoPI;
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
			if(this->isOnTheFloor) {
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

void firePortalGun(float angle) {
	float32 L = 25.0f;

	b2Vec2 & origin = this->getBody()->GetPosition();
	
	b2Vec2 distance(L * cosf(angle), -L * b2Abs(sinf(angle)));
	b2Vec2 end = origin + distance;

	EdgeShapesCallback callback;

	m_world->RayCast(&callback, origin, end);

	if(callback.m_fixture) {
		// check if possible to create a portal
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
	if(!this->isOnTheFloor) {
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
