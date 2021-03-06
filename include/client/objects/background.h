#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "client/texture/texture.h"
#include "client/objects/drawable.h"

class Background : public Drawable {
public:
    Background(const size_t& width, const size_t& height, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;
    virtual SDL_Rect* getClip() override;

private:
    const size_t& width;
    const size_t& height;
    const Texture& texture;
    SDL_Rect clip;
};

#endif  // BACKGROUND_H
