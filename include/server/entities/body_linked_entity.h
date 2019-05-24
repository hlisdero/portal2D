#ifndef BODY_LINKED_ENTITY_H
#define BODY_LINKED_ENTITY_H

#include "Box2D/Box2D.h"

// MetersEntity
class BodyLinkedEntity {
public:
	virtual void attachBody(b2Body * body);
	virtual b2Body * getBody();

private:
	b2Body * body;
};

#endif