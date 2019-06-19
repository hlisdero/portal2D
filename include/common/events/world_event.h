#ifndef WORLD_EVENT_H
#define WORLD_EVENT_H

#include "common/entities/entities_types.h"
#include "common/objects/position.h"
#include "common/objects/state.h"
#include "common/objects/size.h"

enum WorldEventType {
    INVALID_WE = 0,
    ENTITY_CREATION,
	ENTITY_DESTRUCTION,
    POSITION_UPDATE,
    STATE_UPDATE,
    SELECT_PLAYER,
    END_GAME,
};

class WorldEvent {
public:
    explicit WorldEvent() = default;
    WorldEvent(WorldEventType type, int id = -1);
    WorldEvent(int id, EntityType type,
               const Position& position, State state = STATE_DEFAULT);
    explicit WorldEvent(int id);
	WorldEvent(int id, const Position& position);
    WorldEvent(int id, State state);

	WorldEventType type = INVALID_WE;
    int id = -1;
    EntityType entity_type = TYPE_STONE_BLOCK;
    Position position = {0, 0, 0};
    State state = STATE_DEFAULT;
};

#endif
