#include "server/world.h"

// Initialize the world with the gravity vector
World::World(Map & map) :
	world(b2Vec2(0.0f, -10.0f)),
	bodyFactory(world), 
	map(map) {
	this->world.SetContactListener(&this->contactListener);

	const std::vector<Entity*> & staticEntities = map.getStaticEntities();
	for(uint i = 0; i < staticEntities.size(); i++) {
		this->bodyFactory.createBody(staticEntities[i]);
	}

	const std::vector<Entity*> & dynamicEntities = map.getDynamicEntities();
	for(uint i = 0; i < dynamicEntities.size(); i++) {
		this->bodyFactory.createBody(dynamicEntities[i]);
	}
}

void World::createPlayer(PlayerEntity * player) {
	this->players.push_back(player);
	this->bodyFactory.createBody(player);
}

void World::updatePhysics() {
	for(uint i = 0; i < players.size(); i++) {
		players[i]->applyMovement();
	}

	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	this->world.Step(timeStep, velocityIterations, positionIterations);
}

const std::vector<Entity*> World::getDynamicEntities() const {
	const b2Body * body = this->world.GetBodyList();

	std::vector<Entity*> entities;

	while(body != nullptr) {
		Entity * entity = (Entity *) body->GetUserData();

		if(entity->getType() >= DYNAMIC_ENTITY_START) {
			const b2Vec2 position = body->GetPosition();
			entity->setX(position.x);
			entity->setY(position.y);

			entities.push_back(entity);
		}

		body = body->GetNext();
	}

	return std::move(entities);
}
