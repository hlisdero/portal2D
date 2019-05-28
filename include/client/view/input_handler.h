#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include "client/event/keyboard_handler.h"
#include "common/queue/blocking_queue.h"
#include "common/view_event.h"
#include "common/move_direction.h"

class InputHandler : public KeyboardHandler {
public:
    explicit InputHandler(BlockingQueue& queue);

    virtual void handle(const KeyboardEvent& event) override;

private:
    BlockingQueue& queue;

    MoveDirection processMoveDirection(const KeyboardEvent& event);
};

#endif  // INPUT_HANDLER_H
