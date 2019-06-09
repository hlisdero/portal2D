#ifndef PORTAL_ENTITY_H
#define PORTAL_ENTITY_H

#include "common/objects/portal_color.h"
#include "server/entities/entity.h"
#include "server/entities/attributes/body_linked.h"

class PortalEntity :  public Entity, public BodyLinked {
public:
	PortalEntity(const float x, const float y, const b2Vec2 & normal, const PortalColor color);

	void move(const b2Vec2 position, const b2Vec2 & normal);

	PortalEntity * getTwin();
	void setTwin(PortalEntity * twin);

	const b2Vec2 & getOutVector() const;

private:
	PortalEntity * twin = nullptr;
	b2Vec2 outVector;
	PortalColor color;

	static float getRotationFromNormal(const b2Vec2 & normal);
};

#endif  // PORTAL_ENTITY_H