#ifndef ANIMATED_DRAWABLE_H
#define ANIMATED_DRAWABLE_H

#include "client/objects/drawable.h"
#include "client/texture/finite_animation.h"

class AnimatedDrawable : public Drawable {
public:
    AnimatedDrawable(int x, int y, int width, int height, FiniteAnimation animation);

    virtual const Texture& getTexture() override;
    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;
    virtual SDL_Rect* getClip() override;

    bool finished() const;

private:
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    FiniteAnimation animation;
};

#endif  // ANIMATED_DRAWABLE_H
