#include "server/physics/contact_listener.h"

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
	if(entityA->getType() >= DYNAMIC_ENTITY_START || 
		entityA->getType() == TYPE_ENERGY_RECEIVER ||
		entityA->getType() == TYPE_BUTTON ||
		entityA->getType() == TYPE_END_BARRIER) {
		entityA->as<HandleContact>()->handleContactWith(entityB, contact, inContact);
	}
}

void ContactListener::PreSolve(b2Contact * contact, const b2Manifold * manifold) {
	b2Fixture * fixtureA = contact->GetFixtureA();
	b2Fixture * fixtureB = contact->GetFixtureB();

	handlePreSolve(fixtureA, fixtureB, contact, manifold);
	handlePreSolve(fixtureB, fixtureA, contact, manifold);
}

void ContactListener::handlePreSolve(b2Fixture * fixtureA, b2Fixture * fixtureB, b2Contact * contact, const b2Manifold * manifold) {
	Entity * entityA = static_cast<Entity*>(
		fixtureA->GetBody()->GetUserData());

	if(entityA->getType() == TYPE_PLAYER) {
		if(entityA->as<PlayerEntity>()->waitingForResetPosition()) {
			contact->SetEnabled(false);
		} else {
			b2WorldManifold worldManifold;
			contact->GetWorldManifold(&worldManifold);

			// If it's horizontal direction and if the vertical distance is less than the threshold
			if(manifold->localNormal.y == 0 && abs(fixtureA->GetAABB(0).lowerBound.y - fixtureB->GetAABB(0).upperBound.y) < CONTACT_THRESHOLD) {
				contact->SetEnabled(false);
			}
		}
	}
}