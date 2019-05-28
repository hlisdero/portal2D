#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/body_linked.h"
#include "server/entities/handle_contact.h"
#include "common/move_direction.h"

class PlayerEntity :  public Entity, public BodyLinked, public HandleContact {
public:
	PlayerEntity(const float x, const float y);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void keyDown(const MoveDirection direction);
	void keyUp(const MoveDirection direction);

	void applyMovement();

	void handleFloorContact(b2Contact * contact, bool isBegin);

private:
	int contactWithTheFloor = 0;
	
	bool isOnTheFloor = false;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	void applyImpulseToCenter(float vx, float vy);
};

#endif  // PLAYER_ENTITY_H
