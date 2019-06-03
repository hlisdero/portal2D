#include "client/objects/portal.h"

Portal::Portal(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture, double rotation) :
    Block(size, initial, settings, texture, rotation) {
    sprite.addClip(46, 86, 164, 164);
}
