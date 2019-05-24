#ifndef DOOR_ENTITY_H
#define DOOR_ENTITY_H

#include "Box2D/Box2D.h"

#include "server/entities/state_entity.h"

class DoorEntity;

#include "server/door_logica.h"

class DoorEntity : public StateEntity {
public:
	DoorEntity(const float x, const float y, const float angle, DoorLogica & logica);

	void updateState();
private:
	DoorLogica & logica;
};

#endif  // DOOR_ENTITY_H
