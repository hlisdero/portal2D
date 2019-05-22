#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "client/view/sprite.h"

class Drawable {
public:
    virtual Sprite& getSprite() = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual ~Drawable() = default;
};

#endif  // DRAWABLE_H
