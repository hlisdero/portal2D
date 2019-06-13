#include "server/physics/contact_listener.h"

#include "server/entities/attributes/teleportable_entity.h"
#include "server/entities/portal.h"
#include "server/entities/attributes/handle_contact.h"
#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

void ContactListener::BeginContact(b2Contact * contact) {
	handleContact(contact, true);
}

void ContactListener::EndContact(b2Contact * contact) {
	handleContact(contact, false);
}

void ContactListener::handleContact(b2Contact * contact, bool inContact) {
	Entity * entityA = static_cast<Entity*>(
		contact->GetFixtureA()->GetBody()->GetUserData());
	Entity * entityB = static_cast<Entity*>(
		contact->GetFixtureB()->GetBody()->GetUserData());

	if(entityA == nullptr || entityB == nullptr) {
		return;
	}

	broadcastContact(entityA, entityB, contact, inContact);
	broadcastContact(entityB, entityA, contact, inContact);
}

void ContactListener::broadcastContact(Entity * entityA, Entity * entityB, b2Contact * contact, bool inContact) {
	if(entityA->getType() >= DYNAMIC_ENTITY_START || 
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

	if(entityA->getType() == TYPE_PORTAL
		&& entityA->as<PortalEntity>()->getTwin() == nullptr) {
		contact->SetEnabled(false);
	} else if(entityA->getType() >= DYNAMIC_ENTITY_START && entityA->as<TeleportableEntity>()->isTeleporting()) {
		contact->SetEnabled(false);	
	} else if(entityA->getType() == TYPE_PLAYER ||
		entityA->getType() == TYPE_ROCK) {
		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);

		// If it's horizontal direction and if the vertical distance is less than the threshold
		if(manifold->localNormal.y == 0 && abs(fixtureA->GetAABB(0).lowerBound.y - fixtureB->GetAABB(0).upperBound.y) < SETTINGS.CONTACT_THRESHOLD) {
			contact->SetEnabled(false);
		}
	}
}