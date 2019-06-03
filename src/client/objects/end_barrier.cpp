#include "client/objects/end_barrier.h"

EndBarrier::EndBarrier(const Size& size, const Position& initial,
                     const double& ratio, const Texture& texture, double rotation) :
    AnimatedDrawableBox2D(size, initial, ratio, texture, rotation) {
    for (int i = 0; i < 4; ++i) {
        animation.addClip(1 + 252*i, 4597, 251, 251);
    }
}
