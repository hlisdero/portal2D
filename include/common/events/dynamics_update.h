#ifndef DYNAMICS_UPDATE_EVENT_H
#define DYNAMICS_UPDATE_EVENT_H

#include <vector>

#include "common/events/world_event.h"
#include "common/events/entity_position.h"

class DynamicsUpdateEvent : public WorldEvent {
public:
	DynamicsUpdateEvent(std::vector<EntityPosition> entities);

	const std::vector<EntityPosition> & getUpdates() const;
private:
	std::vector<EntityPosition> entities;
};

#endif