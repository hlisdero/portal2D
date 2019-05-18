#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include <vector>

#include "server/physics_scene.h"
#include "common/entity.h"
#include "common/move_direction.h"
#include "server/player_entity.h"

// Temporary class to simulate the separation between client y server.
class ServerInterface {
public:
	// Constructor:
	// - create the scene
	ServerInterface();

	void updatePhysics();

	std::vector<Entity> getStaticEntities();
	std::vector<Entity> getDynamicEntities();

	void movePlayer(MoveDirection direction);

private:
	PhysicsScene scene;
	PlayerEntity player;
};

#endif  // SERVER_INTERFACE_H