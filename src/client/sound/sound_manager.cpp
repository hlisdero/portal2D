#include "client/sound/sound_manager.h"

SoundManager::SoundManager() {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        std::string error_message("Error al inicializar audio de SDL: ");
        error_message += std::string(SDL_GetError());
        throw std::runtime_error(error_message);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0) {
        std::string error_message("Error al inicializar SDL_mixer: ");
        error_message += std::string(Mix_GetError());
        throw std::runtime_error(error_message);
    }

    addMusic("/var/portal2d/sounds/soundtrack.mp3");
    addSoundEffect("/var/portal2d/sounds/portal_creation.wav");
    playMusic(0);
}

SoundManager::~SoundManager() {
    Mix_CloseAudio();
    Mix_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void SoundManager::addSoundEffect(const std::string& path) {
    sound_effects.emplace_back(path);
}

void SoundManager::addMusic(const std::string& path) {
    soundtrack.emplace_back(path);
}

void SoundManager::playSoundEffect(size_t index) {
    checkValidIndexSoundEffect(index);
    Mix_PlayChannel(-1, sound_effects[index].get(), 0);
}

void SoundManager::playMusic(size_t index) {
    checkValidIndexMusic(index);
    int ret_code = Mix_PlayMusic(soundtrack[index].get(), -1);
    if (ret_code) {
        std::string error_message("Error al reproducir música: ");
        error_message += std::string(Mix_GetError());
        throw std::runtime_error(error_message);
    }
}

void SoundManager::toggleMusic(size_t index) {
    if (!Mix_PlayingMusic()) {
        playMusic(index);
    } else {
        if (Mix_PausedMusic()) {
            Mix_ResumeMusic();
        } else {
            Mix_PauseMusic();
        }
    }
}

int SoundManager::setMusicVolume(int volume) {
    return Mix_VolumeMusic(volume);
}

int SoundManager::getCurrentMusicVolume() const {
    return Mix_VolumeMusic(-1);
}

void SoundManager::handle(const KeyboardEvent& event) {
    if (!event.pressed) {
        return;
    }
    if (event.key == SDLK_m) {
        toggleMusic(0);
    } else if (event.key == SDLK_COMMA) {
        setMusicVolume(getCurrentMusicVolume() - 20);
    } else if (event.key == SDLK_PERIOD) {
        setMusicVolume(getCurrentMusicVolume() + 20);
    }
}

void SoundManager::handle(const MouseEvent& event) {
    if (event.motion) {
        return;
    }
    if (event.pressed) {
        playSoundEffect(0);
    }
}

void SoundManager::checkValidIndexSoundEffect(size_t index) const {
    if (index >= sound_effects.size()) {
        throw std::runtime_error("Error: Número de efecto de sonido inválido");
    }
}

void SoundManager::checkValidIndexMusic(size_t index) const {
    if (index >= soundtrack.size()) {
        throw std::runtime_error("Error: Número de canción inválido");
    }
}
