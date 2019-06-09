#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "common/entities/entities_types.h"
#include "common/objects/position.h"
#include "common/objects/state.h"

enum GameEventType {
    INVALID_GE = 0,
    ENTITY_STATE_UPDATE
};

class GameEvent {
public:
    explicit GameEvent() = default;

	GameEventType type = INVALID_GE;
};

#endif
