#ifndef DOOR_ENTITY_H
#define DOOR_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/with_state.h"

class DoorEntity;

#include "server/door_logica.h"

class DoorEntity : public Entity, public WithState {
public:
	DoorEntity(const float x, const float y, const float angle, DoorLogica * logica);
	DoorEntity(YAML::Node yaml);

	void updateState();
private:
	DoorLogica * logica;
};

#endif  // DOOR_ENTITY_H
