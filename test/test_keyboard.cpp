#include "catch.hpp"
#include "screen.h"
#include "sprite.h"
#include "event_handler.h"
#include "key_detector.h"

TEST_CASE("Keyboard Integration Test", "[integration]") {
    Screen screen;
    size_t width = screen.getWidth();
    size_t height = screen.getHeight();

    const TextureCreator& textureCreator = screen.getTextureCreator();
    Sprite sprite1(textureCreator("../test/data/press.png"));
    Sprite sprite2(textureCreator("../test/data/up.png"));
    Sprite sprite3(textureCreator("../test/data/left.png"));
    Sprite sprite4(textureCreator("../test/data/down.png"));
    Sprite sprite5(textureCreator("../test/data/right.png"));
    std::vector<Sprite*> sprites = {
        &sprite1, &sprite2, &sprite3, &sprite4, &sprite5,
    };
    for (auto &sprite : sprites) {
        sprite->addClip(0,0, width, height);
    }
    KeyDetector key_detector(0, 0, sprites);

    EventHandler event_handler;
    event_handler.add(&key_detector);

    while (event_handler) {
        event_handler.poll();

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(key_detector);
        screen.update();
    }
}
