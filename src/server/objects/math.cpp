#include "server/objects/math.h"

float Math::getRotationDegFromNormal(const b2Vec2 & outVector) {
	float angleRad = atan2(outVector.y, outVector.x);

	return radToDeg(angleRad);
}

float Math::degToRad(float degrees) {
	return degrees * PI / 180;
}

float Math::radToDeg(float radians) {
	return radians * 180 / PI;
}

b2Vec2 Math::rotateVectorBy(float rotationRad, const b2Vec2 & vector) {
	return std::move(b2Vec2(
			vector.x * cos(rotationRad) - vector.y * sin(rotationRad),
			vector.x * sin(rotationRad) + vector.y * cos(rotationRad)
	));
}