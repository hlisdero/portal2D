#ifndef ANIMATED_DRAWABLE_BOX2D_H
#define ANIMATED_DRAWABLE_BOX2D_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/view/world_view_settings.h"

class AnimatedDrawableBox2D : public DrawableBox2D {
public:
    AnimatedDrawableBox2D(const Size& size, const Position& initial,
                          const WorldViewSettings& settings, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;

protected:
    Animation animation;
};

#endif  // ANIMATED_DRAWABLE_BOX2D_H
