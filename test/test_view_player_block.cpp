#include "catch.hpp"
#include "client/view/world_view.h"
#include "client/event/event_handler.h"
#include "common/queue/blocking_queue.h"

#include <thread>
#include <chrono>

TEST_CASE("Player and Block Test", "[view]") {
    BlockingQueue<ViewEvent> queue;
    WorldView view(queue);
    EventHandler event_handler;

    size_t player_index = 0;
    size_t block_index = 1;
    const ViewObjectCreator& object_creator = view.getObjectCreator();
    object_creator.createPlayer(player_index, Position(1, 3, 0));
    object_creator.createMetalBlock(block_index, Position(3, 3, 0));

    while (!event_handler.quit()) {
        event_handler.poll();
        view.update();
    }
    view.updatePosition(player_index, Position(5, 3, 0));
    view.updatePosition(block_index, Position(10, 3, 0));
    view.update();
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
