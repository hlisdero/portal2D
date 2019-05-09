#ifndef WINDOW_H
#define WINDOW_H

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window {
public:
    explicit Window(size_t width, size_t height);

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&& other) = delete;
    Window& operator=(Window&& other) = delete;

    ~Window();

    SDL_Window* get() const;

private:
    SDL_Window* window = nullptr;
};

#endif  // WINDOW_H
