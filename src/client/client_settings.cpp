#include "client/client_settings.h"

ClientSettings CLIENT_SETTINGS;

ClientSettings::ClientSettings() {
    YAML::Node yaml = YAML::LoadFile(CLIENT_CONF_FILE);

    PIXEL_PER_METER = yaml["pixel_per_meter"].as<double>();
    INITIAL_SCREEN_WIDTH = yaml["screen_width"].as<size_t>();
    INITIAL_SCREEN_HEIGHT = yaml["screen_height"].as<size_t>();
    
    FILENAME = yaml["filename"].as<std::string>();
    FRAMERATE = yaml["framerate"].as<std::string>();
    OFFSET_X = yaml["offset_x"].as<std::string>();
    OFFSET_Y = yaml["offset_y"].as<std::string>();
}
