#ifndef DYNAMIC_ELEMENT_HPP
#define DYNAMIC_ELEMENT_HPP

#include <string>

enum DynamicElementType {
	// Dynamic
	Rock,
	Player,

	// Kinematic
	EnergyBall,
	PortalCreationLaser // TODO check: optional but can be cool
}

class DynamicElement {
public:
	void attachElementToWorld(b2World & world) = 0;

private:
	int originX;
	int originY;
};

#endif  // DYNAMIC_ELEMENT_HPP
