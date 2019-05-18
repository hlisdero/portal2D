#include <iostream>
#include <chrono>

#include "server/server_interface.h"
#include "client2/client_interface.h"

#include "common/clock_loop.h"

int main() {
	ServerInterface server;
	ClientInterface client;

	// create personnage
	server.addPlayer(); // TODO server-side: link client and player

	// create snapshot world with statics objects
	auto staticEntities = server.getStaticEntities();
	auto initialDynamicEntities = server.getDynamicEntities();
	client.setEntities(staticEntities, initialDynamicEntities);

	ClockLoop<60> clock;
	// while(...)
	for(uint i = 0; i < 1*60; i++) { // TODO replace by while

		// TODO draw
		// TODO listen input

		// TODO apply input to physic world
		server.updatePhysics();

		// TODO get change to snapshot world
		// ... = serverScene.getChanges();
		// clientScene.setChanges(...)
		auto dynamicEntities = server.getDynamicEntities();
		client.setDynamicEntities(dynamicEntities);

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}