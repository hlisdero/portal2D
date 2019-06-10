#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "server/entities/entity.h"
#include "server/objects/game_status.h"

enum GameEventType {
    INVALID_GE = 0,
    ENTITY_STATE_UPDATE,
    ENTITY_SET_ACTIVE,
    ENTITY_TELEPORT,
    PORTALS_RESET,
    GAME_STATUS_CHANGE,
    KILL_PLAYER,
    ENERGY_BALL_DESTRUCTION
};

class GameEvent {
public:
    GameEvent(GameEventType type, Entity * entity);
    GameEvent(Entity * entity, bool active);
    GameEvent(GameStatus status);

	GameEventType type = INVALID_GE;
	Entity* entity = nullptr;
	bool active = false;
    GameStatus status = INVALID_STATUS;
};

#endif
