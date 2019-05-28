#include "client/view/input_handler.h"

InputHandler::InputHandler(BlockingQueue& queue) : queue(queue) {}

void InputHandler::handle(const KeyboardEvent& event) {
    MoveDirection direction = processMoveDirection(event);

    if (direction != NONE) {
        queue.push(ViewEvent(direction, event.pressed, event.repeat));
    }
}

MoveDirection InputHandler::processMoveDirection(const KeyboardEvent& event) {
    MoveDirection direction = NONE;
    switch (event.key) {
        case SDLK_w:
            direction = UP;
            break;
        case SDLK_a:
            direction = LEFT;
            break;
        case SDLK_d:
            direction = RIGHT;
            break;
    }
    return direction;
}
