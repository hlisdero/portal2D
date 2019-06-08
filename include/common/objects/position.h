#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(double x, double y, double z);

    bool operator==(const Position& rhs);

    double x;
    double y;
    double z;
};

#endif // POSITION_H
