#include "server/entities/attributes/teleportable_entity.h"

#include "server/objects/math.h"

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
		portalsToGoThrough--;	
	}
}

bool TeleportableEntity::isGoingThroughPortal() {
	return portalsToGoThrough > 0;
}

void TeleportableEntity::goThroughPortal(PortalEntity * inPortal) {
	// Do not go through the portal if already going through the portal
	if(isGoingThroughPortal()) {
		return;
	}

	PortalEntity * outPortal = inPortal->getTwin();

	if(outPortal != nullptr) {
		float rotation =  outPortal->getRotationRad() - (Math::PI + inPortal->getRotationRad());
		const b2Vec2 & inVelocity = getBody()->GetLinearVelocity();

		// Apply rotation to velocity
		b2Vec2 outVelocity = Math::rotateVectorBy(rotation, inVelocity);

		b2Vec2 outVector = outPortal->getOutVector();

		if(getType() == TYPE_ENERGY_BALL) {
			setRotationDeg(outPortal->getRotationDeg());
		} else {
			// Avoid beeing trapped in portals
			outVelocity += outVector;
		}

		// Add 10% of the out portal vector to move outside of the portal
		outVector *= 0.1;

		// Update player velocity and position
		getBody()->SetLinearVelocity(outVelocity);

		portalsToGoThrough = 2;
		teleportTo(outPortal->getX() + outVector.x, 
			outPortal->getY() + outVector.y);
	}
}

void TeleportableEntity::teleportTo(float x, float y) {
	setX(x);
	setY(y);
	teleporting = true;
	gameEventCreator.addTeleportation(this);	
}

void TeleportableEntity::teleport() {
	getBody()->SetTransform(b2Vec2(getX(), getY()), getRotationRad());
	teleporting = false;
}

bool TeleportableEntity::isTeleporting() {
	return teleporting;
}