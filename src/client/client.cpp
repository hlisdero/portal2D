#include "client/client.h"

Client::Client(float32 world_width, float32 world_height,
               size_t level_width, size_t level_height) :
    view(world_width, world_height, level_width, level_height) {
}

void Client::pollEvents() {
    view.pollEvents();
}

BlockingQueue& Client::getQueue() {
    return view.getQueue();
}

bool Client::quit() const {
    return view.quit();
}
