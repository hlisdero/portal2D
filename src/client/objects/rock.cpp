#include "client/objects/rock.h"

Rock::Rock(const Size& size, const Position& initial,
           const WorldViewSettings& settings, const Texture& texture) :
    DrawableBox2D(size, initial, settings),
    idle(texture), destruction(texture),
    current(&idle) {

    idle.addClip(1450, 9, 198, 198);

	for (int i = 0; i < 3; ++i) {
        destruction.addClip(0 + 199*i, 1714, 198, 198);
    }
}

const Texture& Rock::getTexture() {
    return current->getTexture();
}

SDL_Rect* Rock::getClip() {
    return current->getClip();
}

bool Rock::setDestroy() {
    current = &destruction;
    return false;
}

bool Rock::isFinished() {
    return current == &destruction && static_cast<FiniteAnimation*>(current)->finished();
}