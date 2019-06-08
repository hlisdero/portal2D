#ifndef ENERGY_RECEIVER_ENTITY_H
#define ENERGY_RECEIVER_ENTITY_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/attributes/handle_contact.h"
#include "server/entities/attributes/with_subscribable_state.h"

class EnergyReceiverEntity : public Entity, public WithSubscribableState, public HandleContact {
public:
    EnergyReceiverEntity(float x, float y, float rotation);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;
};

#endif  // ENERGY_RECEIVER_ENTITY_H
