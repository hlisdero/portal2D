#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#define PORTALS_NB 2

#include <cmath>
#include <vector>

#include "Box2D/Box2D.h"

#include "common/objects/move_direction.h"
#include "common/objects/portal_color.h"
#include "server/entities/entity.h"
#include "server/entities/portal.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/teleportable_entity.h"

class PlayerEntity;

#include "server/entities/rock.h"


class PlayerEntity :  public TeleportableEntity {
public:
	PlayerEntity();

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void keyDown(const MoveDirection direction);
	void keyUp(const MoveDirection direction);

	PortalEntity * getPortal(PortalColor color);
	void setPortal(PortalColor color, PortalEntity * portal);

	void applyMovement();

	void handleFloorContact(b2Contact * contact, bool isBegin);

	virtual ~PlayerEntity() override;

private:
	std::vector<b2Contact *> floorsContacts;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	PortalEntity * portals[PORTALS_NB];
	RockEntity * carriedRock;

	void applyImpulseToCenter(float vx, float vy);

	void grabRock(RockEntity* rock);
	void releaseRock();
};

#endif  // PLAYER_ENTITY_H
