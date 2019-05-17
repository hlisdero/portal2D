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
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    size_t b_width = 300;
    size_t b_height = 200;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Sprite sprite1(textureCreator("../data/button.png"));
    sprite1.addClip(0, 0, 300, 200);
    sprite1.addClip(0, 200, 300, 200);
    sprite1.addClip(0, 400, 300, 200);
    sprite1.addClip(0, 600, 300, 200);
    Button button1(std::move(sprite1), 0, 0);

    Sprite sprite2(textureCreator("../data/button.png"));
    sprite2.addClip(0, 0, 300, 200);
    sprite2.addClip(0, 200, 300, 200);
    sprite2.addClip(0, 400, 300, 200);
    sprite2.addClip(0, 600, 300, 200);
    Button button2(std::move(sprite2), width - b_width, 0);

    Sprite sprite3(textureCreator("../data/button.png"));
    sprite3.addClip(0, 0, 300, 200);
    sprite3.addClip(0, 200, 300, 200);
    sprite3.addClip(0, 400, 300, 200);
    sprite3.addClip(0, 600, 300, 200);
    Button button3(std::move(sprite3), 0, height - b_height);

    Sprite sprite4(textureCreator("../data/button.png"));
    sprite4.addClip(0, 0, 300, 200);
    sprite4.addClip(0, 200, 300, 200);
    sprite4.addClip(0, 400, 300, 200);
    sprite4.addClip(0, 600, 300, 200);
    Button button4(std::move(sprite4), width - b_width, height - b_height);

    EventHandler event_handler;
    event_handler.add(&button1);
    event_handler.add(&button2);
    event_handler.add(&button3);
    event_handler.add(&button4);

    while (event_handler) {
        event_handler.poll();

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(button1);
        screen.render(button2);
        screen.render(button3);
        screen.render(button4);
        screen.update();
    }
}

void Client::runWindow2() {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    const TextureCreator& textureCreator = screen.getTextureCreator();
    Sprite sprite1(textureCreator("../data/press.png"));
    Sprite sprite2(textureCreator("../data/up.png"));
    Sprite sprite3(textureCreator("../data/left.png"));
    Sprite sprite4(textureCreator("../data/down.png"));
    Sprite sprite5(textureCreator("../data/right.png"));
    std::vector<Sprite*> sprites = {
        &sprite1, &sprite2, &sprite3, &sprite4, &sprite5,
    };
    for (auto &sprite : sprites) {
        sprite->addClip(0,0, width, height);
    }
    KeyboardTest keyboard_test(0, 0, sprites);

    EventHandler event_handler;
    event_handler.add(&keyboard_test);

    while (event_handler) {
        event_handler.poll();

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(keyboard_test);
        screen.update();
    }
}
