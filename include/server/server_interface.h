#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include "server/scene.h"

// Temporary class to simulate the separation between client y server.
class ServerInterface {
public:
	// Constructor:
	// - create the scene
	ServerInterface();

	void addPlayer();
	void updatePhysics();

private:
	Scene scene;
};

#endif  // SERVER_INTERFACE_H