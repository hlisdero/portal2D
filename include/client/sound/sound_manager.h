#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "sound_effect.h"
#include "music.h"
#include "keyboard_handler.h"

class SoundManager : public KeyboardHandler {
public:
    explicit SoundManager();

    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;
    SoundManager(SoundManager&& other) = delete;
    SoundManager& operator=(SoundManager&& other) = delete;

    ~SoundManager();

    void addSoundEffect(const std::string& path);
    void addMusic(const std::string& path);

    void playSoundEffect(size_t index);
    void playMusic(size_t index);
    void toggleMusic(size_t index);
    void haltMusic();

    virtual void handle(const KeyboardEvent& event) override;

private:
    std::vector<SoundEffect> sound_effects;
    std::vector<Music> soundtrack;

    void checkValidIndexSoundEffect(size_t index) const;
    void checkValidIndexMusic(size_t index) const;
};

#endif  // SOUND_MANAGER_H
