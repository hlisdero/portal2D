#include "client/client_settings.h"

ClientSettings CLIENT_SETTINGS;

ClientSettings::ClientSettings() {
    YAML::Node yaml = YAML::LoadFile(CLIENT_CONF_FILE);

    PIXEL_PER_METER = yaml["pixel_per_meter"].as<double>();
    INITIAL_SCREEN_WIDTH = yaml["screen_width"].as<size_t>();
    INITIAL_SCREEN_HEIGHT = yaml["screen_height"].as<size_t>();
}