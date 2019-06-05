#include "common/events/world/state_update.h"

StateUpdateEvent::StateUpdateEvent(int entityId, State newState) : WorldEvent(STATE_UPDATE), entityId(entityId), newState(newState) {}