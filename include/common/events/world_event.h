#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

#include "common/entities/entities_types.h"
#include "common/objects/position.h"
#include "common/objects/state.h"

enum WorldEventType {
    INVALID_WE = 0,
    ENTITY_CREATION = 1,
	ENTITY_DESTRUCTION = 2,
    POSITION_UPDATE = 3,
    STATE_UPDATE = 4,
    SELECT_PLAYER
};

class WorldEvent {
public:
    explicit WorldEvent() = default;
    WorldEvent(int id, EntityType type, const Position& position);
    explicit WorldEvent(int id);
	WorldEvent(int id, const Position& position);
    WorldEvent(int id, const State& state);

	WorldEventType type = INVALID_WE;
    int id = -1;
    EntityType entity_type = TYPE_STONE_BLOCK;
    Position position = {0, 0, 0};
    State state = STATE_DISABLED;
};

#endif
