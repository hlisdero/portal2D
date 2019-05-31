#include "server/portal_ray_cast_callback.h"

float32 PortalRayCastCallback::ReportFixture(b2Fixture* fixture, 
	const b2Vec2& point, const b2Vec2& normal, float32 fraction) {

	this->body = fixture->GetBody();
	Entity* entity = static_cast<Entity*>(this->body->GetUserData());

	// Go through players
	if(entity.getType() == TYPE_PLAYER) {
		return -1.0f;
	}

	this->hit = true;
	this->m_point = point;
	this->m_normal = normal;

	return fraction;
}