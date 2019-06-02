#include <iostream>
#include <chrono>

#include "client/client.h"
#include "server/server_interface.h"
#include "common/clock_loop.h"
#include "common/view_event.h"
#include "server/entities/with_state.h"

int main(int argc, char const *argv[]) {
    // World size in meter 53.32 x 40
    // World size in pixels 1920 x 1080
    Client client(53.32, 40, 1920, 1080);
    const char * mapName = "../data/maps/map3.yaml";
    if(argc > 1) {
    	mapName = argv[1];
    }
	ServerInterface server(mapName);

	client.view.createEntities(server.getStaticEntities());
	client.view.createEntities(server.getDynamicEntities());

	ClockLoop<60> clock;
	while (!client.quit()) {
        client.pollEvents();
        BlockingQueue& queue = client.getQueue();
        while (!queue.empty()) {
            ViewEvent event = queue.pop();
            if (event.type == KEYBOARD) {
                server.movePlayer(event.direction, event.pressed);
            } else if (event.type == MOUSE) {
                server.createPortal(event.click_direction, COLOR_BLUE);
            }
        }
		server.update();

        client.view.updatePosition(server.getDynamicEntities());
        client.view.update();

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}
