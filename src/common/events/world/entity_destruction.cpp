#include "common/events/world/entity_destruction.h"

EntityDestructionEvent::EntityDestructionEvent(int entityId) : WorldEvent(ENTITY_DESTRUCTION), entityId(entityId) {}