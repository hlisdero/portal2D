#ifndef CHARACTER_H
#define CHARACTER_H

#include "client/view/animation.h"
#include "client/objects/drawable.h"
#include "client/view/texture.h"

class Character : public Drawable {
public:
    Character(int x, int y, const Texture& texture);

    virtual const Texture& getTexture() override;
    virtual int getX() const override;
    virtual int getY() const override;
    virtual int getWidth() const override;
    virtual int getHeight() const override;

    virtual SDL_Rect* getClip();

private:
    int x;
    int y;
    Animation animation;
};

#endif  // CHARACTER_H
