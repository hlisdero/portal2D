#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include <vector>

#include "server/world.h"
#include "server/map.h"
#include "common/entities/entity.h"
#include "common/move_direction.h"
#include "server/entities/player.h"

// Temporary class to simulate the separation between client y server.
class ServerInterface {
public:
	// Constructor:
	// - create the scene
	ServerInterface();

	void updatePhysics();

	std::vector<Entity*> getStaticEntities() const;
	std::vector<Entity> getDynamicEntities() const;

	void movePlayer(const MoveDirection direction, const bool pressed);

private:
	Map map;
	World world;
	PlayerEntity player;
};

#endif  // SERVER_INTERFACE_H
