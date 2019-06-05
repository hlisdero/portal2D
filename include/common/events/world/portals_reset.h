#ifndef PORTALS_RESET_EVENT_H
#define PORTALS_RESET_EVENT_H

#include "common/events/world_event.h"

class PortalsResetEvent : public WorldEvent {
public:
	PortalsResetEvent(int entityId1, int entityId2);

private:
	int entityId1;
	int entityId2;
};

#endif