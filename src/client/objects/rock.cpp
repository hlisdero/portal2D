#include "client/objects/rock.h"

Rock::Rock(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(1, 21, 129, 129);
}
