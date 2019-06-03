#include "client/view/main_player.h"

MainPlayer::MainPlayer(const Player& player, const Camera& camera, BlockingQueue& queue) :
    player(player), camera(camera), queue(queue) {}

void MainPlayer::handle(const KeyboardEvent& event) {
    MoveDirection direction = processMoveDirection(event);

    if (direction != NONE) {
        queue.push(ViewEvent(direction, event.pressed, event.repeat));
    }
}

void MainPlayer::handle(const MouseEvent& event) {
    if (!event.pressed || event.motion ||
         event.x == 0 || event.y == 0) {
        return;
    }
    int player_x = player.getX() + player.getWidth()/2 - camera.position.x;
    int player_y = player.getY() + player.getHeight()/2 - camera.position.y;

    // Calculo un vector de norma 1 con la dirección desde el jugador hacia el clic
    double x = event.x - player_x;
    double y = event.y - player_y;
    ClickDirection click_direction(x/sqrt(x*x + y*y), -y/sqrt(x*x + y*y));
    queue.push(ViewEvent(click_direction));
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
