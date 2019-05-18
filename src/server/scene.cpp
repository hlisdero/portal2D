#include "server/scene.h"

// Initialize the world with the gravity vector
Scene::Scene() : 
	world(b2Vec2(0.0f, -10.0f)), 
	staticEntities(), dynamicEntities() {
	b2BodyDef groundBodyDef;
	b2Body * groundBody = this->world.CreateBody(&groundBodyDef);

	createStaticEntities(groundBody);
	createDynamicEntities();
}

void Scene::createStaticEntities(b2Body * groundBody) {
	// TODO load from file
	createStaticEntity(groundBody, Entity(MetalBlock, 0.0f, -2.0f));
	createStaticEntity(groundBody, Entity(MetalBlock, 0.0f, 0.0f));
}

void Scene::createDynamicEntities() {

}

void Scene::createDynamicEntity() {
	
}

void Scene::createStaticEntity(b2Body * groundBody, Entity entity) {
	b2PolygonShape shape;

	shape.SetAsBox(1.0f, 1.0f, b2Vec2(entity.getX(), entity.getY()), 0.0f);

	groundBody->CreateFixture(&shape, 0.0f);

	this->staticEntities.push_back(entity);
}

void Scene::addPlayer() {
	createDynamicEntity();
}

void Scene::updatePhysics() {
	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	this->world.Step(timeStep, velocityIterations, positionIterations);
}