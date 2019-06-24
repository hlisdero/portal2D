#ifndef CLIENT_SETTINGS_H
#define CLIENT_SETTINGS_H

#include <string>
#include <SDL2/SDL.h>
#include "yaml-cpp/yaml.h"

class ClientSettings {
public:
	explicit ClientSettings();

    // Controls
    SDL_Keycode JUMP;
    SDL_Keycode MOVE_LEFT;
    SDL_Keycode MOVE_RIGHT;

    SDL_Keycode RESET_PORTALS;
    SDL_Keycode GRAB_RELEASE_ROCK;

    SDL_Keycode MUTE_MUSIC;
    SDL_Keycode INCREASE_MUSIC_VOLUME;
    SDL_Keycode DECREASE_MUSIC_VOLUME;

    SDL_Keycode TOGGLE_FULLSCREEN;

    // Controla el tamaño del mundo que se ve
	double PIXEL_PER_METER = 80;

    // Controla el tamaño inicial de la ventana
    size_t INITIAL_SCREEN_WIDTH = 640;
    size_t INITIAL_SCREEN_HEIGHT = 480;

    // Configuración para grabar la pantalla;
    std::string FILENAME;
    std::string FRAMERATE;
    std::string OFFSET_X;
    std::string OFFSET_Y;

private:
    SDL_Keycode getSDLKey(const YAML::Node & yaml, const char * name);
};

#endif  // CLIENT_SETTINGS_H
