#include "client/client_settings.h"

ClientSettings CLIENT_SETTINGS;

ClientSettings::ClientSettings() {
    YAML::Node yaml = YAML::LoadFile(CLIENT_CONF_FILE);

    JUMP = getSDLKey(yaml, "jump");
    MOVE_LEFT = getSDLKey(yaml, "move_left");
    MOVE_RIGHT = getSDLKey(yaml, "move_right");

    RESET_PORTALS = getSDLKey(yaml, "reset_portals");
    GRAB_RELEASE_ROCK = getSDLKey(yaml, "grab_release_rock");

    MUTE_MUSIC = getSDLKey(yaml, "mute_music");
    INCREASE_MUSIC_VOLUME = getSDLKey(yaml, "increase_music_volume");
    DECREASE_MUSIC_VOLUME = getSDLKey(yaml, "decrease_music_volume");

    PIXEL_PER_METER = yaml["pixel_per_meter"].as<double>();
    INITIAL_SCREEN_WIDTH = yaml["screen_width"].as<size_t>();
    INITIAL_SCREEN_HEIGHT = yaml["screen_height"].as<size_t>();
    
    FILENAME = yaml["filename"].as<std::string>();
    FRAMERATE = yaml["framerate"].as<std::string>();
    OFFSET_X = yaml["offset_x"].as<std::string>();
    OFFSET_Y = yaml["offset_y"].as<std::string>();
}

SDL_Keycode ClientSettings::getSDLKey(const YAML::Node & yaml, const char * name) {
	return SDL_GetKeyFromName(yaml[name].as<std::string>().c_str());
}