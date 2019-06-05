#include <iostream>
#include <chrono>

#include "client/client.h"
#include "common/clock_loop.h"
#include "common/events/view_event.h"
#include "server/server_interface.h"
#include "server/entities/attributes/with_state.h"
#include "common/events/world/dynamics_update.h"

int main(int argc, char const *argv[]) {
    // World size in meter 53.32 x 40
    Client client(53.32, 40);
    const char * mapName = "../data/maps/map3.yaml";
    if(argc > 1) {
    	mapName = argv[1];
    }
	ServerInterface server(mapName);

	client.view.createEntities(server.getStaticEntities());
	client.view.createEntities(server.getDynamicEntities());

    BlockingQueue<ViewEvent>& queue = client.getQueue();
    BlockingQueue<WorldEventPtr> & worldQueue = server.getQueue();

    bool color = false;

	ClockLoop<60> clock;
	while (!client.quit()) {
        client.pollEvents();
        while (!queue.empty()) {
            ViewEvent event = queue.pop();
            if (event.type == KEYBOARD) {
                server.movePlayer(event.direction, event.pressed);
            } else if (event.type == MOUSE) {
                color = !color;
                server.createPortal(event.click_direction, color ? COLOR_BLUE: COLOR_ORANGE);
            }
        }
		server.update();

        while (!worldQueue.empty()) {
            WorldEventPtr event = worldQueue.pop();
            if(event->getType() == DYNAMICS_UPDATE) {
                DynamicsUpdateEvent* ev = static_cast<DynamicsUpdateEvent*>(event.get());
                client.view.updatePosition(ev->getUpdates());
            } else if(event->getType() == PORTAL_CREATION) {
                // TODO
            } else if(event->getType() == PORTAL_MOVE) {
                // TODO
            }
        }
        
        client.view.update();

		// wait t1
		clock.waitNextLoop();
	}

	return 0;
}
