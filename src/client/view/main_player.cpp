#include "client/view/main_player.h"

MainPlayer::MainPlayer(const Player& player, const Ratio& meter_to_pixel, BlockingQueue& queue) :
    player(player), meter_to_pixel(meter_to_pixel), queue(queue) {}

void MainPlayer::handle(const KeyboardEvent& event) {
    MoveDirection direction = processMoveDirection(event);

    if (direction != NONE) {
        queue.push(ViewEvent(direction, event.pressed, event.repeat));
    }
}

void MainPlayer::handle(const MouseEvent& event) {
    if (!event.pressed || event.motion) {
        return;
    }
    // Transformo el sistema de coordenadas de Box2D al de SDL
    // La posición se mide desde el medio del objeto
    // int x = drawable.getX() - drawable.getWidth()/2;
    // int y = window.height - (drawable.getY() + drawable.getHeight()/2);

    float32 x = event.x / meter_to_pixel.x - player.currentX();
    float32 y = event.y / meter_to_pixel.y - player.currentY();
    x = x/sqrt(x*x + y*y);
    y = y/sqrt(x*x + y*y);
    queue.push(ViewEvent(ClickDirection(x, y)));
}

MoveDirection MainPlayer::processMoveDirection(const KeyboardEvent& event) const {
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
