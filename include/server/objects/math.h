#ifndef MATH_H
#define MATH_H

#include "Box2D/Box2D.h"

class Math {
public:
	constexpr static float PI = 3.1415926f;

	static int getRotationDegFromNormal(const b2Vec2 & normal);
	static float degToRad(int degrees);
	static int radToDeg(float radians);
	static b2Vec2 rotateVectorBy(float rotationRad, const b2Vec2 & vector);
	static b2Vec2 vectorFromRotation(float radians);
	static void toEdgeMiddle(b2Vec2 & point, const b2Vec2 & normal); 
};

#endif