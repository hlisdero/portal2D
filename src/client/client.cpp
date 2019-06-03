#include "client/client.h"

Client::Client(float32 world_width, float32 world_height) :
    view(world_width, world_height) {
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
