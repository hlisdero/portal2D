#include <iostream>
#include <chrono>

#include "server/server_interface.h"
#include "common/clock_loop.h"

int main() {
	ServerInterface server;

	// TODO create personnage
	server.addPlayer();

	// TODO create snapshot world with statics objects



	ClockLoop<60> clock;
	// while(...)
	for(uint i = 0; i < 60*60; i++) { // TODO replace by while

		// TODO draw
		// TODO listen input

		// TODO apply input to physic world
		server.updatePhysics();

		// TODO get change to snapshot world
		// ... = serverScene.getChanges();
		// clientScene.setChanges(...)

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}