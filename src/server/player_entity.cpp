#include "server/player_entity.h"

PlayerEntity::PlayerEntity(const float x, const float y) :
	Entity(Player, x, y) {}

void PlayerEntity::setBody(b2Body * body) {
	this->body = body;
}

void PlayerEntity::move(const MoveDirection direction) {
	float vx = 0.0f;
	float vy = 0.0f;

	switch(direction) {
		case UP:
			vy = 1.0f;
			break;
		case DOWN:
			vy = -0.5f;
			break;
		case LEFT:
			vx = -1.0f;
			break;
		case RIGHT:
			vx = 1.0f;
			break;
	}

	this->body->ApplyLinearImpulse(b2Vec2(vx, vy), this->body->GetWorldCenter(), true);
}