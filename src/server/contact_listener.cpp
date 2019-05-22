#include "server/contact_listener.h"

#include "server/entities/m_entity.h"

void ContactListener::BeginContact(b2Contact * contact) {
	MEntity * userDataA = (MEntity*) contact->GetFixtureA()->GetBody()->GetUserData();
	MEntity * userDataB = (MEntity*) contact->GetFixtureB()->GetBody()->GetUserData();

	if(userDataA != nullptr) {
		userDataA->beginContactWith(userDataB, contact);
	}
	if(userDataB != nullptr) {
		userDataB->beginContactWith(userDataA, contact);
	}
}

void ContactListener::EndContact(b2Contact * contact) {
	MEntity * userDataA = (MEntity*) contact->GetFixtureA()->GetBody()->GetUserData();
	MEntity * userDataB = (MEntity*) contact->GetFixtureB()->GetBody()->GetUserData();

	if(userDataA != nullptr) {
		userDataA->endContactWith(userDataB, contact);
	}

	if(userDataB != nullptr) {
		userDataB->endContactWith(userDataA, contact);
	}
}