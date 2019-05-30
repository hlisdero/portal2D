#include "server/entities/body_factory.h"
#include "server/entities/player.h"
#include "server/entities/rock.h"
#include "server/entities/portal.h"
#include "server/entities/energy_ball.h"
#include "server/entities/end_barrier.h"

#include "common/entities/entities_settings.h"

BodyFactory::BodyFactory(b2World & world) : world(world) {}

b2BodyDef BodyFactory::createBodyDef(Entity * entity) {
	b2BodyDef bodyDef;

	bodyDef.angle = entity->getRotationRad();
	
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

void BodyFactory::setButtonShape(b2PolygonShape & shape, const float * entitySettings, b2Vec2 & offset) {
	b2Vec2 points[4];
	points[0].Set(-1 * entitySettings[HALF_WIDTH], 
				-1 * entitySettings[HALF_HEIGHT]);

	points[1].Set(-1 * BUTTON_TOP_SIZE_PERCENTAGE * entitySettings[HALF_WIDTH], 
				entitySettings[HALF_HEIGHT]);

	points[2].Set(BUTTON_TOP_SIZE_PERCENTAGE * entitySettings[HALF_WIDTH], 
				entitySettings[HALF_HEIGHT]);

	points[3].Set(entitySettings[HALF_WIDTH], 
				-1 * entitySettings[HALF_HEIGHT]);

	for(b2Vec2 & point : points) {
		point += offset;
	}

	shape.Set(points, 4);
}

void BodyFactory::setDiagBlockShape(b2PolygonShape & shape, const float * entitySettings, b2Vec2 & offset) {
	b2Vec2 points[3];
	points[0].Set(-1 * entitySettings[HALF_WIDTH], 
				-1 * entitySettings[HALF_HEIGHT]);

	points[1].Set(-1 * entitySettings[HALF_WIDTH], 
				entitySettings[HALF_HEIGHT]);

	points[2].Set(entitySettings[HALF_WIDTH], 
				-1 * entitySettings[HALF_HEIGHT]);

	for(b2Vec2 & point : points) {
		point += offset;
	}

	shape.Set(points, 3);
}

void BodyFactory::setBlockShape(b2PolygonShape & shape, const float * entitySettings, b2Vec2 & offset) {
	shape.SetAsBox(
			entitySettings[HALF_WIDTH], entitySettings[HALF_HEIGHT],
			offset, 0.0f);
}

b2PolygonShape BodyFactory::createShape(Entity * entity) {
	const float (&entitySettings)[4] = entitiesSettings[entity->getType()];
	b2Vec2 offset(entitySettings[X_OFFSET], entitySettings[Y_OFFSET]);

	b2PolygonShape shape;

	if(entity->getType() == TYPE_METAL_DIAG_BLOCK) {
		this->setDiagBlockShape(shape, entitySettings, offset);
	} else if(entity->getType() == TYPE_BUTTON) {
		this->setButtonShape(shape, entitySettings, offset);
	} else {
		this->setBlockShape(shape, entitySettings, offset);
	}

	return shape;
}

void BodyFactory::attachBody(Entity * entity, b2Body * body) {
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
		case TYPE_END_BARRIER:
			entity->as<EndBarrierEntity>()->attachBody(body);
			break;
		case TYPE_ENERGY_BALL:
			entity->as<EnergyBallEntity>()->attachBody(body);
			break;
		default:
			break;
	}
}

void BodyFactory::createBody(Entity * entity) {
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