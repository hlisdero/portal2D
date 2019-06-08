#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

#include "common/entities/entity.h"
#include "common/objects/position.h"
#include "common/objects/state.h"

enum WorldEventType {
    INVALID_WE = 0,
    ENTITY_CREATION,
	ENTITY_DESTRUCTION,
    POSITION_UPDATE,
    STATE_UPDATE,
};

class WorldEvent {
public:
    explicit WorldEvent() = default;
    WorldEvent(int id, EntityType type, const Position& position);
	WorldEvent(int id, const Position& position);
    WorldEvent(int id, const State& state);

	WorldEventType type = INVALID_WE;
    int id = -1;
    EntityType entity_type = TYPE_STONE_BLOCK;
    Position position = {0, 0, 0};
    State state = STATE_DISABLED;
};

#endif
