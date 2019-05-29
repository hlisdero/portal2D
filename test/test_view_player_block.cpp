#include "catch.hpp"
#include "client/view/world_view.h"
#include "client/event/event_handler.h"

#include <thread>
#include <chrono>

TEST_CASE("Player and Block Test", "[view]") {
    WorldView view(13.33, 10);
    EventHandler event_handler;

    size_t player = view.createPlayer(Position(1, 3));
    size_t block = view.createMetalBlock(Position(3, 3));

    while (!event_handler.quit()) {
        event_handler.poll();

        view.update();
    }
    view.updatePosition(player, Position(5, 3));
    view.updatePosition(block, Position(10, 3));
    view.update();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
