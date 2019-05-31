#include "client/client.h"

Client::Client(float32 world_width, float32 world_height,
               size_t level_width, size_t level_height) :
    view(world_width, world_height, level_width, level_height), queue(), event_handler(), input_handler(queue) {
    event_handler.add(&input_handler);
    event_handler.add(&sound_manager);
}

void Client::pollEvents() {
    event_handler.poll();
}

bool Client::quit() const {
    return event_handler.quit();
}
