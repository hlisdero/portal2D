#include "client/view/animation_manager.h"

AnimationManager::AnimationManager(Screen& screen, const WorldViewSettings& settings) :
    screen(screen),
    textures(settings.getTextureLoader()) {}

AnimationManager::~AnimationManager() {
    for (const auto& animation : animations) {
        delete animation.second;
    }
}

void AnimationManager::render() {
    std::vector<size_t> indexes;
    for (const auto& animation : animations) {
        if (animation.second->finished()) {
            indexes.push_back(animation.first);
            continue;
        }
        screen.render(*animation.second);
    }
    // Elimina las animaciones que terminaron
    for (size_t index : indexes) {
        delete animations.at(index);
        animations.erase(index);
        players.erase(index);
    }
}

void AnimationManager::addPlayer(size_t index) {
    players.insert(index);
}

void AnimationManager::showPlayerDeath(size_t index, const DrawableBox2D& drawable) {
    if (!players.count(index)) {
        return;
    }
    FiniteAnimation death(textures["Player"]);
    for (int i = 0; i < 9; ++i) {
        death.addClip(1 + 174*i, 3447, 173, 202);
    }
    createAnimation(drawable, std::move(death));
}

void AnimationManager::createAnimation(const DrawableBox2D& drawable, FiniteAnimation animation) {
    int x = drawable.getX();
    int y = drawable.getY();
    int width = drawable.getWidth();
    int height = drawable.getHeight();
    animations[current++] = new AnimatedDrawable(x, y, height, width, std::move(animation));
}
