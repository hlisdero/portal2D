#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <string>

class Color {
public:
    Color(uint8_t red, uint8_t green,
                   uint8_t blue, uint8_t alpha = 0);

    explicit Color(const std::string& color_name);

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a = 0;
};

#endif  // COLOR_H
