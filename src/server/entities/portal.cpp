#include "server/entities/portal.h"

PortalEntity::PortalEntity(const float x, const float y, const b2Vec2 & normal, const PortalColor color) :
	Entity(TYPE_PORTAL, x, y, getRotationFromNormal(normal)), WithState(color) {}

PortalEntity * PortalEntity::getTwin() {
	return this->twin;
}

void PortalEntity::setTwin(PortalEntity * twin) {
	this->twin = twin;
}

void PortalEntity::move(const float newX, const float newY, const b2Vec2 & normal) {
	this->getBody()->SetTransform(b2Vec2(newX, newY), 0);
	this->setX(newX);
	this->setY(newY);
	this->setRotationDeg(getRotationFromNormal(normal));
}

float PortalEntity::getRotationFromNormal(const b2Vec2 & normal) {
	float angleRad = atan2(normal.y, normal.x);

	return angleRad * 180 / PI;
}