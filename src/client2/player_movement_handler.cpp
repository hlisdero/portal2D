#include "client2/player_movement_handler.h"
#include "common/move_direction.h"

PlayerMovementHandler::PlayerMovementHandler(ServerInterface & server) :
    server(server) {}

void PlayerMovementHandler::handle(const KeyboardEvent& event) {
	MoveDirection direction = NONE;
	switch(event.key) {
		case 'w':
			direction = UP;
		break;
		case 'a':
			direction = LEFT;
		break;
		case 'd':
			direction = RIGHT;
		break;
	}

	if(direction != NONE) {
		this->server.movePlayer(direction, event.pressed);
	}
}
