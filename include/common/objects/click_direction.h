#ifndef CLICK_DIRECTION_H
#define CLICK_DIRECTION_H

class ClickDirection {
public:
    ClickDirection(float x, float y);

    ClickDirection& operator*(double num);

    bool operator==(const ClickDirection& rhs);

    float x = 0;
    float y = 0;
};

#endif  // CLICK_DIRECTION_H
