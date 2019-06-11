#ifndef PORTAL_AABB_CALLBACK_H
#define PORTAL_AABB_CALLBACK_H

#include "Box2D/Box2D.h"
#include "server/entities/entity.h"

class PortalAABBCallback : public b2QueryCallback {
public:
	PortalAABBCallback(b2Vec2 edgeA, b2Vec2 edgeB);

	virtual bool ReportFixture(b2Fixture* fixture) override;

	bool isOk();

private:
	b2Vec2 edgeA;
	b2Vec2 edgeB;
	bool edgeAInTheAir = true;
	bool edgeBInTheAir = true;
	bool isValid = true;

	bool isPointOk(Entity* fixture);
};

#endif