#ifndef BODY_FACTORY_H
#define BODY_FACTORY_H

#include "Box2D/Box2D.h"

#include "server/entities/entity.h"

class BodyFactory {
public:
	BodyFactory(b2World & world);

	void createBody(Entity * Entity);

	b2AABB createPortalAABB(b2Vec2 & position, float rotation);

	int getNewId();

private:
	b2World & world;
	int nextDynamicEntityId = 0;

	b2BodyDef createBodyDef(Entity * entity);

	b2PolygonShape createShape(Entity * entity);

	void setDiagBlockShape(b2PolygonShape & shape, 
		const float * entitySettings, b2Vec2 & offset);

	void setButtonShape(b2PolygonShape & shape, 
		const float * entitySettings, b2Vec2 & offset);

	void setDiamondShape(b2PolygonShape & shape, 
		const float * entitySettings, b2Vec2 & offset);

	void setBlockShape(b2PolygonShape & shape, 
		const float * entitySettings, b2Vec2 & offset);

	b2FixtureDef createFixtureDef(Entity * entity, b2PolygonShape * shape,
		b2BodyDef & bodyDef);

	void attachBody(Entity * entity, b2Body * body);
};

#endif  // BODY_FACTORY_H
