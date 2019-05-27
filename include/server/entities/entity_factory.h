#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"

class EntityFactory {
public:
	EntityFactory(b2World & world);

	void createBody(Entity * Entity);

private:
	b2World & world;
	int nextDynamicEntityId = 0;

	b2BodyDef createBodyDef(Entity * entity);
	b2PolygonShape createShape(Entity * entity);
	void attachBody(Entity * entity, b2Body * body);
};

#endif  // ENTITY_FACTORY_H
