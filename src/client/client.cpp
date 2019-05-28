#include "client/client.h"

Client::Client() :
    view(13.33, 10), queue(), event_handler(), input_handler(queue) {
    event_handler.add(&input_handler);
}

void Client::pollEvents() {
    event_handler.poll();
}
