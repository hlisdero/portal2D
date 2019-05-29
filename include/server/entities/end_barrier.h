#ifndef END_BARRIER_ENTITY_H
#define END_BARRIER_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/body_linked.h"
#include "server/entities/handle_contact.h"
#include "server/entities/player.h"

class EndBarrierEntity :  public Entity, public BodyLinked, public HandleContact {
public:
	EndBarrierEntity(YAML::Node yaml);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

private:	
	std::map<PlayerEntity*, b2Vec2> contacts;
};

#endif  // END_BARRIER_ENTITY_H
