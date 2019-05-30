#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <cmath>

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/body_linked.h"
#include "server/entities/handle_contact.h"
#include "common/move_direction.h"
#include "server/entities/portal.h"

class PlayerEntity :  public Entity, public BodyLinked, public HandleContact {
public:
	PlayerEntity();

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

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

	void goThroughPortal(PortalEntity * portal);
};

#endif  // PLAYER_ENTITY_H
