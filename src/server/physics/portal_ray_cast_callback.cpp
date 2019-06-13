#include "server/physics/portal_ray_cast_callback.h"

#include "server/entities/player.h"

#define IGNORE_FIXTURE -1.0f;

float32 PortalRayCastCallback::ReportFixture(b2Fixture* fixture, 
	const b2Vec2& point, const b2Vec2& normal, float32 doClipFixture) {

	b2Body * body = fixture->GetBody();
	Entity* newEntity = static_cast<Entity*>(body->GetUserData());

	// Go through dynamics entities
	if(newEntity->getType() >= DYNAMIC_ENTITY_START ||
		newEntity->getType() == TYPE_PORTAL) {
		return IGNORE_FIXTURE;
	}

	hit = true;
	entity = newEntity;
	m_point = point;
	m_normal = normal;

	return doClipFixture;
}