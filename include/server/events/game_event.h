#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "server/entities/entity.h"

enum GameEventType {
    INVALID_GE = 0,
    ENTITY_STATE_UPDATE
};

class GameEvent {
public:
    explicit GameEvent() = default;
    GameEvent(Entity * entity);

	GameEventType type = INVALID_GE;
	Entity* entity = nullptr;
};

#endif
