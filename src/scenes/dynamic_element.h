#ifndef DYNAMIC_ELEMENT_H
#define DYNAMIC_ELEMENT_H

#include <string>
#include "Box2D/Box2D.h"

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

#endif  // DYNAMIC_ELEMENT_H
