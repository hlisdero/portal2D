#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "common/events/view_event.h"
#include "common/events/world_event.h"
#include "common/entities/entity.h"
#include "common/queue/blocking_queue.h"

#include "server/game.h"
#include "server/entities/player.h"
#include "server/events/event_creator.h"

class Server {
public:
	Server(const char * mapName);

    BlockingQueue<WorldEvent>& getQueue();

	void update();

    void processQueue(BlockingQueue<ViewEvent>& queue);

	void movePlayer(const MoveDirection direction, const bool pressed);
	void createPortal(ClickDirection& direction);

private:
	BlockingQueue<WorldEvent> queue;
	EventCreator eventCreator;
	Game game;
	PlayerEntity player;
};

#endif  // SERVER_H
