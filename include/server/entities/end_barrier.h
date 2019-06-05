#ifndef END_BARRIER_ENTITY_H
#define END_BARRIER_ENTITY_H

#include "common/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/handle_contact.h"
#include "server/physics/end_zone.h"

class EndBarrierEntity :  public Entity, public BodyLinked, public HandleContact {
public:
	EndBarrierEntity(YAML::Node yaml, EndZone & endZone);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

private:	
	EndZone & endZone;
	std::map<PlayerEntity*, b2Vec2> contacts;
};

#endif  // END_BARRIER_ENTITY_H
