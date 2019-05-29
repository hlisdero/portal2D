#include "server/entities/end_barrier.h"

EndBarrierEntity::EndBarrierEntity(YAML::Node yaml, EndZone & endZone) : Entity(TYPE_END_BARRIER, yaml), endZone(endZone) {}

void EndBarrierEntity::handleContactWith(Entity * entity, b2Contact * contact, bool inContact) {

	if(entity->getType() == TYPE_PLAYER) {
		PlayerEntity * player = entity->as<PlayerEntity>();

		if(inContact) {
			this->contacts[player] = contact->GetManifold()->localNormal;
		} else {
			auto iterator = this->contacts.find(player);

			if(iterator != this->contacts.end()) {
				if(iterator->second == 
					-1 * contact->GetManifold()->localNormal) {
					// Player went through
					endZone.playerWentTroughBarrier(player);
				} else {
					// Player went the other way
					this->contacts.erase(iterator);
				}
			}
		}
	}
}