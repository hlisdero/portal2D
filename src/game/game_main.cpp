#include <iostream>
#include <chrono>

#include "server/server_interface.h"
#include "client2/client_interface.h"
#include "client2/player_movement_handler.h"

#include "common/clock_loop.h"

int main() {
	ServerInterface server;
	ClientInterface client;

	PlayerMovementHandler moveHandler(server);
	client.addHandler(&moveHandler);

	// create drawable world with statics objects
	auto staticEntities = server.getStaticEntities();
	auto initialDynamicEntities = server.getDynamicEntities();
	client.setEntities(staticEntities, initialDynamicEntities);

	ClockLoop<60> clock;
	while(!client.doQuit()) {
		// get keyboard/mouse input
		client.poolEvent();
		// TODO client - send input keyUp, keyDown; mouseClicks
		// TODO server - receive/apply input to physic world


		server.updatePhysics();

		// update drawable world
		auto dynamicEntities = server.getDynamicEntities();
		client.setDynamicEntities(dynamicEntities);

		// draw screen
		client.renderScreen();
		client.updateScreen();

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}