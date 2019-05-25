#include "client/texture/color.h"
#include <map>

static const std::map<std::string, std::array<uint8_t,4> > color_map = {
    {"white", {0xFF, 0xFF, 0xFF, 0xFF} },
    {"black", {0x00, 0x00, 0x00, 0xFF} },
    {"red", {0xFF, 0x00, 0x00, 0xFF} },
    {"green", {0x00, 0xFF, 0x00, 0xFF} },
    {"blue", {0x00, 0x00, 0xFF, 0xFF} },
    {"yellow", {0xFF, 0xFF, 0x00, 0xFF} },
    {"cyan", {0x00, 0xFF, 0xFF, 0xFF} },
    {"magenta", {0xFF, 0x00, 0xFF, 0xFF} },
};

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
    r(red), g(green), b(blue), a(alpha) {}

Color::Color(const std::string& color_name) {
    r = color_map.at(color_name)[0];
    g = color_map.at(color_name)[1];
    b = color_map.at(color_name)[2];
    a = color_map.at(color_name)[3];
}
