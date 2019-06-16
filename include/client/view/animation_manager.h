#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <map>
#include <unordered_set>
#include "client/screen/screen.h"
#include "client/objects/animated_drawable.h"
#include "client/objects/drawable_box2D.h"
#include "client/view/world_view_settings.h"

class AnimationManager {
public:
    explicit AnimationManager(Screen& screen, const WorldViewSettings& settings);

    AnimationManager(const AnimationManager&) = delete;
    AnimationManager& operator=(const AnimationManager&) = delete;
    AnimationManager(AnimationManager&& other) = delete;
    AnimationManager& operator=(AnimationManager&& other) = delete;

    ~AnimationManager();

    void render();

    void addPlayer(size_t index);
    void showPlayerDeath(size_t index, const DrawableBox2D& drawable);

private:
    Screen& screen;
    const TextureLoader& textures;
    std::map<size_t, AnimatedDrawable*> animations;
    size_t current = 0;

    std::unordered_set<size_t> players;



    void createAnimation(const DrawableBox2D& drawable, FiniteAnimation animation);
};

#endif  // ANIMATION_MANAGER_H
