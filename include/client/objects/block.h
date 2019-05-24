#ifndef BLOCK_H
#define BLOCK_H

#include "client/objects/drawable_box2D.h"
#include "client/view/sprite.h"
#include "client/view/texture_creator.h"
#include "common/position.h"
#include "common/ratio.h"

class Block : public DrawableBox2D {
public:
    Block(const Position& initial, Ratio& ratio, Texture& texture);

    virtual Texture& getTexture() override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;
    virtual SDL_Rect* getClip() override;

private:
    Sprite sprite;
};

#endif  // BLOCK_H
