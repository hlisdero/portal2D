#ifndef CLIENT_INTERFACE_H
#define CLIENT_INTERFACE_H

#include <vector>

#include "client2/drawable_scene.h"
#include "server/entities/m_entity.h"
#include "client2/p_entity.h"
#include "client/event/keyboard_handler.h"

// Temporary class to simulate the separation between client y server.
class ClientInterface {
public:
	ClientInterface();

	void addHandler(KeyboardHandler * handler);

	void setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities);
	void setDynamicEntities(const std::vector<MEntity> dynamicEntities);
	
	void renderScreen();
	void updateScreen();

	void poolEvent();

	bool doQuit();
private:
	DrawableScene scene;

};

#endif  // CLIENT_INTERFACE_H