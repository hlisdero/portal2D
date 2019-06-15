#include "client/view/main_player.h"

MainPlayer::MainPlayer(size_t index, Player& player,
                       const Camera& camera, BlockingQueue<ViewEvent>& queue) :
    index(index), player(player), camera(camera), queue(queue) {}

void MainPlayer::handle(const KeyboardEvent& event) {
    MoveDirection direction = processMoveDirection(event);

    if (direction != NONE) {
        queue.push(ViewEvent(index, direction, event.pressed, event.repeat));
    } else if(event.pressed) {
        if(event.key == SDLK_r) {
        queue.push(ViewEvent(index, RESET_PORTALS));
        } else if(event.key == SDLK_e) {
            queue.push(ViewEvent(index, GRAB_RELEASE_ROCK));
        }
    }
}

size_t MainPlayer::getIndex() const {
    return index;
}

void MainPlayer::handle(const MouseEvent& event) {
    if (!event.pressed || event.motion ||
         event.x == 0 || event.y == 0) {
        return;
    }

    if(event.button != SDL_BUTTON_LEFT && 
        event.button != SDL_BUTTON_RIGHT &&
        event.button != SDL_BUTTON_MIDDLE) {
        return;
    }

    int player_x = player.getX() + player.getWidth()/2 - camera.position.x;
    int player_y = player.getY() + player.getHeight()/2 - camera.position.y;

    // Calculo un vector de norma 1 con la dirección desde el jugador hacia el clic
    double x = event.x - player_x;
    double y = event.y - player_y;
    ClickDirection click_direction(x/sqrt(x*x + y*y), -y/sqrt(x*x + y*y));

    if(event.button == SDL_BUTTON_MIDDLE) {
        queue.push(ViewEvent(index, click_direction));
    } else {
        PortalColor color = 
            (event.button == SDL_BUTTON_LEFT) ? COLOR_BLUE : COLOR_ORANGE;
        queue.push(ViewEvent(index, click_direction, color));
    }
}

void MainPlayer::startDeathAnimation() {
    player.startDeathAnimation();
}

bool MainPlayer::finishedDeathAnimation() const {
    return player.finishedDeathAnimation();
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
