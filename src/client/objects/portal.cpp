#include "client/objects/portal.h"

Portal::Portal(const Size& size, const Position& initial,
                     Ratio& ratio, const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(46, 86, 164, 164, rotation);
}
