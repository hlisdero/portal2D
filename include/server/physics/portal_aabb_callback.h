#ifndef PORTAL_AABB_CALLBACK_H
#define PORTAL_AABB_CALLBACK_H

#include "Box2D/Box2D.h"
#include "server/entities/entity.h"

enum PortalOrientation {
	HORIZONTAL,
	VERTICAL,
	DIAGONAL
};

class PortalAABBCallback : public b2QueryCallback {
public:
	PortalAABBCallback(b2Vec2 edgeA, b2Vec2 edgeB, 
		b2Vec2 & normal, Entity * centerEntity);

	virtual bool ReportFixture(b2Fixture* fixture) override;

	bool isOk();

private:
	b2Vec2 edgeA;
	b2Vec2 edgeB;

	PortalOrientation orientation;
	Entity * centerEntity;

	bool edgeAInTheAir = true;
	bool edgeBInTheAir = true;
	bool isValid = true;

	bool isPointOk(Entity* fixture);

	static PortalOrientation getPortalOrientation(b2Vec2 & normal);
};

#endif