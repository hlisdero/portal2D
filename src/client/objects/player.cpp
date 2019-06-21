#include "client/objects/player.h"

Player::Player(const Size& size, const Position& initial,
               const WorldViewSettings& settings, const Texture& texture,
               SoundManager& sound_manager) :
    DrawableBox2D(size, initial, settings),
    idle(texture), run(texture),
    jump_rise(texture), jump_apex(texture),
    jump_fall(texture), jump_land(texture),
    death(texture),
    current(&idle),
    sound_manager(sound_manager) {

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

    for (int i = 0; i < 9; ++i) {
        death.addClip(1 + 174*i, 3447, 173, 202);
    }
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

void Player::updatePosition(const Position& new_position) {
    updateFlipState(new_position);
    updateAnimation(new_position);
    DrawableBox2D::updatePosition(new_position);
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
    } else if ((current == &idle || current == &run) && isMovingHorizontally(new_position)) {
        current = &run;
    } else {
        current = &idle;
    }
}

bool Player::isMovingHorizontally(const Position& new_position) const {
    return abs(new_position.x - currentX()) > 0.0001;
}

bool Player::setDestroy() {
    current = &death;
    return false;
}

bool Player::isFinished() {
    return current == &death && static_cast<FiniteAnimation*>(current)->finished();
}

void Player::playSound() {
    if (current == &run) {
        // sound_manager.playSoundEffect("player_run");
    } else if (current == &jump_rise) {
        // sound_manager.playSoundEffect("player_jump");
    } else if (current == &jump_land) {
        // sound_manager.playSoundEffect("player_land");
    }
}

void Player::playDestroySound() {
    sound_manager.playSoundEffect("player_death");
}
