#ifndef CLIENT_SETTINGS_H
#define CLIENT_SETTINGS_H

#include <string>
#include "yaml-cpp/yaml.h"

class ClientSettings {
public:
	explicit ClientSettings();

    // Controla dónde buscar los archivos de imágenes y sonidos
    std::string ASSET_DIR_PREFIX;

    // Controla el tamaño del mundo que se ve
	double PIXEL_PER_METER = 80;

    // Controla el tamaño inicial de la ventana
    size_t INITIAL_SCREEN_WIDTH = 640;
    size_t INITIAL_SCREEN_HEIGHT = 480;
};

#endif  // CLIENT_SETTINGS_H
