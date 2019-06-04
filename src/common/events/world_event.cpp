#include "common/events/world_event.h"

WorldEvent::WorldEvent(WorldEventType type) : type(type) {}

WorldEventType WorldEvent::getType() {
	return this->type;
}