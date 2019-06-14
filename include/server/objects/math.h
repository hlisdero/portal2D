#ifndef MATH_H
#define MATH_H

#include "Box2D/Box2D.h"

class Math {
public:
	constexpr static float PI = 3.1415926f;

	static float getRotationDegFromNormal(const b2Vec2 & normal);
	static float degToRad(float degrees);
	static float radToDeg(float radians);
	static b2Vec2 rotateVectorBy(float rotationRad, const b2Vec2 & vector);
};

#endif