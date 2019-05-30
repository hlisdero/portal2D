#include "client/client.h"

Client::Client() :
    view(13.33, 10), queue(), event_handler(), input_handler(queue) {
    event_handler.add(&input_handler);
    event_handler.add(&sound_manager);   
}

void Client::pollEvents() {
    event_handler.poll();
}

bool Client::quit() const {
    return event_handler.quit();
}
