#ifndef BUTTON_H
#define BUTTON_H

#include "client/objects/block.h"

class Button : public Block {
public:
    Button(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture);

    virtual SDL_Rect* getClip() override;
};

#endif  // BUTTON_H
