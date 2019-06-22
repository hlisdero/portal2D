#ifndef EVENT_CREATOR_H
#define EVENT_CREATOR_H

#include <queue>
#include "server/entities/entity.h"
#include "server/entities/portal.h"
#include "common/events/world_event.h"
#include "common/queue/blocking_queue.h"
#include "server/entities/portal.h"
#include "server/entities/button.h"
#include "server/objects/game_status.h"

class EventCreator {
public:
	EventCreator(std::queue<WorldEvent>& queue);

    void addEntityCreation(Entity* entity);
    void addPortalCreation(PortalEntity* entity);
    void addEntityDestruction(Entity* entity);
    void addPositionUpdate(Entity* entity);
    void addStateUpdate(Entity* entity);
    void addEndGame(GameStatus status);

    // Métodos para vectores
    void addEntityCreations(const std::vector<Entity*>& entities);
    void addPositionUpdates(const std::vector<Entity*>& entities);

    void addPinToolCreation(b2Vec2 & position, float rotationDeg);

private:
	std::queue<WorldEvent>& queue;

    State portalColorToState(const PortalColor& color) const;
};

#endif
