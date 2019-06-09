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

void PortalEntity::move(const b2Vec2 newPosition, const b2Vec2 & outVector) {
	this->getBody()->SetTransform(newPosition, 0);
	this->setPosition(newPosition);
	
	this->outVector = outVector;
	this->setRotationDeg(getRotationFromNormal(outVector));
}

float PortalEntity::getRotationFromNormal(const b2Vec2 & outVector) {
	float angleRad = atan2(outVector.y, outVector.x);

	return angleRad * 180 / PI;
}