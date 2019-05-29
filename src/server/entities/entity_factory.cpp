#include "server/entities/entity_factory.h"
#include "server/entities/player.h"
#include "server/entities/rock.h"
#include "server/entities/portal.h"
#include "server/entities/energy_ball.h"

EntityFactory::EntityFactory(b2World & world) : world(world) {}

b2BodyDef EntityFactory::createBodyDef(Entity * entity) {
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

	return bodyDef;
}

b2PolygonShape EntityFactory::createShape(Entity * entity) {
	const float (&entitySettings)[4] = entitiesSettings[entity->getType()];

	b2PolygonShape shape;

	shape.SetAsBox(entitySettings[HALF_WIDTH],
		entitySettings[HALF_HEIGHT],
		b2Vec2(entitySettings[X_OFFSET], entitySettings[Y_OFFSET]),
		0.0f);

	return shape;
}

void EntityFactory::attachBody(Entity * entity, b2Body * body) {
	// TODO find a better way?
	switch(entity->getType()) {
		case TYPE_PLAYER:
			entity->as<PlayerEntity>()->attachBody(body);
			break;
		case TYPE_ROCK:
			entity->as<RockEntity>()->attachBody(body);
			break;
		case TYPE_PORTAL:
			entity->as<PortalEntity>()->attachBody(body);
			break;
		case TYPE_ENERGY_BALL:
			entity->as<EnergyBallEntity>()->attachBody(body);
			break;
		default:
			break;
	}
}

void EntityFactory::createBody(Entity * entity) {
	entity->setId(this->nextDynamicEntityId++);

	b2BodyDef bodyDef = createBodyDef(entity);
	b2PolygonShape shape = createShape(entity);

	b2Body * body = this->world.CreateBody(&bodyDef);
	attachBody(entity, body);
	body->SetUserData(entity);

	if(entity->getType() == TYPE_ENERGY_BALL) {
		body->SetLinearVelocity(
			b2Vec2(ENERGY_BALL_SPEED, 0.0f));
	}

	// "Attach" shape to body
	body->CreateFixture(&shape,
		(bodyDef.type == b2_staticBody) ? 0.0f : 1.0f);
}