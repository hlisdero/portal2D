#ifndef STONE_BLOCK_HPP
#define STONE_BLOCK_HPP


class StoneBlock : StaticElement {
public:
	StoneBlock(YAML::Node yaml) : width(yaml["width"]), height(yaml["height"]), StaticElement(yaml) {}

	void attachElementToGround(b2Body & groundBody) = 0;

private:
	int width;
	int height;
};

#endif  // STONE_BLOCK_HPP
