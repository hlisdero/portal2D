#include "server/objects/math.h"

int Math::getRotationDegFromNormal(const b2Vec2 & outVector) {
	float angleRad = atan2(outVector.y, outVector.x);

	return (radToDeg(angleRad) + 360) % 360; // return in range [0;360]
}

float Math::degToRad(int degrees) {
	return degrees * PI / 180;
}

int Math::radToDeg(float radians) {
	return (int) (radians * 180 / PI);
}

b2Vec2 Math::rotateVectorBy(float rotationRad, const b2Vec2 & vector) {
	return std::move(b2Vec2(
			vector.x * cos(rotationRad) - vector.y * sin(rotationRad),
			vector.x * sin(rotationRad) + vector.y * cos(rotationRad)
	));
}

b2Vec2 Math::vectorFromRotation(float radians) {
	return std::move(b2Vec2(cos(radians), sin(radians)));
}

void Math::toEdgeMiddle(b2Vec2 & point, const b2Vec2 & normal) {
	if(normal.y != 0) {
		point.x = round(point.x);		
	} else {
		point.x = round(point.x / 0.5) * 0.5;;
	}

	if(normal.x != 0) {
		point.y = round(point.y);
	} else {
		point.y = round(point.y / 0.5) * 0.5;;
	}
}