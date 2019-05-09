#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Surface {
public:
    explicit Surface(const std::string& path);

    Surface(const Surface&) = delete;
    Surface& operator=(const Surface&) = delete;
    Surface(Surface&& other) = delete;
    Surface& operator=(Surface&& other) = delete;

    ~Surface();

    SDL_Surface* get() const;

private:
    SDL_Surface* surface;
};

#endif  // SURFACE_H
