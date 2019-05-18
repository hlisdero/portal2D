#ifndef ENTITY_H
#define ENTITY_H

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
	EnergyBall,
	PortalCreationLaser // TODO check: optional but can be cool
};

class Entity {
public:
	Entity(EntityType type, float x, float y);

	float getX();
	float getY();
private:
	EntityType type;
	float x;
	float y;
};

#endif  // ENTITY_H