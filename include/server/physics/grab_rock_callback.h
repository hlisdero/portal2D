#ifndef GRAB_ROCK_CALLBACK_H
#define GRAB_ROCK_CALLBACK_H

#include "Box2D/Box2D.h"
#include "server/entities/rock.h"

class GrabRockCallback : public b2QueryCallback {
public:
	GrabRockCallback(const b2Vec2 & playerPosition);

	virtual bool ReportFixture(b2Fixture* fixture) override;

	const b2Vec2 & playerPosition;
	float minDistance = -1;
	RockEntity * rock = nullptr;
};

#endif