#include "sound_effect.h"

SoundEffect::SoundEffect(const std::string& path) {
    sound_effect = Mix_LoadWAV(path.c_str());
    if (!sound_effect) {
        std::string error_message("Error al cargar efecto de sonido: ");
        error_message += std::string(Mix_GetError());
        throw std::runtime_error(error_message);
    }
}

SoundEffect::SoundEffect(SoundEffect&& other) {
    sound_effect = other.sound_effect;
    other.sound_effect = nullptr;
}

SoundEffect& SoundEffect::operator=(SoundEffect&& other) {
    sound_effect = other.sound_effect;
    other.sound_effect = nullptr;
    return *this;
}

SoundEffect::~SoundEffect() {
    if (sound_effect) {
        Mix_FreeChunk(sound_effect);
    }
}

Mix_Chunk* SoundEffect::get() const {
    return sound_effect;
}
