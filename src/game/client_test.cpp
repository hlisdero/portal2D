#include "common/protocol/protocol.h"

int main() {
    ActiveSocket skt("localhost", "8080");
    skt.connect();
    Protocol protocol(std::move(skt));
    ViewEvent event;
    event.type = KEYBOARD;
    event.direction = UP;
    event.pressed = true;
    event.repeat = false;
    event.click_direction = ClickDirection(4.0, -2.0);
    protocol.send(event);
    return 0;
}
