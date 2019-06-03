#include "client/objects/rock.h"

Rock::Rock(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture, double rotation) :
    Block(size, initial, settings, texture, rotation) {
    sprite.addClip(1, 21, 129, 129);
}
