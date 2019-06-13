#ifndef BUTTON_ENTITY_H
#define BUTTON_ENTITY_H

#include <unordered_set>
#include "Box2D/Box2D.h"

#include "server/entities/entity.h"
#include "server/entities/attributes/with_subscribable_state.h"
#include "server/entities/attributes/handle_contact.h"

class ButtonEntity : public Entity, public WithSubscribableState, public HandleContact {
public:
	ButtonEntity(float x, float y, float rotation, GameEventCreator& gameEventCreator);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

private:
	std::unordered_set<b2Contact*> contacts;
};

#endif  // BUTTON_ENTITY_H
