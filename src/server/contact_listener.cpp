#include "server/contact_listener.h"

#include "server/entities/m_entity.h"

void ContactListener::BeginContact(b2Contact * contact) {
	Entity * userDataA = (Entity*) contact->GetFixtureA()->GetBody()->GetUserData();
	Entity * userDataB = (Entity*) contact->GetFixtureB()->GetBody()->GetUserData();

	if(userDataA != nullptr) {
		userDataA->beginContactWith(userDataB, contact);
	}
	if(userDataB != nullptr) {
		userDataB->beginContactWith(userDataA, contact);
	}
}

void ContactListener::EndContact(b2Contact * contact) {
	Entity * userDataA = (Entity*) contact->GetFixtureA()->GetBody()->GetUserData();
	Entity * userDataB = (Entity*) contact->GetFixtureB()->GetBody()->GetUserData();

	if(userDataA != nullptr) {
		userDataA->endContactWith(userDataB, contact);
	}

	if(userDataB != nullptr) {
		userDataB->endContactWith(userDataA, contact);
	}
}
