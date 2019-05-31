#include "server/entities/portal.h"

PortalEntity::PortalEntity(const float x, const float y, const PortalColor color) :
	Entity(TYPE_PORTAL, x, y, 0.0f), WithState(color) {}

PortalEntity * PortalEntity::getTwin() {
	return this->getTwin();
}

void PortalEntity::setTwin(PortalEntity * twin) {
	this->twin = twin;
}

void PortalEntity::move(const float newX, const float newY) {
	this->getBody()->SetTransform(b2Vec2(newX, newY), 0);
}