#include "server/entities/portal.h"

PortalEntity::PortalEntity(const float x, const float y, const b2Vec2 & outVector, const PortalColor color) : Entity(TYPE_PORTAL, x, y, getRotationFromNormal(outVector)), outVector(outVector), color(color) {}

PortalEntity * PortalEntity::getTwin() {
	return this->twin;
}

void PortalEntity::setTwin(PortalEntity * twin) {
	this->twin = twin;
}

const b2Vec2 & PortalEntity::getOutVector() const {
	return this->outVector;
}

void PortalEntity::move(const float newX, const float newY, const b2Vec2 & outVector) {
	this->getBody()->SetTransform(b2Vec2(newX, newY), 0);
	this->setX(newX);
	this->setY(newY);
	this->outVector = outVector;
	this->setRotationDeg(getRotationFromNormal(outVector));
}

float PortalEntity::getRotationFromNormal(const b2Vec2 & outVector) {
	float angleRad = atan2(outVector.y, outVector.x);

	return angleRad * 180 / PI;
}