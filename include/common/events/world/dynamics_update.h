#ifndef DYNAMICS_UPDATE_EVENT_H
#define DYNAMICS_UPDATE_EVENT_H

#include <vector>

#include "common/objects/entity_position.h"
#include "common/events/world_event.h"

class DynamicsUpdateEvent : public WorldEvent {
public:
	DynamicsUpdateEvent(std::vector<EntityPosition> entities);

	const std::vector<EntityPosition> & getUpdates() const;
private:
	std::vector<EntityPosition> entities;
};

#endif