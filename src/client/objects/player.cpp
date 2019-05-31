#include "client/objects/player.h"

Player::Player(const Size& size, const Position& initial,
               const Ratio& ratio, const Texture& texture) :
    DrawableBox2D(size, initial, ratio),
    idle(texture), run(texture),
    jump_rise(texture), jump_apex(texture),
    jump_fall(texture), jump_land(texture),
    current(&idle) {

    for (int i = 0; i < 7; ++i) {
        idle.addClip(1 + 105*i, 2073, 104, 215);
    }

    for (int i = 0; i < 8; ++i) {
        run.addClip(1 + 195*i, 4123, 194, 204);
    }
    for (int i = 0; i < 4; ++i) {
        run.addClip(1 + 195*i, 4328, 194, 204);
    }

    // Jump animations
    for (int i = 0; i < 4; ++i) {
        jump_rise.addClip(1 + 144*i, 855, 143, 228);
    }
    jump_apex.addClip(1, 21, 137, 207);
    for (int i = 0; i < 4; ++i) {
        jump_fall.addClip(1 + 157*i, 1835, 156, 216);
    }
    jump_land.addClip(1, 635, 230, 199);
    jump_land.addClip(232, 635, 230, 199);
}

const Texture& Player::getTexture() {
    return current->getTexture();
}

SDL_Rect* Player::getClip() {
    return current->getClip();
}

SDL_RendererFlip Player::getFlipState() const {
    return flip_state;
}

void Player::updatePosition(const Position& new_position, double angle) {
    updateFlipState(new_position);
    updateAnimation(new_position);
    DrawableBox2D::updatePosition(new_position, angle);
}

void Player::updateFlipState(const Position& new_position) {
    if (new_position.x > currentX()) {
        flip_state = SDL_FLIP_NONE;
    } else if (new_position.x < currentX()) {
        flip_state = SDL_FLIP_HORIZONTAL;
    }
}

void Player::updateAnimation(const Position& new_position) {
    if (new_position.y > currentY()) {
        current = &jump_rise;
    } else if (current == &jump_rise && (new_position.y - currentY()) < 0.01) {
        current = &jump_apex;
    } else if (new_position.y < currentY()) {
        current = &jump_fall;
    } else if (current == &jump_fall && (new_position.y - currentY()) < 0.01) {
        current = &jump_land;
    } else if (current == &idle && isMovingHorizontally(new_position)) {
        current = &run;
    } else {
        current = &idle;
    }
}

bool Player::isMovingHorizontally(const Position& new_position) const {
    return abs(new_position.x - currentX()) > 0.0001;
}

float32 Player::abs(float32 number) const {
    return number > 0? number: -number;
}
