#include <iostream>
#include <chrono>

#include "client/client.h"
#include "server/server_interface.h"
#include "common/clock_loop.h"
#include "common/view_event.h"

int main() {
    // World size in meter 53.32 x 40
    // World size in pixels 1920 x 1080
    Client client(53.32, 40, 1920, 1080);
	ServerInterface server;

	client.view.createEntities(server.getStaticEntities());
	client.view.createEntities(server.getDynamicEntities());

	ClockLoop<60> clock;
	while (!client.quit()) {
        client.pollEvents();
        while (!client.queue.empty()) {
            ViewEvent event = client.queue.pop();
            server.movePlayer(event.direction, event.pressed);
        }
		server.update();

        client.view.updatePosition(server.getDynamicEntities());
        client.view.update();

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}
