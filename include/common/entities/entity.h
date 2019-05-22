#ifndef ENTITY_H
#define ENTITY_H

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

template <class T> class Entity {
public:
	Entity(EntityType type, T x, T y, float angle) : 
	type(type), x(x), y(y) {}

	T getX() const {
	    return this->x;
	}

	T getY() const {
		return this->y;
	}

	void setX(const T x) {
		this->x = x;
	}
	void setY(const T y) {
		this->y = y;
	}

	EntityType getType() const {
		return this->type;
	}
private:
	EntityType type;
	T x;
	T y;
};

#endif  // ENTITY_H