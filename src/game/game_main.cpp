#include <iostream>
#include <chrono>

#include "server/server_interface.h"

#include "common/clock_loop.h"

int main() {
	ServerInterface server;

	// create drawable world with statics objects
	auto staticEntities = server.getStaticEntities();
	auto initialDynamicEntities = server.getDynamicEntities();
	ClockLoop<60> clock;
	while(true) {
		// get keyboard/mouse input
		// TODO client - send input keyUp, keyDown; mouseClicks
		// TODO server - receive/apply input to physic world


		server.updatePhysics();

		// update drawable world
		auto dynamicEntities = server.getDynamicEntities();

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}
