#ifndef PLAYER_MOVEMENT_HANDLER_H
#define PLAYER_MOVEMENT_HANDLER_H

#include "client/event/keyboard_handler.h"
#include "server/server_interface.h"

class PlayerMovementHandler : public KeyboardHandler {
public:
    explicit PlayerMovementHandler(ServerInterface & server);

    virtual void handle(const KeyboardEvent& event) override;

private:
	ServerInterface & server;
};

#endif  // PLAYER_MOVEMENT_HANDLER_H
