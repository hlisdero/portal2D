#ifndef ENTITY_H
#define ENTITY_H

#include "common/entities/entities_types.h"

class Entity {
public:
	Entity(EntityType type, float x, float y, float rotation);

	virtual ~Entity() = default;

	float getX() const;
	float getY() const;
    void setX(float x);
    void setY(float y);

	float getRotationRad() const;
	int getRotationDeg() const;
    void setRotationDeg(int angleDegrees);
    void setRotationRad(float angleRadians);

	EntityType getType() const;

	void setId(const int id);
	int getId() const;

	bool isDestroyed();
	void destroy();

	template <class T>
	T * as() {
		return dynamic_cast<T*>(this);
	}

private:
	EntityType type;
	float x;
	float y;
	int rotation;
	// TODO uint ?
	int id = 0;
	bool destroyed = false;
};

#endif  // ENTITY_H
