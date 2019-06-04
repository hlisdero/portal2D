#ifndef PORTAL_CREATION_EVENT_H
#define PORTAL_CREATION_EVENT_H

#include "common/events/world_event.h"
#include "server/entities/state.h"

class PortalCreationEvent : public WorldEvent {
public:
	PortalCreationEvent(int entityId, float x, float y, float rotation, PortalColor color);

private:
	int entityId;
	float x;
	float y;
	float rotation;
	PortalColor color;

};

#endif