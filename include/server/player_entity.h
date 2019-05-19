#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entities/m_entity.h"
#include "common/move_direction.h"

class PlayerEntity : public MEntity {
public:
	PlayerEntity(const float x, const float y);

	void setBody(b2Body * body);

	void keyDown(const MoveDirection direction);
	void keyUp(const MoveDirection direction);

	void setOnTheFloor(const bool isOnTheFloor);

	void applyMovement();
private:
	b2Body * body;
	bool isOnTheFloor = false;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	void applyImpulseToCenter(float vx, float vy);
};

#endif  // PLAYER_ENTITY_H