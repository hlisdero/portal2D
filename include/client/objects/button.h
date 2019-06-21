#ifndef BUTTON_H
#define BUTTON_H

#include "client/objects/block.h"
#include "client/sound/sound_manager.h"

class Button : public Block {
public:
    Button(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture,
           SoundManager& sound_manager);

    virtual SDL_Rect* getClip() override;

    virtual void playSound() override;

private:
    SoundManager& sound_manager;
};

#endif  // BUTTON_H
