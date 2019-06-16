#include "client/objects/portal.h"

Portal::Portal(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture,
               const State& state) :
    Block(size, initial, settings, texture) {

    if (state == PORTAL_COLOR_ORANGE) {
    	sprite.addClip(1680, 27, 164, 164);
	} else {
    	sprite.addClip(1862, 26, 164, 164);
	}
}
