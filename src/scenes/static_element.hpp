#ifndef STATIC_ELEMENT_HPP
#define STATIC_ELEMENT_HPP

#include <string>

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

#endif  // STATIC_ELEMENT_HPP
