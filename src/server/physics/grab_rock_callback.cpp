#include "server/physics/grab_rock_callback.h"

#define CONTINUE_SEARCH true;

GrabRockCallback::GrabRockCallback(const b2Vec2 & playerPosition) : 
	playerPosition(playerPosition) {}

bool GrabRockCallback::ReportFixture(b2Fixture* fixture) {
	b2Body * body = fixture->GetBody();
	Entity* entity = static_cast<Entity*>(body->GetUserData());

	if(entity->getType() == TYPE_ROCK) {
		b2Vec2 distanceVector = body->GetPosition();
		distanceVector -= playerPosition;

		float distanceSquared = distanceVector.LengthSquared();

		if(minDistance == -1 || distanceSquared < minDistance) {
			minDistance = distanceSquared;
			rock = entity->as<RockEntity>();
		}
	}

	return CONTINUE_SEARCH;
}