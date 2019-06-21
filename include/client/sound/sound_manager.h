#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include "client/client_settings.h"
#include "client/sound/sound_effect.h"
#include "client/sound/music.h"
#include "client/event/keyboard_handler.h"
#include "client/event/mouse_handler.h"

extern ClientSettings CLIENT_SETTINGS;

class SoundManager : public KeyboardHandler {
public:
    explicit SoundManager();

    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;
    SoundManager(SoundManager&& other) = delete;
    SoundManager& operator=(SoundManager&& other) = delete;

    ~SoundManager();

    void addSoundEffect(const std::string& name, const std::string& path);
    void addMusic(const std::string& path);

    void playSoundEffect(const std::string& name);
    void playMusic(size_t index);
    void toggleMusic(size_t index);

    int setMusicVolume(int volume);
    int getCurrentMusicVolume() const;

    virtual void handle(const KeyboardEvent& event) override;

private:
    const std::string sounds_dir_prefix;
    std::map<std::string, size_t> sound_effects_names;
    std::map<std::string, SoundEffect> sound_effects;
    std::vector<Music> soundtrack;

    void checkValidIndexMusic(size_t index) const;
};

#endif  // SOUND_MANAGER_H
