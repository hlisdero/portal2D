#ifndef BODY_LINKED_H
#define BODY_LINKED_H

#include "Box2D/Box2D.h"

class BodyLinked {
public:
	virtual void attachBody(b2Body * body);
	virtual b2Body * getBody();

private:
	b2Body * body;
};

#endif