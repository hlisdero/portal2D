#include "client/objects/end_barrier.h"

EndBarrier::EndBarrier(const Size& size, const Position& initial,
                     const Ratio& ratio, const Texture& texture, double rotation) :
    AnimatedDrawableBox2D(size, initial, ratio, texture) {
    for (int i = 0; i < 4; ++i) {
        animation.addClip(1 + 252*i, 4597, 251, 251, rotation);
    }
}