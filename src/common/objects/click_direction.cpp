#include "common/objects/click_direction.h"

ClickDirection::ClickDirection(float x, float y) : x(x), y(y) {}

ClickDirection& ClickDirection::operator*(double num) {
    x *= num;
    y *= num;
    return *this;
}

bool ClickDirection::operator==(const ClickDirection& rhs) {
    return (x == rhs.x) && (y == rhs.y);
}
