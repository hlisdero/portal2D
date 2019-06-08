#include "server/entities/end_barrier.h"

EndBarrierEntity::EndBarrierEntity(float x, float y, float rotation, EndZone & endZone) :
    Entity(TYPE_END_BARRIER, x, y, rotation), endZone(endZone) {}

void EndBarrierEntity::handleContactWith(Entity * entity, b2Contact * contact, bool inContact) {

	if(entity->getType() == TYPE_PLAYER) {
		PlayerEntity * player = entity->as<PlayerEntity>();

		b2WorldManifold manifold;
		contact->GetWorldManifold(&manifold);

		if(inContact) {
			this->contacts[player] = manifold.normal;
		} else {
			auto iterator = this->contacts.find(player);

			if(iterator != this->contacts.end()) {
				if(iterator->second ==
					-1 * manifold.normal) {
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
