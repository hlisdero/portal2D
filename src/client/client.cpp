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
    runWindow3();
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
    Sprite dots(textureCreator("../data/dots.png", Color("cyan")));
    dots.addClip(0, 0, 100, 100);
    dots.addClip(100, 0, 100, 100);
    dots.addClip(0, 100, 100, 100);
    dots.addClip(100, 100, 100, 100);

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

        screen.setRenderDrawColor("white");
        screen.clear();

        screen.render(dots, 0, 0);
        screen.render(dots, width - dots.getWidth(), 0);
        screen.render(dots, 0, height - dots.getHeight());
        screen.render(dots, width - dots.getWidth(), height - dots.getHeight());

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

void Client::runWindow3() {
    bool quit = false;
    SDL_Event e;

    Screen screen;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture background = textureCreator("../data/background.png");
    Texture character = textureCreator("../data/foo.png", Color("cyan"));

    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }

        screen.clear();
        screen.render(background);
        screen.render(character, 240, 190);
        screen.update();
    }
}
