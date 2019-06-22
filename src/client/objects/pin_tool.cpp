#include "client/objects/pin_tool.h"

PinTool::PinTool(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture) :
    DrawableBox2D(size, initial, settings),
    animation(texture) {

    for(int j = 0; j < 2; j++) {
		for (int i = 0; i < 4; ++i) {
	        animation.addClip(1704 + 199*i, 1102, 198, 198);
	    }
	}
}

const Texture& PinTool::getTexture() {
    return animation.getTexture();
}

SDL_Rect* PinTool::getClip() {
    return animation.getClip();
}

bool PinTool::isFinished() {
    return animation.finished();
}