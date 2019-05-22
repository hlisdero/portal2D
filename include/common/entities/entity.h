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

	float32 getX() const;
	float32 getY() const;
    void setX(float32 x);
    void setY(float32 y);

	float getAngle() const;
    void setAngle(float angle);

	EntityType getType() const;

private:
	EntityType type;
	float32 x;
	float32 y;
	float32 angle;
};

#endif  // ENTITY_H
