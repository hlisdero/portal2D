#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "client/view/color.h"

class Surface {
public:
    explicit Surface(const std::string& path);
    Surface(const std::string& path, const Color& color_key);

    Surface(const Surface&) = delete;
    Surface& operator=(const Surface&) = delete;
    Surface(Surface&& other) = delete;
    Surface& operator=(Surface&& other) = delete;

    ~Surface();

    void setColorKey(const Color& color_key);

    SDL_Surface* get() const;
    int getWidth() const;
    int getHeight() const;

private:
    SDL_Surface* surface;
    int width;
    int height;
};

#endif  // SURFACE_H
