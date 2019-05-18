#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include <stdexcept>

class SoundEffect {
public:
    SoundEffect() = default;
    explicit SoundEffect(const std::string& path);

    SoundEffect(const SoundEffect&) = delete;
    SoundEffect& operator=(const SoundEffect&) = delete;

    SoundEffect(SoundEffect&& other);
    SoundEffect& operator=(SoundEffect&& other);

    ~SoundEffect();

    Mix_Chunk* get() const;

private:
    Mix_Chunk* sound_effect = nullptr;
};

#endif  // SOUND_EFFECT_H
