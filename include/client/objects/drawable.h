#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "client/screen/texture.h"

class Drawable {
public:
    virtual const Texture& getTexture() = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual SDL_Rect* getClip() {
        return nullptr;
    }

    virtual double getRotation() const {
        return 0.0;
    }

    virtual SDL_RendererFlip getFlipState() const {
        return SDL_FLIP_NONE;
    }

    virtual ~Drawable() = default;
};

#endif  // DRAWABLE_H
