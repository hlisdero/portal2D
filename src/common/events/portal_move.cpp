#include "common/events/portal_move.h"

PortalMoveEvent::PortalMoveEvent(int entityId, float x, float y, float rotation) : WorldEvent(PORTAL_MOVE), entityId(entityId), x(x), y(y), rotation(rotation) {}