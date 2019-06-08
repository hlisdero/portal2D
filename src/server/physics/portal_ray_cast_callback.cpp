#include "server/physics/portal_ray_cast_callback.h"

#include "server/entities/player.h"

float32 PortalRayCastCallback::ReportFixture(b2Fixture* fixture, 
	const b2Vec2& point, const b2Vec2& normal, float32 fraction) {

	b2Body * body = fixture->GetBody();
	Entity* entity = static_cast<Entity*>(body->GetUserData());

	// Go through dynamics entities
	if(entity->getType() >= DYNAMIC_ENTITY_START ||
		entity->getType() == TYPE_PORTAL) {
		return -1.0f;
	}

	this->hit = true;
	this->body = body;
	this->m_point = point;
	this->m_normal = normal;

	return fraction;
}