#include "server/physics_scene.h"

#include "server/entities/rock.h"

// Initialize the world with the gravity vector
PhysicsScene::PhysicsScene() :
	world(b2Vec2(0.0f, -10.0f)), entityFactory(world) {
	this->world.SetContactListener(&this->contactListener);

	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 1.0f, 1.0f, 0.0f));
	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 2.0f, 1.0f, 0.0f));
	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 3.0f, 1.0f, 0.0f));

	for(uint i = 0; i < this->staticEntities.size(); i++) {
		this->entityFactory.createBody(this->staticEntities[i]);
	}

	this->entityFactory.createBody(new RockEntity(1.0f, 5.0f));
}

void PhysicsScene::createPlayer(PlayerEntity * player) {
	this->players.push_back(player);
	this->entityFactory.createBody(player);
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

std::vector<Entity> PhysicsScene::getStaticEntities() const {
	std::vector<Entity> entities;

	for(uint i = 0; i < this->staticEntities.size(); i++) {
		entities.push_back(*this->staticEntities[i]);
	}

	return entities;
}

std::vector<Entity> PhysicsScene::getDynamicEntities() const {
	const b2Body * body = this->world.GetBodyList();

	std::vector<Entity> entities;

	while(body != nullptr) {
		Entity * entityPtr = (Entity *) body->GetUserData();

		if(entityPtr->getType() >= DYNAMIC_ENTITY_START) {
			const b2Vec2 position = body->GetPosition();
			entityPtr->setX(position.x);
			entityPtr->setY(position.y);

			entities.push_back(*entityPtr);
		}

		body = body->GetNext();
	}

	return entities;
}
