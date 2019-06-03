#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include <SDL2/SDL.h>
#include "client/event/keyboard_handler.h"
#include "client/event/mouse_handler.h"
#include "client/screen/camera.h"
#include "client/objects/player.h"
#include "common/queue/blocking_queue.h"
#include "common/view_event.h"
#include "common/move_direction.h"
#include "common/click_direction.h"

class MainPlayer : public KeyboardHandler, public MouseHandler {
public:
    MainPlayer(const Player& player, const Camera& camera, BlockingQueue& queue);

    virtual void handle(const KeyboardEvent& event) override;

    virtual void handle(const MouseEvent& event) override;

private:
    const Player& player;
    const Camera& camera;
    BlockingQueue& queue;

    MoveDirection processMoveDirection(const KeyboardEvent& event) const;
};

#endif  // MAIN_PLAYER_H
