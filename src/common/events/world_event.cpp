#include "common/events/world_event.h"

WorldEvent::WorldEvent(WorldEventType type, int id) : type(type), id(id) {}

WorldEvent::WorldEvent(int id, EntityType type,
                       const Position& position, State state) :
    type(ENTITY_CREATION), id(id), entity_type(type), position(position), state(state) {}

WorldEvent::WorldEvent(int id) :
    type(ENTITY_DESTRUCTION), id(id) {}

WorldEvent::WorldEvent(int id, const Position& position) :
    type(POSITION_UPDATE), id(id), position(position) {}

WorldEvent::WorldEvent(int id, State state) :
    type(STATE_UPDATE), id(id), state(state) {}
