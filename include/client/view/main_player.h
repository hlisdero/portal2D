#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include <SDL2/SDL.h>
#include "client/event/keyboard_handler.h"
#include "client/event/mouse_handler.h"
#include "client/screen/camera.h"
#include "client/objects/player.h"
#include "common/queue/blocking_queue.h"
#include "common/events/view_event.h"
#include "common/objects/move_direction.h"
#include "common/objects/click_direction.h"

class MainPlayer : public KeyboardHandler, public MouseHandler {
public:
    MainPlayer(size_t index, const Player& player, const Camera& camera, BlockingQueue<ViewEvent>& queue);

    virtual void handle(const KeyboardEvent& event) override;

    virtual void handle(const MouseEvent& event) override;

private:
    size_t index;
    const DrawableBox2D& player;
    const Camera& camera;
    BlockingQueue<ViewEvent>& queue;

    MoveDirection processMoveDirection(const KeyboardEvent& event) const;
};

#endif  // MAIN_PLAYER_H
