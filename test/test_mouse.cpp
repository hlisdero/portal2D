#include "catch.hpp"
#include "client/view/screen.h"
#include "client/view/sprite.h"
#include "client/event/event_handler.h"
#include "button.h"

TEST_CASE("Mouse Integration Test", "[integration]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    size_t b_width = 300;
    size_t b_height = 200;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Sprite sprite1(textureCreator("../test/data/button.png"));
    sprite1.addClip(0, 0, 300, 200);
    sprite1.addClip(0, 200, 300, 200);
    sprite1.addClip(0, 400, 300, 200);
    sprite1.addClip(0, 600, 300, 200);
    Button button1(std::move(sprite1), 0, 0);

    Sprite sprite2(textureCreator("../test/data/button.png"));
    sprite2.addClip(0, 0, 300, 200);
    sprite2.addClip(0, 200, 300, 200);
    sprite2.addClip(0, 400, 300, 200);
    sprite2.addClip(0, 600, 300, 200);
    Button button2(std::move(sprite2), width - b_width, 0);

    Sprite sprite3(textureCreator("../test/data/button.png"));
    sprite3.addClip(0, 0, 300, 200);
    sprite3.addClip(0, 200, 300, 200);
    sprite3.addClip(0, 400, 300, 200);
    sprite3.addClip(0, 600, 300, 200);
    Button button3(std::move(sprite3), 0, height - b_height);

    Sprite sprite4(textureCreator("../test/data/button.png"));
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

    while (!event_handler.quit()) {
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
