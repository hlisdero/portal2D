#ifndef PORTAL_CREATION_EVENT_H
#define PORTAL_CREATION_EVENT_H

#include "common/events/world_event.h"

class PortalCreationEvent : public WorldEvent {
public:
	PortalCreationEvent(int entityId, float x, float y, float rotation, bool color);

private:
	int entityId;
	float x;
	float y;
	float rotation;
	bool color;

};

#endif