#include "client/sound/music.h"

Music::Music(const std::string& path) {
    music = Mix_LoadMUS(path.c_str());
    if (!music) {
        std::string error_message("Error al cargar música: ");
        error_message += std::string(Mix_GetError());
        throw std::runtime_error(error_message);
    }
}

Music::Music(Music&& other) {
    music = other.music;
    other.music = nullptr;
}

Music& Music::operator=(Music&& other) {
    music = other.music;
    other.music = nullptr;
    return *this;
}

Music::~Music() {
    if (music) {
        Mix_FreeMusic(music);
    }
}

Mix_Music* Music::get() const {
    return music;
}
