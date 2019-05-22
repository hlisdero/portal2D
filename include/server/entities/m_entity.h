#ifndef M_ENTITY_H
#define M_ENTITY_H

#include "Box2D/Box2D.h"
#include "common/entities/entity.h"

// MetersEntity
class MEntity : public Entity<float> {
public:
	using Entity<float>::Entity; // inherit construtor

	virtual void beginContactWith(MEntity * other, b2Contact * contact);
	virtual void endContactWith(MEntity * other, b2Contact * contact);
};

#endif