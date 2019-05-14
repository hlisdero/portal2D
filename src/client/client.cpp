#include "client.h"
#include <string>

Client::Client(const std::string& hostname,
               const std::string& port) :
    skt_(hostname, port) {
    // skt_.connect();
}

void Client::run() {
    // greetServer();
    runWindow1();
    runWindow2();
}

void Client::greetServer() {
    std::string message("Hola servidor!");
    skt_ << (uint32_t) 0;
    skt_ << (uint32_t) message.length();
    skt_ << message;

    uint32_t length;
    std::string response;
    skt_ >> length;
    skt_.receive(response, length);

    std::cout << response << std::endl;
}

void Client::runWindow1() {
    bool quit = false;
    SDL_Event e;

    Screen screen;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture texture = textureCreator("../data/texture.png");

    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }

        size_t width = screen.getWidth();
        size_t height = screen.getHeight();

        screen.clear();
        screen.render(texture);

        // Render red filled quad
        screen.setRenderDrawColor(0xFF, 0x00, 0x00, 0xFF);
        screen.drawFillRect(width / 4, height / 4, width / 2, width / 2);
        // Render green outlined quad
        screen.setRenderDrawColor(0x00, 0xFF, 0x00, 0xFF);
        screen.drawRect(width / 6, height / 6, width * 2 / 3, height * 2 / 3);
        // Draw blue horizontal line
        screen.setRenderDrawColor(0x00, 0x00, 0xFF, 0xFF);
        screen.drawLine(0, height / 2, width, height / 2);
        // Draw vertical line of yellow dots
        screen.setRenderDrawColor(0xFF, 0xFF, 0x00, 0xFF);
        for (size_t i = 0; i < height; i += 4 ) {
            screen.drawPoint(width / 2, i);
        }

        screen.update();
    }
}

void Client::runWindow2() {
    bool quit = false;
    SDL_Event e;

    Screen screen;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture texture = textureCreator("../data/viewport.png");

    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }

        size_t width = screen.getWidth();
        size_t height = screen.getHeight();

        screen.clear();

        // Top left corner viewport
        screen.setViewport(0, 0, width / 2, height / 2);
        screen.render(texture);

        // Top right viewport
        screen.setViewport(width / 2, 0, width / 2, height / 2);
        screen.render(texture);


        // Bottom viewport
        screen.setViewport(0, height / 2, width, height / 2);
        screen.render(texture);

        screen.update();
    }
}
