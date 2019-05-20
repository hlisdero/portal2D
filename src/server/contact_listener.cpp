#include "server/contact_listener.h"

#include "common/entities/m_entity.h"
#include "server/player_entity.h"

bool isPlayerWithVNormal(MEntity * entity, b2Vec2 & localNormal, float hy) {
	return (entity = nullptr) 
		&& (entity->getType() == TYPE_PLAYER) 
		&& (localNormal == b2Vec2(0.0f, hy));
}

void ContactListener::BeginContact(b2Contact * contact) {
	MEntity * userDataA = (MEntity*) contact->GetFixtureA()->GetBody()->GetUserData();
	MEntity * userDataB = (MEntity*) contact->GetFixtureB()->GetBody()->GetUserData();
	b2Vec2 & localNormal = contact->GetManifold()->localNormal;


	if(isPlayerWithVNormal(userDataA, localNormal, -1.0f)) {
		((PlayerEntity *) userDataA)->setOnTheFloor(true);
	} else if(isPlayerWithVNormal(userDataB, localNormal, 1.0f)) {
		((PlayerEntity *) userDataB)->setOnTheFloor(true);
	}
}

void ContactListener::EndContact(b2Contact * contact) {
	MEntity * userDataA = (MEntity*) contact->GetFixtureA()->GetBody()->GetUserData();
	MEntity * userDataB = (MEntity*) contact->GetFixtureB()->GetBody()->GetUserData();
	b2Vec2 & localNormal = contact->GetManifold()->localNormal;

	if(isPlayerWithVNormal(userDataA, localNormal, -1.0f)) {
		((PlayerEntity *) userDataA)->setOnTheFloor(false);
	} else if(isPlayerWithVNormal(userDataB, localNormal, 1.0f)) {
		((PlayerEntity *) userDataB)->setOnTheFloor(false);
	}
}