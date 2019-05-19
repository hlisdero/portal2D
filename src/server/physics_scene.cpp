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
	createStaticEntity(groundBody, MEntity(MetalBlock, -1.0f, 0.0f));
	createStaticEntity(groundBody, MEntity(MetalBlock, 1.0f, 0.0f));
}

void PhysicsScene::createDynamicEntities() {
	// TODO load from file
	createDynamicEntity(MEntity(Rock, 1.0f, 10.0f));
}

void PhysicsScene::createDynamicEntity(MEntity entity) {
	b2BodyDef bodyDef;
	bodyDef.position.Set(entity.getX(), entity.getY());

	bodyDef.type = (entity.getType() >= KINEMATIC_ENTITY_START) ? b2_kinematicBody : b2_dynamicBody;

	b2Body * body = this->world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 1.0f);

	body->CreateFixture(&shape, 1.0f);
	body->SetUserData(&entity);
}

void PhysicsScene::createStaticEntity(b2Body * groundBody, const MEntity entity) {
	b2PolygonShape shape;

	shape.SetAsBox(1.0f, 1.0f, b2Vec2(entity.getX(), entity.getY()), 0.0f);

	groundBody->CreateFixture(&shape, 0.0f);

	this->staticEntities.push_back(entity);
}

void PhysicsScene::createPlayer(PlayerEntity & player) {
	b2BodyDef bodyDef;
	bodyDef.position.Set(player.getX(), player.getY());
	bodyDef.fixedRotation = true;
	bodyDef.type = b2_dynamicBody;

	b2Body * body = this->world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(0.5f, 1.0f);

	body->CreateFixture(&shape, 1.0f);
	body->SetUserData(&player);

	player.setBody(body);

	players.push_back(&player);
}

void PhysicsScene::updatePhysics() {
	for(uint i = 0; i < players.size(); i++) {
		players[i]->applyMovement();
	}

	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	this->world.Step(timeStep, velocityIterations, positionIterations);
}

std::vector<MEntity> PhysicsScene::getStaticEntities() const {
	return this->staticEntities;
}

std::vector<MEntity> PhysicsScene::getDynamicEntities() const {
	const b2Body * body = this->world.GetBodyList();

	std::vector<MEntity> entities;

	while(body != nullptr) {
		MEntity * entityPtr = (MEntity *) body->GetUserData();

		if(entityPtr != nullptr) {
			const b2Vec2 position = body->GetPosition();
			entityPtr->setX(position.x);
			entityPtr->setY(position.y);

			entities.push_back(*entityPtr);
		}

		body = body->GetNext();
	}

	return entities;
}