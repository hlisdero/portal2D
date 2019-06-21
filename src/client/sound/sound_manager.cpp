#include "client/sound/sound_manager.h"

SoundManager::SoundManager() :
    sounds_dir_prefix(ASSETS_DIRECTORY + std::string("sounds/")) {
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

    addMusic("soundtrack.mp3");
    addSoundEffects();

    playMusic(0);
}

SoundManager::~SoundManager() {
    Mix_CloseAudio();
    Mix_Quit();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void SoundManager::addSoundEffects() {
    std::map<const char *, const char *> sounds;

    sounds["portal_creation"] = "portal_creation.wav";
    sounds["rock_destruction"] = "rock_destruction.wav";
    sounds["ball_creation"] = "ball_creation.wav";
    sounds["ball_destruction"] = "ball_destruction.wav";
    sounds["player_death"] = "player_death.wav";
    sounds["defeat"] = "defeat.wav";
    sounds["win"] = "win.wav";
    // sounds["button_on"] = "button_on.wav";
    // sounds["button_off"] = "button_off.wav";
    // sounds["gate"] = "gate.wav";
    // sounds["player_run"] = "player_run.wav";
    // sounds["player_land"] = "player_land.wav";
    // sounds["player_jump"] = "player_jump.wav";

    int i = 0;
    for(auto it : sounds) {
        sound_effects.emplace_back(sounds_dir_prefix + it.second);
        sound_effects_names[std::string(it.first)] = i; 
        i++;
    }
}

void SoundManager::addMusic(const std::string& path) {
    soundtrack.emplace_back(sounds_dir_prefix + path);
}

void SoundManager::playSoundEffect(const char * name) {
    size_t i = sound_effects_names[std::string(name)];
    Mix_PlayChannel(-1, sound_effects[i].get(), 0);
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
    if (event.key == SDL_SCANCODE_M) {
        toggleMusic(0);
    } else if (event.key == SDL_SCANCODE_COMMA) {
        setMusicVolume(getCurrentMusicVolume() - 20);
    } else if (event.key == SDL_SCANCODE_PERIOD) {
        setMusicVolume(getCurrentMusicVolume() + 20);
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
