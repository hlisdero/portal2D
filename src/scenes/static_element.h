#ifndef STATIC_ELEMENT_H
#define STATIC_ELEMENT_H

#include <string>
#include "yaml-cpp/yaml.h"
#include "Box2D/Box2D.h"

enum StaticElementType {
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
	Portal
}

class StaticElement {
public:
	StaticElement(YAML::Node yaml) : x(yaml['x']), y(yaml['y']) {}

	void attachElementToGround(b2Body & groundBody) = 0;

private:
	int x;
	int y;
};

#endif  // STATIC_ELEMENT_H
