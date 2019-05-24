#include "server/entities/entity_factory.h"

EntityFactory::EntityFactory(b2World & world) : world(world) {}

void EntityFactory::createBody(Entity * entity) {
	const float (&entitySettings)[4] = entitiesSettings[entity->getType()];

	b2BodyDef bodyDef;
	bodyDef.angle = entity->getAngle();
	bodyDef.position.Set(entity->getX(), entity->getY());

	if(entity->getType() == TYPE_PLAYER
		|| entity->getType() == TYPE_ROCK) {
		bodyDef.type = b2_dynamicBody;
		bodyDef.fixedRotation = true;
	} else if(entity->getType() == TYPE_ENERGY_BALL) {
		bodyDef.type = b2_kinematicBody;
	} else {
		bodyDef.type = b2_staticBody;
	}

	b2Body * body = this->world.CreateBody(&bodyDef);

	if(entity->getType() == TYPE_ENERGY_BALL) {
		body->SetLinearVelocity(b2Vec2(ENERGY_BALL_SPEED, 0.0f));
	}

	b2PolygonShape shape;
	shape.SetAsBox(entitySettings[HALF_WIDTH],
		entitySettings[HALF_HEIGHT],
		b2Vec2(entitySettings[X_OFFSET], entitySettings[Y_OFFSET]),
		0.0f);

	body->CreateFixture(&shape,
		(bodyDef.type == b2_staticBody) ? 0.0f : 1.0f);

	body->SetUserData(entity);

	if(entity->getType() == TYPE_PORTAL
		|| entity->getType() == TYPE_PLAYER
		|| entity->getType() == TYPE_ENERGY_BALL
		|| entity->getType() == TYPE_ROCK) {
		((BodyLinkedEntity*) entity)->attachBody(body);
	}
}
