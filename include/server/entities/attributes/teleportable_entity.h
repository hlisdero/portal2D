#ifndef TELEPORTABLE_ENTITY_H
#define TELEPORTABLE_ENTITY_H

#include "Box2D/Box2D.h"
#include "server/entities/portal.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/handle_contact.h"
#include "server/events/game_event_creator.h"

class TeleportableEntity : public HandleContact, public BodyLinked, public Entity {
public:
	TeleportableEntity(EntityType type, float x, float y, float rotation,
		GameEventCreator & gameEventCreator);

    virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

    bool isGoingThroughPortal();

    bool isTeleporting();
    void teleport();

protected:
	GameEventCreator& gameEventCreator;

	void teleportTo(const b2Vec2 & position);

private:
	int goingTroughPortal = 0;
	bool teleporting = false;

	void goThroughPortal(PortalEntity * inPortal);
};

#endif