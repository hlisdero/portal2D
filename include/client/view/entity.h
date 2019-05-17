#ifndef ENTITY_H
#define ENTITY_H

#include "sprite.h"

class Entity {
public:
    Entity(Sprite sprite, int x, int y);

    Sprite& getSprite();
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

private:
    Sprite sprite;
    int x;
    int y;
};

#endif  // ENTITY_H
