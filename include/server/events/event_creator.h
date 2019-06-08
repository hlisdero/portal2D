#ifndef EVENT_CREATOR_H
#define EVENT_CREATOR_H

#include "server/entities/entity.h"
#include "common/events/world_event.h"
#include "common/queue/blocking_queue.h"
#include "server/entities/portal.h"
#include "server/entities/button.h"

class EventCreator {
public:
	EventCreator(BlockingQueue<WorldEvent>& queue);

    void addEntityCreation(Entity* entity);
    void addPositionUpdate(Entity* entity);
    void addButtonStateUpdate(ButtonEntity* entity);
    void addDoorStateUpdate(DoorEntity* entity);

    // Métodos para vectores
    void addEntityCreations(const std::vector<Entity*>& entities);
    void addPositionUpdates(const std::vector<Entity*>& entities);

private:
	BlockingQueue<WorldEvent>& queue;
};

#endif
