#ifndef BUTTON_ENTITY_H
#define BUTTON_ENTITY_H

#include <vector>
#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/with_subscribable_state.h"
#include "server/entities/handle_contact.h"

class ButtonEntity : public Entity, public WithSubscribableState, public HandleContact {
public:
	ButtonEntity(const float x, const float y);
	ButtonEntity(YAML::Node yaml);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;
};

#endif  // BUTTON_ENTITY_H
