#ifndef TELEPORTABLE_ENTITY_H
#define TELEPORTABLE_ENTITY_H

#include "Box2D/Box2D.h"
#include "server/entities/portal.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/handle_contact.h"

class TeleportableEntity : public HandleContact, public BodyLinked, public Entity {
public:
	using Entity::Entity;

    virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

    bool isGoingThroughPortal();
    bool applyPositionReset();
    bool markedForPositionReset();

private:
	int goingTroughPortal = 0;
	bool resetPosition = false;

	void goThroughPortal(PortalEntity * inPortal);
};

#endif