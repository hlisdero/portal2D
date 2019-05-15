#ifndef STONE_BLOCK_H
#define STONE_BLOCK_H

#include "static_element.h"
#include "yaml-cpp/yaml.h"

class StoneBlock : StaticElement {
public:
	StoneBlock(YAML::Node yaml) : width(yaml["width"]), height(yaml["height"]), StaticElement(yaml) {}

	void attachElementToGround(b2Body & groundBody) = 0;

private:
	int width;
	int height;
};

#endif  // STONE_BLOCK_H
