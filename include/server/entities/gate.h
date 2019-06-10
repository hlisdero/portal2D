#ifndef GATE_ENTITY_H
#define GATE_ENTITY_H

#include <Box2D/Box2D.h>

class GateEntity;

#include "server/entities/entity.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/with_state.h"
#include "server/entities/attributes/with_subscribable_state.h"

typedef std::map<std::string, WithSubscribableState*> subscribablesMap;

#include "server/entities/utils/gate_logica.h"

class GateEntity : public Entity, public BodyLinked, public WithState {
public:
    GateEntity(float x, float y, float rotation, GateLogicaPtr logica, GameEventCreator& gameEventCreator);

	void updateState();

	virtual void attachBody(b2Body * body) override;

	void attach(subscribablesMap & subscribables);

private:
	GateLogicaPtr logica;
	GameEventCreator & gameEventCreator;
};

#endif  // GATE_ENTITY_H
