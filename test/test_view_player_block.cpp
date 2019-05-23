#include "catch.hpp"
#include "client/view/world_view.h"
#include "client/event/event_handler.h"

TEST_CASE("Player and Block Test", "[view]") {
    WorldView view(13.33, 10);
    EventHandler event_handler;

    view.createPlayer(Position(1, 0.5));
    view.createBlock(Position(3, 0.5));

    while (!event_handler.quit()) {
        event_handler.poll();

        view.update();
    }
}
