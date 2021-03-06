#include "client/objects/acid.h"

Acid::Acid(const Size& size, const Position& initial, const WorldViewSettings& settings, const Texture& texture) :
    AnimatedDrawableBox2D(size, initial, settings, texture) {
    for (int i = 0; i < 8; ++i) {
        animation.addClip(1 + 301*i, 1545, 300, 61);
    }
}
