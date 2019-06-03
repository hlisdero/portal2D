#ifndef GATE_H
#define GATE_H

#include "client/objects/drawable_box2D.h"
#include "client/texture/animation.h"
#include "client/texture/sprite.h"

class Gate : public DrawableBox2D {
public:
    Gate(const Size& size, const Position& initial,
         const WorldViewSettings& settings, const Texture& texture, double rotation = 0.0);

    virtual const Texture& getTexture();
    virtual SDL_Rect* getClip();

    void open();

private:
    Sprite sprite;
    Animation animation;
    bool open_flag = false;
};

#endif  // GATE_H
