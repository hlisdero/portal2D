#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/body_linked_entity.h"
#include "server/entities/energy_ball.h"

class EntityFactory {
public:
	EntityFactory(b2World & world);

	void createBody(Entity * Entity);

private:
	b2World & world;
};

#endif  // ENTITY_FACTORY_H
