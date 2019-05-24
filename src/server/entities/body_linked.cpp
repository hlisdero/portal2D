#include "server/entities/body_linked.h"

void BodyLinked::attachBody(b2Body * body) {
	this->body = body;
}

b2Body * BodyLinked::getBody() {
	return this->body;
}