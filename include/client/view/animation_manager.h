#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <map>
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

    void addPlayerDeath(const DrawableBox2D& drawable);

private:
    Screen& screen;
    const TextureLoader& textures;
    std::map<size_t, AnimatedDrawable*> animations;
    size_t current = 0;

    void createAnimation(const DrawableBox2D& drawable, FiniteAnimation animation);
};

#endif  // ANIMATION_MANAGER_H
