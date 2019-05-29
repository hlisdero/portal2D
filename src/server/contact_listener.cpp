#include "server/contact_listener.h"

#include "server/entities/player.h"
#include "server/entities/rock.h"
#include "server/entities/energy_receiver.h"
#include "server/entities/button.h"
#include "server/entities/end_barrier.h"

void ContactListener::BeginContact(b2Contact * contact) {
	handleContact(contact, true);
}

void ContactListener::EndContact(b2Contact * contact) {
	handleContact(contact, false);
}

void ContactListener::handleContact(b2Contact * contact, bool inContact) {
	Entity * userDataA = static_cast<Entity*>(
		contact->GetFixtureA()->GetBody()->GetUserData());
	Entity * userDataB = static_cast<Entity*>(
		contact->GetFixtureB()->GetBody()->GetUserData());

	broadcastContact(userDataA, userDataB, contact, inContact);
	broadcastContact(userDataB, userDataA, contact, inContact);
}

void ContactListener::broadcastContact(Entity * entityA, Entity * entityB, b2Contact * contact, bool inContact) {
	switch(entityA->getType()) {
		case TYPE_PLAYER:
			entityA->as<PlayerEntity>()->handleContactWith(entityB, contact, inContact);
			break;
		// case TYPE_ROCK:		
		// 	static_cast<RockEntity*>(entityA)->handleContactWith(entityB, contact, inContact);
		// 	break;
		case TYPE_ENERGY_RECEIVER:
			entityA->as<EnergyReceiverEntity>()->handleContactWith(entityB, contact, inContact);
			break;
		case TYPE_BUTTON:
			entityA->as<ButtonEntity>()->handleContactWith(entityB, contact, inContact);
			break;
		case TYPE_END_BARRIER:
			entityA->as<EndBarrierEntity>()->handleContactWith(entityB, contact, inContact);
			break;
		// case TYPE_ENERGY_BALL:
		// 	break;
		default:
			break;
	}
}