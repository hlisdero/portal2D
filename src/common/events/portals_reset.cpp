#include "common/events/portals_reset.h"

PortalsResetEvent::PortalsResetEvent(int entityId1, int entityId2) : WorldEvent(PORTALS_RESET), entityId1(entityId1), entityId2(entityId2) {}