#include "catch.hpp"
#include "client/screen/screen.h"
#include "client/texture/sprite.h"
#include "client/event/event_handler.h"
#include "key_detector.h"

TEST_CASE("Keyboard Integration Test", "[modules][keyboard]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture press = textureCreator("../test/data/press.png");
    Texture up = textureCreator("../test/data/up.png");
    Texture left = textureCreator("../test/data/left.png");
    Texture down = textureCreator("../test/data/down.png");
    Texture right = textureCreator("../test/data/right.png");

    Sprite sprite1(press);
    Sprite sprite2(up);
    Sprite sprite3(left);
    Sprite sprite4(down);
    Sprite sprite5(right);
    std::vector<Sprite*> sprites = {
        &sprite1, &sprite2, &sprite3, &sprite4, &sprite5,
    };
    for (auto &sprite : sprites) {
        sprite->addClip(0,0, width, height);
    }
    KeyDetector key_detector(0, 0, sprites);

    EventHandler event_handler;
    event_handler.add(&key_detector);

    while (!event_handler.quit()) {
        event_handler.poll();

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(key_detector);
        screen.update();
    }
}
