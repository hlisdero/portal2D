#include <iostream>
#include <chrono>

#include <stdexcept>
#include "client/client.h"
#include "common/clock_loop.h"
#include "common/events/view_event.h"
#include "common/events/world_event.h"
#include "server/server.h"
#include "server/entities/attributes/with_state.h"

int main(int argc, char *argv[]) {
    // World size in meter 53.32 x 40
    Client client(53.32, 40);
    const char * mapName = "../data/maps/map3.yaml";
    if (argc > 1) {
    	mapName = argv[1];
    }
	Server server(mapName);
    client.createInitialView(server.getQueue());

	ClockLoop<60> clock;
	while (!client.quit()) {
        client.pollEvents();
        server.processQueue(client.getQueue());

		server.update();

        client.processQueue(server.getQueue());

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}
