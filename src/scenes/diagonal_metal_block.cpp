#ifndef DIAGONAL_METAL_BLOCK_HPP
#define DIAGONAL_METAL_BLOCK_HPP

enum Orientation {
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
}

class DiagonalMetalBlock : StaticElement {
public:

private:
	Orientation orientation;
};

#endif  // DIAGONAL_METAL_BLOCK_HPP
