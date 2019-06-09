#include "server/events/game_event.h"

GameEvent::GameEvent(GameEventType type, Entity * entity) : 
	type(type), entity(entity) {}

GameEvent::GameEvent(Entity * entity, bool active) : 
	type(ENTITY_SET_ACTIVE), entity(entity), active(active) {}