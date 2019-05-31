#ifndef DOOR_ENTITY_H
#define DOOR_ENTITY_H

#include "Box2D/Box2D.h"

class DoorEntity;

#include "common/entities/entity.h"
#include "server/entities/with_state.h"
#include "server/entities/body_linked.h"

#include "server/entities/with_subscribable_state.h"

typedef std::map<std::string, WithSubscribableState*> subscribablesMap;

#include "server/door_logica.h"

class DoorEntity : public Entity, public BodyLinked, public WithState {
public:
	DoorEntity(const float x, const float y, const float angle, DoorLogica * logica);
	DoorEntity(YAML::Node yaml);

	void updateState();

	virtual void attachBody(b2Body * body) override;

	void attach(subscribablesMap & subscribables);
private:
	DoorLogicaPtr logica;
};

#endif  // DOOR_ENTITY_H
