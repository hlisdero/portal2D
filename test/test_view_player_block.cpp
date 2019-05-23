#include "catch.hpp"
#include "client/view/world_view.h"
#include "client/event/event_handler.h"

#include <thread>
#include <chrono>

TEST_CASE("Player and Block Test", "[view]") {
    WorldView view(13.33, 10);
    EventHandler event_handler;

    size_t player = view.createPlayer(Position(1, 0.5));
    size_t block = view.createBlock(Position(3, 0.5));

    while (!event_handler.quit()) {
        event_handler.poll();

        view.update();
    }
    view.updatePosition(player, Position(4, 0.5));
    view.updatePosition(block, Position(7, 0.5));
    view.update();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
