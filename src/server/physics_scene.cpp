#include "server/physics_scene.h"

// Initialize the world with the gravity vector
PhysicsScene::PhysicsScene() : Scene(), 
	world(b2Vec2(0.0f, -10.0f)) {
	b2BodyDef groundBodyDef;
	b2Body * groundBody = this->world.CreateBody(&groundBodyDef);

	createStaticEntities(groundBody);
	createDynamicEntities();
}

void PhysicsScene::createStaticEntities(b2Body * groundBody) {
	// TODO load from file
	createStaticEntity(groundBody, Entity(MetalBlock, 0.0f, -2.0f));
	createStaticEntity(groundBody, Entity(MetalBlock, 0.0f, 0.0f));
}

void PhysicsScene::createDynamicEntities() {
	// TODO load from file
	createDynamicEntity(Entity(Rock, 1.0f, -1.0f));
}

void PhysicsScene::createDynamicEntity(Entity entity) {
	b2BodyDef bodyDef;
	bodyDef.position.Set(entity.getX(), entity.getY());

	bodyDef.type = (entity.getType() >= KINEMATIC_ENTITY_START) ? b2_kinematicBody : b2_dynamicBody;

	b2Body * body = this->world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 1.0f);

	body->CreateFixture(&shape, 1.0f);
	body->SetUserData(&entity);
}

void PhysicsScene::createStaticEntity(b2Body * groundBody, Entity entity) {
	b2PolygonShape shape;

	shape.SetAsBox(1.0f, 1.0f, b2Vec2(entity.getX(), entity.getY()), 0.0f);

	groundBody->CreateFixture(&shape, 0.0f);

	this->staticEntities.push_back(entity);
}

void PhysicsScene::addPlayer() {
	createDynamicEntity(Entity(Player, 1.0f, 0.0f));
}

void PhysicsScene::updatePhysics() {
	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	this->world.Step(timeStep, velocityIterations, positionIterations);
}

std::vector<Entity> PhysicsScene::getStaticEntities() {
	return this->staticEntities;
}

std::vector<Entity> PhysicsScene::getDynamicEntities() {
	b2Body * body = this->world.GetBodyList();

	std::vector<Entity> entities;

	while(body != nullptr) {
		Entity * entityPtr = (Entity *) body->GetUserData();

		if(entityPtr != nullptr) {
			const b2Vec2 position = body->GetPosition();
			(*entityPtr).setX(position.x);
			(*entityPtr).setY(position.y);

			entities.push_back(*entityPtr);
		}

		body = body->GetNext();
	}

	return entities;
}