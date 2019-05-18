#include "catch.hpp"
#include "screen.h"
#include "event_handler.h"
#include "sound_manager.h"

TEST_CASE("Sound Integration Test", "[integration]") {
    Screen screen;
    const TextureCreator& textureCreator = screen.getTextureCreator();
    Texture prompt = textureCreator("../test/data/prompt.png");
    SoundManager sound_manager;
    sound_manager.addMusic("../test/data/beat.wav");
    sound_manager.addSoundEffect("../test/data/high.wav");
    sound_manager.addSoundEffect("../test/data/medium.wav");
    sound_manager.addSoundEffect("../test/data/low.wav");
    sound_manager.addSoundEffect("../test/data/scratch.wav");

    EventHandler event_handler;
    event_handler.add(&sound_manager);

    while (event_handler) {
        event_handler.poll();

        screen.setRenderDrawColor("white");
        screen.clear();
        screen.render(prompt, 0, 0);
        screen.update();
    }
}
