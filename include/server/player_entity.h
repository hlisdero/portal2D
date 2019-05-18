#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entity.h"
#include "common/move_direction.h"

class PlayerEntity : public Entity {
public:
	PlayerEntity(const float x, const float y);

	void setBody(b2Body * body);

	void move(const MoveDirection direction);
private:
	b2Body * body;
};

#endif  // PLAYER_ENTITY_H