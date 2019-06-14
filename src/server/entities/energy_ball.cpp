#include "server/entities/energy_ball.h"

#include "server/entities/energy_receiver.h"
#include "server/objects/math.h"
#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

EnergyBallEntity::EnergyBallEntity(const float intialX, const float intialY, 
	const float angle, GameEventCreator & gameEventCreator, EnergyEmitterEntity & owner) :
	TeleportableEntity(TYPE_ENERGY_BALL, intialX, intialY, 
		angle, gameEventCreator), owner(owner) {}

void EnergyBallEntity::handleContactWith(Entity * other, b2Contact * contact, bool newContact) {
	TeleportableEntity::handleContactWith(other, contact, newContact);

	if(isGoingThroughPortal() ||
		other->getType() >= DYNAMIC_ENTITY_START ||
		other->getType() == TYPE_PORTAL ||
		other->getType() == TYPE_ENERGY_BAR) {
		return;
	}

	if(other == &owner && justEmitted) {
		justEmitted = newContact;
		return;
	}

	if(!newContact) {
		return;
	}

	if(other->getType() == TYPE_METAL_BLOCK ||
		other->getType() == TYPE_METAL_DIAG_BLOCK) {

		evaluateCollision(contact);

		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);
		worldManifold.normal.Normalize();
		worldManifold.normal *= SETTINGS.ENERGY_BALL_SPEED;

		getBody()->SetLinearVelocity(worldManifold.normal);
		setRotationDeg(Math::getRotationDegFromNormal(worldManifold.normal));
	} else {

		if(other->getType() == TYPE_ENERGY_RECEIVER) {
			other->as<EnergyReceiverEntity>()->setState(STATE_ENABLED);
		}

		owner.setNoBall();
		gameEventCreator.addBallDestruction(this);
		destroy();
	}
}

void EnergyBallEntity::evaluateCollision(b2Contact * contact) {
	const b2Transform & transformA = contact->GetFixtureA()->GetBody()->GetTransform();
	const b2Transform & transformB = contact->GetFixtureB()->GetBody()->GetTransform();

	contact->Evaluate(contact->GetManifold(), transformA, transformB);
}