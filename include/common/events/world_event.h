#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

#include "common/entities/entity.h"
#include "common/objects/position.h"
#include "server/entities/attributes/state.h"

enum WorldEventType {
    ENTITY_CREATION = 0,
	ENTITY_DESTRUCTION,
    POSITION_UPDATE,
    STATE_UPDATE,
};

class WorldEvent {
public:
    WorldEvent(int id, EntityType type, const Position& position);
	WorldEvent(int id, const Position& position);
    WorldEvent(int id, const State& state);

	WorldEventType type;
    int id = -1;
    EntityType entity_type = TYPE_STONE_BLOCK;
    Position position = {0, 0, 0};
    State state = STATE_DISABLED;
};

#endif
