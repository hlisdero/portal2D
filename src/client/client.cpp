#include "client.h"
#include <string>

Client::Client(const std::string& hostname,
               const std::string& port) :
    skt_(hostname, port) {
    // skt_.connect();
}

void Client::run() {
    // greetServer();
    runWindow();
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

void Client::runWindow() {
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

        screen.clear();
        screen.render(texture);
        screen.update();
    }
}
