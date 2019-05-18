#include <iostream>
#include <chrono>

#include "server_scene.hpp"
#include "clock_loop.hpp"

int main() {
	ServerScene serverScene;

	// Create a map con box2d
	serverScene.create();
	// TODO create personnage

	// TODO create snapshot world with statics objects



	ClockLoop<60> clock;
	// while(...)
	for(uint i = 0; i < 60*60; i++) { // TODO replace by while

		// TODO draw
		// TODO listen input

		// TODO apply input to physic world
		serverScene.updatePhysics();

		// TODO get change to snapshot world
		// ... = serverScene.getChanges();
		// clientScene.setChanges(...)

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}