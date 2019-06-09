#include "server/entities/attributes/teleportable_entity.h"

TeleportableEntity::TeleportableEntity(EntityType type, float x, float y, 
	float rotation, GameEventCreator & gameEventCreator) : 
	Entity(type, x, y, rotation), gameEventCreator(gameEventCreator) {}

void TeleportableEntity::handleContactWith(Entity * other, b2Contact *, bool inContact) {
	if(other->getType() != TYPE_PORTAL) {
		return;
	}

	if(inContact) {
		goThroughPortal(other->as<PortalEntity>());
	} else if(isGoingThroughPortal()) {
		goingTroughPortal--;	
	}
}

bool TeleportableEntity::isGoingThroughPortal() {
	return goingTroughPortal > 0;
}

void TeleportableEntity::goThroughPortal(PortalEntity * inPortal) {
	// Do not go through the portal if already going through the portal
	if(isGoingThroughPortal()) {
		return;
	}

	PortalEntity * outPortal = inPortal->getTwin();

	if(outPortal != nullptr) {
		float rotation =  outPortal->getRotationRad() - (PI + inPortal->getRotationRad());
		const b2Vec2 & inVelocity = getBody()->GetLinearVelocity();

		// Apply rotation to velocity
		b2Vec2 outVelocity(
			inVelocity.x * cos(rotation) - inVelocity.y * sin(rotation),
			inVelocity.x * sin(rotation) + inVelocity.y * cos(rotation)
			);

		b2Vec2 outVector = outPortal->getOutVector();

		// Avoid beeing trapped in portals
		outVelocity += outVector;

		outVector *= 0.1;

		// Update player velocity and position
		getBody()->SetLinearVelocity(outVelocity);

		goingTroughPortal = 2;
		teleportTo(outVector + outPortal->getPosition());
	}
}

void TeleportableEntity::teleportTo(const b2Vec2 & position) {
	setPosition(position);
	teleporting = true;
	gameEventCreator.addTeleportation(this);	
}

void TeleportableEntity::teleport() {
	getBody()->SetTransform(getPosition(), 0);
	teleporting = false;
}

bool TeleportableEntity::isTeleporting() {
	return teleporting;
}