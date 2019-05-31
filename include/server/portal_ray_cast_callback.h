#ifndef PORTAL_RAY_CAST_CALLBACK_H
#define PORTAL_RAY_CAST_CALLBACK_H

class PortalRayCastCallback : public b2RayCastCallback
{
public:
	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;
	
	// TODO private
	bool hit = false;
	b2Vec2 m_point;
	b2Vec2 m_normal;
	b2Body * body;
};

#endif