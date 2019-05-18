#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H

#include <vector>

#include "client2/drawable_scene.h"
#include "common/entity.h"

// Temporary class to simulate the separation between client y server.
class ClientInterface {
public:
	ClientInterface();

	void setEntities(const std::vector<Entity> staticEntities, const std::vector<Entity> dynamicEntities);
	void setDynamicEntities(const std::vector<Entity> dynamicEntities);
private:
	DrawableScene scene;
};

#endif  // CLIENT_INTERFACE_H