#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Box2D/Box2D.h"

#include "server/entities/m_entity.h"

class EntityFactory {
public:
	EntityFactory(b2World & world);

	void createBody(MEntity * Entity);
	
private:
	b2World & world;
};

#endif  // ENTITY_FACTORY_H