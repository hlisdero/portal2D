#include "client/objects/metal_block.h"

MetalBlock::MetalBlock(const Size& size, const Position& initial, Ratio& ratio, const Texture& texture) :
    Block(size, initial, ratio, texture) {
    sprite.addClip(1, 600, 193, 193);
}
