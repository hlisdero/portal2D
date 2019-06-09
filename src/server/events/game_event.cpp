#include "server/events/game_event.h"

GameEvent::GameEvent(Entity * entity) : 
	type(ENTITY_STATE_UPDATE), entity(entity) {}

GameEvent::GameEvent(Entity * entity, bool active) : 
	type(ENTITY_SET_ACTIVE), entity(entity), active(active) {}