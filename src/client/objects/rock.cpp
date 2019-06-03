#include "client/objects/rock.h"

Rock::Rock(const Size& size, const Position& initial,
           const double& ratio, const Texture& texture, double rotation) :
    Block(size, initial, ratio, texture, rotation) {
    sprite.addClip(1, 21, 129, 129);
}
