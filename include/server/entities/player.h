#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <cmath>

#include "Box2D/Box2D.h"

#include "common/objects/move_direction.h"
#include "server/entities/entity.h"
#include "server/entities/portal.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/handle_contact.h"

#define PORTALS_NB 2

class PlayerEntity :  public Entity, public BodyLinked, public HandleContact {
public:
	PlayerEntity();

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void keyDown(const MoveDirection direction);
	void keyUp(const MoveDirection direction);

	PortalEntity * getPortal(PortalColor color);
	void setPortal(PortalColor color, PortalEntity * portal);

	void applyMovement();

	void handleFloorContact(b2Contact * contact, bool isBegin);

	bool waitingForResetPosition();

	virtual ~PlayerEntity() override;

private:
	std::vector<b2Contact *> floorsContacts;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	PortalEntity * portals[PORTALS_NB];

	bool resetPosition = false;
	int goingTroughPortal = 0;

	void applyImpulseToCenter(float vx, float vy);

	void goThroughPortal(PortalEntity * portal);
};

#endif  // PLAYER_ENTITY_H
