#ifndef GATE_H
#define GATE_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/finite_animation.h"
#include "client/texture/sprite.h"

class Gate : public DrawableBox2D {
public:
    Gate(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture);

    virtual const Texture& getTexture();
    virtual SDL_Rect* getClip();

    virtual const char * updateState(const State& new_state) override;

private:
    Sprite sprite;
    FiniteAnimation animation;
};

#endif  // GATE_H
