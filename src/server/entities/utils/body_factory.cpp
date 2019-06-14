#include "server/entities/utils/body_factory.h"

#include "server/entities/gate.h"
#include "server/entities/end_barrier.h"
#include "server/entities/energy_ball.h"
#include "server/entities/player.h"
#include "server/entities/portal.h"
#include "server/entities/rock.h"
#include "server/objects/math.h"
#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

#include "common/entities/entities_settings.h"

#define DISABLE_GRAVITY 0.0f;

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
		bodyDef.type = b2_dynamicBody;
		bodyDef.gravityScale = DISABLE_GRAVITY;
	} else {
		bodyDef.type = b2_staticBody;
	}

	return std::move(bodyDef);
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

void BodyFactory::setDiamondShape(b2PolygonShape & shape, const float * entitySettings, b2Vec2 & offset) {
	b2Vec2 points[4];
	points[0].Set(-1 * entitySettings[HALF_WIDTH], 0);
	points[1].Set(0, entitySettings[HALF_HEIGHT]);
	points[2].Set(entitySettings[HALF_WIDTH], 0);
	points[3].Set(0, -1 * entitySettings[HALF_HEIGHT]);

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
		setDiagBlockShape(shape, entitySettings, offset);
	} else if(entity->getType() == TYPE_BUTTON) {
		setButtonShape(shape, entitySettings, offset);
	} else if(entity->getType() == TYPE_ENERGY_BALL) {
		setDiamondShape(shape, entitySettings, offset);
	} else {
		setBlockShape(shape, entitySettings, offset);
	}

	return std::move(shape);
}

void BodyFactory::attachBody(Entity * entity, b2Body * body) {
	if(entity->getType() >= DYNAMIC_ENTITY_START ||
		entity->getType() == TYPE_GATE ||
		entity->getType() == TYPE_PORTAL) {
		entity->as<BodyLinked>()->attachBody(body);
	}
}

b2FixtureDef BodyFactory::createFixtureDef(Entity * entity, 
	b2PolygonShape * shape, b2BodyDef & bodyDef) {

	b2FixtureDef fixtureDef;

	fixtureDef.shape = shape;
	fixtureDef.density = (bodyDef.type == b2_staticBody) ? 
		0.0f : SETTINGS.DYNAMIC_BODY_DENSITY;

	if(entity->getType() == TYPE_PLAYER) {
		fixtureDef.friction = 0;
	} else if(entity->getType() == TYPE_ENERGY_BAR ||
		entity->getType() == TYPE_END_BARRIER ||
		entity->getType() == TYPE_ENERGY_BALL) {
		fixtureDef.isSensor = true;
	}

	return std::move(fixtureDef);
}

void BodyFactory::createBody(Entity * entity) {
	entity->setId(this->nextDynamicEntityId++);

	b2BodyDef bodyDef = createBodyDef(entity);
	b2PolygonShape shape = createShape(entity);

	b2Body * body = this->world.CreateBody(&bodyDef);

	if(entity->getType() == TYPE_ENERGY_BALL) {
		b2Vec2 direction = Math::vectorFromRotation(entity->getRotationRad());
		direction *= SETTINGS.ENERGY_BALL_SPEED;
		body->SetLinearVelocity(direction);
	}

	// "Attach" shape to body
	b2FixtureDef fixtureDef = createFixtureDef(entity, &shape, bodyDef);
	b2Fixture * fixture = body->CreateFixture(&fixtureDef);

	// Set shape center to entity for client-side use
	const b2Vec2 & center = fixture->GetAABB(0).GetCenter();
	entity->setX(center.x);
	entity->setY(center.y);
	
	body->SetUserData(entity);
	attachBody(entity, body);
}

b2AABB BodyFactory::createPortalAABB(b2Vec2 & position, float rotation) {
	b2PolygonShape shape;
	auto & portalSettings = entitiesSettings[TYPE_PORTAL];
	b2Vec2 offset(portalSettings[X_OFFSET], portalSettings[Y_OFFSET]);
	setBlockShape(shape, portalSettings, offset);

	b2AABB aabb;
	shape.ComputeAABB(&aabb, b2Transform(position, b2Rot(rotation)), 0);

	return std::move(aabb);
}