#include "client/view/main_player.h"

MainPlayer::MainPlayer(const Player& player, const Camera& camera, BlockingQueue& queue, const size_t& screen_height) :
    player(player), camera(camera), queue(queue), screen_height(screen_height) {}

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
    // Transformo el sistema de coordenadas de Box2D al de SDL
    // La posición se mide desde el medio del objeto
    int player_x = player.getX() - camera.position.x;
    int player_y = screen_height - player.getY() - camera.position.y;

    // Calculo un vector de norma 1 con la dirección desde el jugador hacia el clic
    double x = event.x - player_x;
    double y = event.y - player_y;
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
