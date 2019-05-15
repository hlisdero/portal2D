#include "server_scene.hpp"

// Initialize the world with the gravity vector
ServerScene::ServerScene() : world(b2Vec2(0.0f, -10.0f)) {}

void ServerScene::create() {

	b2BodyDef groundBodyDef;
	b2Body* groundBody = this->world.CreateBody(&groundBodyDef);

	createGroundElements(groundBody);
}

void ServerScene::createGroundElements(b2Body * groundBody) {
	// Define the ground box shape.
	b2PolygonShape metalBox;

	b2Vec2 position1(0.0f, -2.0f);	
	metalBox.SetAsBox(1.0f, 1.0f, position1, 0.0f);

	// Create first metal box
	groundBody->CreateFixture(&metalBox, 0.0f);

	// Change position
	metalBox.m_centroid = b2Vec2(0.0f, 0.0f);

	// Create second metal box
	groundBody->CreateFixture(&metalBox, 0.0f);
}

void ServerScene::updatePhysics() {
	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	this->world.Step(timeStep, velocityIterations, positionIterations);
}