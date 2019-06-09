#ifndef ENTITY_H
#define ENTITY_H

#include "Box2D/Box2D.h"
#include "common/entities/entities_types.h"

#define PI 3.1415926f

class Entity {
public:
	Entity(EntityType type, float x, float y, float rotation);

	virtual ~Entity() = default;

	const b2Vec2 & getPosition() const;
	void setPosition(const b2Vec2 & position);

	float getRotationRad() const;
	float getRotationDeg() const;
    void setRotationDeg(float angleDegrees);

	EntityType getType() const;

	void setId(const int id);
	int getId() const;

	template <class T>
	T * as() {
		return dynamic_cast<T*>(this);
	}

private:
	EntityType type;
	b2Vec2 position;
	float rotation;
	// TODO uint ?
	int id = 0;
};

#endif  // ENTITY_H
