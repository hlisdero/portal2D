#include "server/entities/end_barrier.h"

EndBarrierEntity::EndBarrierEntity(YAML::Node yaml) : Entity(TYPE_END_BARRIER, yaml) {}

void EndBarrierEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {

	if(other->getType() == TYPE_PLAYER) {
		PlayerEntity * otherPlayer = other->as<PlayerEntity>();
		if(inContact) {
			this->contacts[otherPlayer] = contact->GetManifold()->localNormal;
		} else {
			auto iterator = this->contacts.find(otherPlayer);

			if(iterator != this->contacts.end()) {
				if(iterator->second == 
					-1 * contact->GetManifold()->localNormal) {
					// Player went through
				} else {
					// Player went the other way
					this->contacts.erase(iterator);
				}
			}
		}
	}
}