#include "catch.hpp"
#include "client/view/world_view.h"
#include "client/event/event_handler.h"

#include <thread>
#include <chrono>

TEST_CASE("Player and Block Test", "[view]") {
    WorldView view(13.33, 10, 1920, 1080);
    EventHandler event_handler;

    size_t player_index = 0;
    size_t block_index = 1;
    const ViewObjectCreator& object_creator = view.getObjectCreator();
    object_creator.createPlayer(player_index, Position(1, 3));
    object_creator.createMetalBlock(block_index, Position(3, 3));

    while (!event_handler.quit()) {
        event_handler.poll();

        view.update();
    }
    view.updatePosition(player_index, Position(5, 3));
    view.updatePosition(block_index, Position(10, 3));
    view.update();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
