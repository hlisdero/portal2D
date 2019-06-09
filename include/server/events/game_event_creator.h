#ifndef GAME_EVENT_CREATOR_H
#define GAME_EVENT_CREATOR_H

#include "common/queue/safe_queue.h"
#include "server/events/game_event.h"
#include "server/entities/entity.h"

class GameEventCreator {
public:
	GameEventCreator(SafeQueue<GameEvent>& queue);

	void addStateUpdate(Entity* entity);
	void addSetActiveEntity(Entity * entity, bool active);

private:
	SafeQueue<GameEvent>& queue;
};

#endif
