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
		other->getType() == TYPE_PORTAL) {
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

		if(contact->GetFixtureA()->GetBody()->GetUserData() == (Entity*)this) {
			worldManifold.normal *= -1;
		}

		int blockRotation = Math::getRotationDegFromNormal(worldManifold.normal);

		// strait bounce
		if(abs(blockRotation - getRotationDeg()) == 180) {
			getBody()->SetLinearVelocity(-1 * getBody()->GetLinearVelocity());
			setRotationDeg((getRotationDeg() + 180) % 360);
		// diag bounce
		} else {
			if((Math::getRotationDegFromNormal(worldManifold.normal) - getRotationDeg() + 360) % 360 < 180) {
				setRotationDeg((getRotationDeg() + 90) % 360);
			} else {
				setRotationDeg((getRotationDeg() + 270) % 360);
			}
			b2Vec2 direction = Math::vectorFromRotation(getRotationRad());
			direction *= SETTINGS.ENERGY_BALL_SPEED;
			getBody()->SetLinearVelocity(direction);

			b2Vec2 & contactPoint = worldManifold.points[0];
			Math::toEdgeMiddle(contactPoint, worldManifold.normal);
			teleportTo(contactPoint.x, contactPoint.y);
		}

	} else {

		if(other->getType() == TYPE_ENERGY_RECEIVER) {
			other->as<EnergyReceiverEntity>()->setState(STATE_ENABLED);
		}

		gameEventCreator.addBallDestruction(this);
		destroy();
	}
}

EnergyBallEntity::~EnergyBallEntity() {
	owner.setNoBall();
}

void EnergyBallEntity::evaluateCollision(b2Contact * contact) {
	const b2Transform & transformA = contact->GetFixtureA()->GetBody()->GetTransform();
	const b2Transform & transformB = contact->GetFixtureB()->GetBody()->GetTransform();

	contact->Evaluate(contact->GetManifold(), transformA, transformB);
}

std::chrono::system_clock::time_point * EnergyBallEntity::getDeathTP() {
	return &deathTP;
}