#include "server/entities/end_barrier.h"

EndBarrierEntity::EndBarrierEntity(float x, float y, float rotation, EndZone & endZone) :
    Entity(TYPE_END_BARRIER, x, y, rotation), endZone(endZone) {}

EndBarrierSide EndBarrierEntity::getSide(b2Vec2 position) {
	float delta;
	if(getRotationDeg() == 0) {
		delta = position.x - getX();
	} else if(getRotationDeg() == 90) {
		delta = position.y - getY();
	} else {
		throw std::runtime_error("Unsupported end barrier orientation");
	}

	return delta > 0 ? SIDE_A : SIDE_B;
}

void EndBarrierEntity::handleContactWith(Entity * entity, b2Contact *, bool newContact) {

	if(entity->getType() == TYPE_PLAYER) {
		PlayerEntity * player = entity->as<PlayerEntity>();

		if(newContact) {
			this->contacts[player] = getSide(player->getBody()->GetPosition());
		} else {
			auto iterator = this->contacts.find(player);

			if(iterator != this->contacts.end()) {
				EndBarrierSide newSide = getSide(player->getBody()->GetPosition());

				// If: Player went through (newSide != oldSide)
				if(newSide != iterator->second) {
					endZone.playerWentTroughBarrier(player);
				}
				// Else: Player went the other way

				this->contacts.erase(iterator);
			}
		}
	}
}
