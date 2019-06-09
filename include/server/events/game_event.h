#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "server/entities/entity.h"

enum GameEventType {
    INVALID_GE = 0,
    ENTITY_STATE_UPDATE,
    ENTITY_SET_ACTIVE
};

class GameEvent {
public:
    explicit GameEvent() = default;
    GameEvent(Entity * entity);
    GameEvent(Entity * entity, bool active);

	GameEventType type = INVALID_GE;
	Entity* entity = nullptr;
	bool active = false;
};

#endif
