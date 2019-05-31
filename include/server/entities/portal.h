#ifndef PORTAL_ENTITY_H
#define PORTAL_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/with_state.h"
#include "server/entities/body_linked.h"

class PortalEntity :  public Entity, public WithState, public BodyLinked {
public:
	PortalEntity(const float x, const float y, const PortalColor color);

	void move(const float newX, const float newY);

	PortalEntity * getTwin();
	void setTwin(PortalEntity * twin);

private:
	PortalEntity * twin;
};

#endif  // PORTAL_ENTITY_H