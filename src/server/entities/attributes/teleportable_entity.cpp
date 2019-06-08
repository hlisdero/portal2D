#include "server/entities/attributes/teleportable_entity.h"

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

		resetPosition = true;
		setX(outPortal->getX() + outVector.x);
		setY(outPortal->getY() + outVector.y);
		goingTroughPortal = 2;
	}
}

bool TeleportableEntity::applyPositionReset() {
	if(resetPosition) {
		getBody()->SetTransform(b2Vec2(getX(), getY()), 0);
		resetPosition = false;

		return true;
	}

	return false;
}

bool TeleportableEntity::isMarkedForPositionReset() {
	return resetPosition;
}

void TeleportableEntity::markForPositionReset() {
	resetPosition = true;
}