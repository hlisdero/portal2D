#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include <vector>

#include "server/physics_scene.h"
#include "common/entity.h"

// Temporary class to simulate the separation between client y server.
class ServerInterface {
public:
	// Constructor:
	// - create the scene
	ServerInterface();

	void addPlayer();
	void updatePhysics();

	std::vector<Entity> getStaticEntities();
	std::vector<Entity> getDynamicEntities();

private:
	PhysicsScene scene;
};

#endif  // SERVER_INTERFACE_H