#ifndef BUTTON_H
#define BUTTON_H

#include "client/objects/block.h"

class Button : public Block {
public:
    Button(const Size& size, const Position& initial, const Ratio& ratio, const Texture& texture);

    void toggleState();
};

#endif  // BUTTON_H
