#include "client/objects/metal_block.h"

MetalBlock::MetalBlock(const Size& size, const Position& initial,
                       const WorldViewSettings& settings, const Texture& texture) :
    Block(size, initial, settings, texture) {
    sprite.addClip(415, 9, 192, 192);
}
