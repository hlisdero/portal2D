#ifndef ENTITY_H
#define ENTITY_H

#include <Box2D/Box2D.h>

enum EntityType {
	// Static
	// - Ground
	TYPE_STONE_BLOCK = 0,
	TYPE_METAL_BLOCK,
	TYPE_METAL_DIAG_BLOCK,
	// - Not Ground
	TYPE_ACID,
	TYPE_DOOR,
	TYPE_ENERGY_BAR,
	TYPE_ENERGY_EMITTOR,
	TYPE_ENERGY_RECEIVER,
	TYPE_ENDCAKE,
	TYPE_BUTTON,
	TYPE_PORTAL,

	// Dynamic
	TYPE_ROCK,
	TYPE_PLAYER,

	// Kinematic
	TYPE_ENERGY_BALL,

	ENTITY_TYPES_LENGTH
};

constexpr EntityType DYNAMIC_ENTITY_START = TYPE_ROCK;

class Entity {
public:
	Entity(EntityType type, float32 x, float32 y, float32 angle = 0.0f) :
	type(type), x(x), y(y), angle(angle) {}

	float32 getX() const {
	    return x;
	}

	float32 getY() const {
		return y;
	}

	float getAngle() const {
		return angle;
	}

	void setX(float32 x) {
		this->x = x;
	}
	void setY(float32 y) {
		this->y = y;
	}

	EntityType getType() const {
		return type;
	}

	void setAngle(float angle) {
		this->angle = angle;
	}

private:
	EntityType type;
	float32 x;
	float32 y;
	float32 angle;
};

#endif  // ENTITY_H
