#ifndef GAME_EVENT_CREATOR_H
#define GAME_EVENT_CREATOR_H

#include "common/queue/safe_queue.h"
#include "server/events/game_event.h"

class GameEventCreator {
public:
	GameEventCreator(SafeQueue<GameEvent>& queue);

private:
	SafeQueue<GameEvent>& queue;
};

#endif
