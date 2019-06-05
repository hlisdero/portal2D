#ifndef EVENT_CREATOR_H
#define EVENT_CREATOR_H

#include <vector>

#include "common/entities/entity.h"
#include "common/events/world_event.h"
#include "common/queue/blocking_queue.h"
#include "server/entities/portal.h"

class EventCreator {
public:
	EventCreator(BlockingQueue<WorldEventPtr> & eventQueue);

	void sendDynamicsUpdate(const std::vector<Entity*> entities);

	void sendPortalCreation(PortalEntity * portal);
	void sendPortalMove(PortalEntity * portal);

private:
	BlockingQueue<WorldEventPtr> & eventQueue;
};

#endif