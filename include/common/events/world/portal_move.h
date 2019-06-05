#ifndef PORTAL_MOVE_EVENT_H
#define PORTAL_MOVE_EVENT_H

#include "common/events/world_event.h"

class PortalMoveEvent : public WorldEvent {
public:
	PortalMoveEvent(int entityId, float x, float y, float rotation);

private:
	int entityId;
	float x;
	float y;
	float rotation;	
};

#endif