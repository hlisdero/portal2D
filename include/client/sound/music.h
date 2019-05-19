#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include <stdexcept>

class Music {
public:
    Music() = default;
    explicit Music(const std::string& path);

    Music(const Music&) = delete;
    Music& operator=(const Music&) = delete;

    Music(Music&& other);
    Music& operator=(Music&& other);

    ~Music();

    Mix_Music* get() const;

private:
    Mix_Music* music = nullptr;
};

#endif  // MUSIC_H
