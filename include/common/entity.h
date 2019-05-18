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

class Entity {
public:
	Entity(EntityType type, float x, float y);

	float getX() const;
	float getY() const;
	EntityType getType() const;

	void setX(const float x);
	void setY(const float y);
private:
	EntityType type;
	float x;
	float y;
};

#endif  // ENTITY_H