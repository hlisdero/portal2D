#ifndef ENTITY_H
#define ENTITY_H

#include "yaml-cpp/yaml.h"
#include "common/entities/entities_types.h"

#define PI 3.1415926f

class Entity {
public:
	Entity(EntityType type, float x, float y, float rotation);
	Entity(EntityType type, YAML::Node yaml);

	virtual ~Entity() = default;

	float getX() const;
	float getY() const;
    void setX(float x);
    void setY(float y);

	float getRotationRad() const;
	float getRotationDeg() const;
    void setRotationDeg(float angleDegrees);

	EntityType getType() const;

	void setId(const int id);
	int getId() const;

	template <class T>
	T * as() {
		return static_cast<T*>(this);
	}

private:
	EntityType type;
	float x;
	float y;
	float rotation;
	// TODO uint ?
	int id = 0;
};

#endif  // ENTITY_H
