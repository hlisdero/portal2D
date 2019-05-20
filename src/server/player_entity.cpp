#include "server/player_entity.h"

PlayerEntity::PlayerEntity(const float x, const float y) :
	Entity(TYPE_PLAYER, x, y) {}

void PlayerEntity::setBody(b2Body * body) {
	this->body = body;
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

void PlayerEntity::setOnTheFloor(const bool isOnTheFloor) {
	this->isOnTheFloor = isOnTheFloor;
}

void PlayerEntity::applyImpulseToCenter(const float vx, const float vy) {
	b2Vec2 vector(vx, vy);
	vector *= this->body->GetMass();

	this->body->ApplyLinearImpulse(vector, this->body->GetWorldCenter(), true);
}

void PlayerEntity::applyMovement() {
	b2Vec2 velocity = this->body->GetLinearVelocity();

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