#ifndef ENTITY_DESTRUCTION_EVENT_H
#define ENTITY_DESTRUCTION_EVENT_H

#include "common/events/world_event.h"

class EntityDestructionEvent : public WorldEvent {
public:
	EntityDestructionEvent(int entityId);

private:
	int entityId;
};

#endif