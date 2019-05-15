#ifndef DIAGONAL_METAL_BLOCK_H
#define DIAGONAL_METAL_BLOCK_H

#include "static_element.h"

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

#endif  // DIAGONAL_METAL_BLOCK_H
