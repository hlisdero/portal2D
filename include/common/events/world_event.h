#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

#include <memory>

enum WorldEventType {
	DYNAMICS_UPDATE,
	ENTITY_DESTRUCTION,
	PORTAL_CREATION,
	PORTAL_MOVE,
	PORTALS_RESET,
	STATE_UPDATE
};

class WorldEvent {
public:
	WorldEvent(WorldEventType type);

	WorldEventType getType();

private:
	WorldEventType type;
};

typedef std::shared_ptr<WorldEvent> WorldEventPtr;

#endif