#ifndef PORTAL_ENTITY_H
#define PORTAL_ENTITY_H

#include "server/entities/state_entity.h"

class PortalEntity : public StateEntity, public BodyLinkedEntity {
public:
	PortalEntity(const float x, const float y, const State color);

	// TODO
	//void move();

	PortalEntity * getTwin();
	void setTwin(PortalEntity * twin);

private:
	PortalEntity * twin;
};

#endif  // PORTAL_ENTITY_H