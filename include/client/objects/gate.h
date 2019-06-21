#ifndef GATE_H
#define GATE_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/finite_animation.h"
#include "client/texture/sprite.h"
#include "client/sound/sound_manager.h"

class Gate : public DrawableBox2D {
public:
    Gate(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture,
         SoundManager& sound_manager);

    virtual const Texture& getTexture();
    virtual SDL_Rect* getClip();

    virtual void updateState(const State& new_state) override;

    virtual void playSound() override;

private:
    Sprite sprite;
    FiniteAnimation animation;
    SoundManager& sound_manager;
};

#endif  // GATE_H
