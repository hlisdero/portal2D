#include "client/view/main_player.h"

MainPlayer::MainPlayer(size_t index, Player& player,
                       const Camera& camera, BlockingQueue<ViewEvent>& queue) :
    index(index), player(player), camera(camera), queue(queue) {}

void MainPlayer::handle(const KeyboardEvent& event) {
    MoveDirection direction = processMoveDirection(event);

    if (direction != NONE) {
        queue.push(ViewEvent(index, direction, event.pressed, event.repeat));
    } else if (event.pressed) {
        if (event.key == CLIENT_SETTINGS.RESET_PORTALS) {
            queue.push(ViewEvent(index, RESET_PORTALS));
        } else if(event.key == CLIENT_SETTINGS.GRAB_RELEASE_ROCK) {
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

    if (event.button == SDL_BUTTON_MIDDLE) {
        queue.push(ViewEvent(index, click_direction));
    } else {
        queue.push(ViewEvent(index, click_direction, pickPortalColor(event.button)));
    }
}

MoveDirection MainPlayer::processMoveDirection(const KeyboardEvent& event) const {
    MoveDirection direction = NONE;

    if(event.key == CLIENT_SETTINGS.JUMP) {
        direction = UP;
    } else if(event.key == CLIENT_SETTINGS.MOVE_LEFT) {
        direction = LEFT;
    } else if(event.key == CLIENT_SETTINGS.MOVE_RIGHT) {
        direction = RIGHT;
    }

    return direction;
}

State MainPlayer::pickPortalColor(uint8_t button) const {
    if (button == SDL_BUTTON_LEFT) {
        return PORTAL_COLOR_BLUE;
    } else {
        return PORTAL_COLOR_ORANGE;
    }
}
