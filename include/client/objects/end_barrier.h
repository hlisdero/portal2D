#ifndef END_BARRIER_H
#define END_BARRIER_H

#include "client/objects/animated_drawable_box2D.h"

class EndBarrier : public AnimatedDrawableBox2D {
public:
    EndBarrier(const Size& size, const Position& initial,
              const Ratio& ratio, const Texture& texture, double rotation);
};

#endif  // END_BARRIER_H
