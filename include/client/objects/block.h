#ifndef BLOCK_H
#define BLOCK_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/sprite.h"

class Block : public DrawableBox2D {
public:
    Block(const Size& size, const Position& initial,
          const WorldViewSettings& settings, const Texture& texture, double angle = 0.0);

    virtual const Texture& getTexture() override;
    virtual SDL_Rect* getClip() override;

protected:
    Sprite sprite;
};

#endif  // BLOCK_H
