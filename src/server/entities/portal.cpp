#include "server/entities/portal.h"

PortalEntity::PortalEntity(const float x, const float y, const State color) :
	StateEntity(TYPE_PORTAL, x, y, 0) {}

PortalEntity * PortalEntity::getTwin() {
	return this->getTwin();
}

void PortalEntity::setTwin(PortalEntity * twin) {
	this->twin = twin;
}