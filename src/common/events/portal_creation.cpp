#include "common/events/portal_creation.h"

PortalCreationEvent::PortalCreationEvent(int entityId, float x, float y, float rotation, PortalColor color) : WorldEvent(PORTAL_CREATION), entityId(entityId), x(x), y(y), rotation(rotation), color(color) {}