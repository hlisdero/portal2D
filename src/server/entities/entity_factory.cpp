#include "server/entities/entity_factory.h"

#include <map>

#define X_OFFSET 0
#define Y_OFFSET 1
#define HALF_WIDTH 2
#define HALF_HEIGHT 3

static const float entitiesSettings[4][ENTITY_TYPES_LENGTH] = {
	// {x_offset, y_offset, half-width, half-height}

	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_STONE_BLOCK
	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_METAL_BLOCK
	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_METAL_DIAG_BLOCK
	{0.0f, -0.25f, 0.5f, 0.25f}, // TYPE_ACID
	{0.0f, 0.0f, 0.5f, 1.0f}, // TYPE_DOOR
	{0.0f, 0.5f, 0.5f, 0.05f}, // TYPE_ENERGY_BAR
	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_ENERGY_EMITTOR
	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_ENERGY_RECEIVER
	{0.0f, 0.0f, 0.5f, 0.5f}, // TYPE_ENDCAKE
	{0.0f, -0.25f, 0.5f, 0.25f}, // TYPE_BUTTON
	{-0.5f, 0.0f, 0.05f, 0.5f}, // TYPE_PORTAL
	{0.0f, 0.0f, 0.25f, 0.25f}, // TYPE_ROCK
	{0.0f, -0.1f, 0.25f, 0.4f}, // TYPE_PLAYER
	{0.0f, 0.0f, 0.25f, 0.25f}, // TYPE_ENERGY_BALL
};


EntityFactory::EntityFactory(b2World & world) : world(world) {}

void EntityFactory::createBody(MEntity * entity) {
	float & entitySettings = entitiesSettings[entity->getType()];

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