#include "client/client_settings.h"

ClientSettings CLIENT_SETTINGS;

ClientSettings::ClientSettings() {
    std::ifstream conf_file;
    conf_file.open("../data/conf_test/client.conf");
    if (conf_file) {
        conf_file.close();
        std::cout << "Usando configuración de test" << std::endl;
        loadConf("../data/conf_test/client.conf");
    } else {
        loadConf("/etc/portal2d/conf/client.conf");
    }
}

void ClientSettings::loadConf(const std::string& filename) {
    YAML::Node yaml = YAML::LoadFile(filename);

    ASSET_DIR_PREFIX = yaml["asset_dir"].as<std::string>();
    PIXEL_PER_METER = yaml["pixel_per_meter"].as<double>();
    INITIAL_SCREEN_WIDTH = yaml["screen_width"].as<size_t>();
    INITIAL_SCREEN_HEIGHT = yaml["screen_height"].as<size_t>();
}
