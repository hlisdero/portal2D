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
    Sprite dots(textureCreator("../data/animation.png", Color("cyan")));
    dots.addClip(0, 0, 64, 205);
    dots.addClip(64, 0, 64, 205);
    dots.addClip(128, 0, 64, 205);
    dots.addClip(196, 0, 64, 205);

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

        int frame = 0;
        if (frame++ % 64*8*8 == 0) {
            screen.setRenderDrawColor("white");
            screen.clear();
            screen.render(dots, width/2, height/2);
            screen.update();
        }
        if (frame == 64*8*8*4) {
            frame = 0;
        }

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
