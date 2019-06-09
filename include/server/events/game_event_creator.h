#ifndef GAME_EVENT_CREATOR_H
#define GAME_EVENT_CREATOR_H

#include "common/queue/safe_queue.h"
#include "server/events/game_event.h"
#include "server/entities/entity.h"

class GameEventCreator {
public:
	GameEventCreator(SafeQueue<GameEvent>& queue);

	void addUpdateStateEvent(Entity* entity, const State state);

private:
	SafeQueue<GameEvent>& queue;
};

#endif
