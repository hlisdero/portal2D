#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include <vector>

#include "server/game.h"
#include "common/entities/entity.h"
#include "common/move_direction.h"
#include "server/entities/player.h"

// Temporary class to simulate the separation between client y server.
class ServerInterface {
public:
	// Constructor:
	// - create the scene
	ServerInterface(const char * mapName);

	void update();

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> getDynamicEntities() const;

	void movePlayer(const MoveDirection direction, const bool pressed);
	void createPortal(b2Vec2 & direction, PortalColor color);

private:
	MapLoader mapLoader;
	Game game;
	PlayerEntity player;
};

#endif  // SERVER_INTERFACE_H
