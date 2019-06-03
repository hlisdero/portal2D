#include "client/objects/metal_block.h"

MetalBlock::MetalBlock(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(1, 600, 193, 193);
}
