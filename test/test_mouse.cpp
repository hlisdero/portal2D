#include "catch.hpp"
#include "client/screen/screen.h"
#include "client/texture/sprite.h"
#include "client/event/event_handler.h"
#include "test_button.h"

TEST_CASE("Mouse Integration Test", "[modules][mouse]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    size_t b_width = 300;
    size_t b_height = 200;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture texture = textureCreator("../test/data/button.png");
    TestButton button1(texture, 0, 0);
    TestButton button2(texture, width - b_width, 0);
    TestButton button3(texture, 0, height - b_height);
    TestButton button4(texture, width - b_width, height - b_height);

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
