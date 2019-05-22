#include "server/entities/body_linked_entity.h"

void BodyLinkedEntity::attachBody(b2Body * body) {
	this->body = body;
}

b2Body * BodyLinkedEntity::getBody() {
	return this->body;
}