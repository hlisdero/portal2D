#ifndef ACID_H
#define ACID_H

#include "client/objects/animated_drawable_box2D.h"

class Acid : public AnimatedDrawableBox2D {
public:
    Acid(const Size& size, const Position& initial, const double& ratio, const Texture& texture);
};

#endif  // ACID_H
