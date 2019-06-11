#include "server/events/game_event.h"

GameEvent::GameEvent(GameEventType type, Entity * entity) : 
	type(type), entity(entity) {}

GameEvent::GameEvent(Entity * entity, bool active) : 
	type(ENTITY_SET_ACTIVE), entity(entity), active(active) {}

GameEvent::GameEvent(GameStatus status) : 
	type(GAME_STATUS_CHANGE), status(status) {}

GameEvent::GameEvent(size_t playerCount) : 
	type(POTENTIAL_VICTORY), playerCount(playerCount) {}