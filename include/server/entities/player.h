#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/body_linked_entity.h"
#include "common/move_direction.h"

class PlayerEntity : public Entity, public BodyLinkedEntity {
public:
	PlayerEntity(const float x, const float y);

	virtual void beginContactWith(Entity * other, b2Contact * contact) override;
	virtual void endContactWith(Entity * other, b2Contact * contact) override;

	void keyDown(const MoveDirection direction);
	void keyUp(const MoveDirection direction);

	void applyMovement();

	void handleFloorContact(b2Contact * contact, bool isBegin);

private:
	bool isOnTheFloor = false;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	void applyImpulseToCenter(float vx, float vy);
};

#endif  // PLAYER_ENTITY_H
