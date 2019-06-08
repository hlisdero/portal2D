#include "common/objects/position.h"

Position::Position(double x, double y, double z) :
    x(x), y(y), z(z) {}

bool Position::operator==(const Position& rhs) {
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}
