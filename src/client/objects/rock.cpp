#include "client/objects/rock.h"

Rock::Rock(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(1, 21, 129, 129, rotation);
}
