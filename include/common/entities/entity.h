#ifndef ENTITY_H
#define ENTITY_H

#define KINEMATIC_ENTITY_START 20

enum EntityType {
	// Static
	StoneBlock,
	MetalBlock,
	MetalDiagBlock,
	Acid,
	Door,
	EnergyBar,
	EnergyEmittor,
	EnergyReceiver,
	PlayerSpawn,
	EndCake,
	Button,
	Portal,

	// Dynamic
	Rock,
	Player,

	// Kinematic
	EnergyBall = KINEMATIC_ENTITY_START,
	PortalCreationLaser  // TODO check: optional but can be cool
};


template <class T> class Entity {
public:
	Entity(EntityType type, T x, T y) : 
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