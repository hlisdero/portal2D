#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#define PORTALS_NB 2

#include <cmath>
#include <vector>

#include <Box2D/Box2D.h>

#include "common/objects/move_direction.h"
#include "common/objects/portal_color.h"
#include "server/entities/entity.h"
#include "server/entities/portal.h"
#include "server/entities/rock.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/teleportable_entity.h"
#include "server/events/game_event_creator.h"
#include "server/events/event_creator.h"

class RockEntity;

class PlayerEntity :  public TeleportableEntity {
public:
	PlayerEntity(b2Vec2 position, GameEventCreator & gameEventCreator);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

	void move(const MoveDirection& direction, bool pressed);

	PortalEntity * getPortal(PortalColor color);
	void setPortal(PortalColor color, PortalEntity * portal);
	void resetPortals(b2World & world, EventCreator & eventCreator);

	void applyMovement();

	void handleFloorContact(b2Contact * contact, bool isBegin);

	virtual ~PlayerEntity() override;

private:
	std::vector<b2Contact *> floorsContacts;
	// This allow for better gameplay experience
	bool hasMovedInTheAir = false;
	MoveDirection moveDirection = NONE;

	PortalEntity * portals[PORTALS_NB];
	RockEntity * carriedRock = nullptr;

	void applyImpulseToCenter(float vx, float vy);

	void grabRock(RockEntity* rock);
	void releaseRock();
};

#endif  // PLAYER_ENTITY_H
