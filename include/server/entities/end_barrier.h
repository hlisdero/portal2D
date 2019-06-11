#ifndef END_BARRIER_ENTITY_H
#define END_BARRIER_ENTITY_H

#include <map>

#include "server/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/attributes/body_linked.h"
#include "server/entities/attributes/handle_contact.h"
#include "server/physics/end_zone.h"

enum EndBarrierSide {
	SIDE_A = 0,
	SIDE_B
};

class EndBarrierEntity :  public Entity, public HandleContact {
public:
	EndBarrierEntity(float x, float y, float rotation, EndZone & endZone);

	virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) override;

private:
	EndZone & endZone;
	std::map<PlayerEntity*, EndBarrierSide> contacts;

	EndBarrierSide getSide(b2Vec2 position);
};

#endif  // END_BARRIER_ENTITY_H
