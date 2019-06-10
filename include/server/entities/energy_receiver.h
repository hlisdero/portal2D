#ifndef ENERGY_RECEIVER_ENTITY_H
#define ENERGY_RECEIVER_ENTITY_H

#include "Box2D/Box2D.h"

#include "server/entities/entity.h"
#include "server/entities/attributes/with_subscribable_state.h"

class EnergyReceiverEntity : public Entity, public WithSubscribableState {
public:
    EnergyReceiverEntity(float x, float y, float rotation, GameEventCreator& gameEventCreator);
};

#endif  // ENERGY_RECEIVER_ENTITY_H
