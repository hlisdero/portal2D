#include "server/events/game_event.h"

GameEvent::GameEvent(Entity * entity) : type(ENTITY_STATE_UPDATE), entity(entity) {}