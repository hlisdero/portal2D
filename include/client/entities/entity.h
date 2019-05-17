#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class Entity {
public:
    Entity(int x, int y);

    virtual Sprite& getSprite() = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    int getX() const;
    int getY() const;
    void setX(int nex_x);
    void setY(int new_y);

private:
    int x;
    int y;
};

#endif  // ENTITY_H
