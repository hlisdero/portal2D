#ifndef PORTAL_ENTITY_H
#define PORTAL_ENTITY_H

#include "server/entities/entity.h"
#include "server/entities/attributes/with_state.h"
#include "server/entities/attributes/body_linked.h"

class PortalEntity :  public Entity, public WithState, public BodyLinked {
public:
	PortalEntity(const float x, const float y, const b2Vec2 & normal, const PortalColor color);

	void move(const float newX, const float newY, const b2Vec2 & normal);

	PortalEntity * getTwin();
	void setTwin(PortalEntity * twin);

	const b2Vec2 & getOutVector() const;

private:
	PortalEntity * twin = nullptr;
	b2Vec2 outVector;

	static float getRotationFromNormal(const b2Vec2 & normal);
};

#endif  // PORTAL_ENTITY_H