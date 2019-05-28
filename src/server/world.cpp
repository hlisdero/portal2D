#include "server/world.h"

// Initialize the world with the gravity vector
World::World(Map & map) :
	world(b2Vec2(0.0f, -10.0f)),
	entityFactory(world), 
	map(map) {
	this->world.SetContactListener(&this->contactListener);

	const std::vector<Entity*> & staticEntities = map.getStaticEntities();
	for(uint i = 0; i < staticEntities.size(); i++) {
		this->entityFactory.createBody(staticEntities[i]);
	}

	const std::vector<Entity*> & dynamicEntities = map.getDynamicEntities();
	for(uint i = 0; i < dynamicEntities.size(); i++) {
		this->entityFactory.createBody(dynamicEntities[i]);
	}
}

void World::createPlayer(PlayerEntity * player) {
	this->players.push_back(player);
	this->entityFactory.createBody(player);
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

const std::vector<Entity*> & World::getStaticEntities() const {
	return this->map.getStaticEntities();
}

// TODO change: entity slicing, not a problem?
std::vector<Entity> World::getDynamicEntities() const {
	const b2Body * body = this->world.GetBodyList();

	std::vector<Entity> entities;

	while(body != nullptr) {
		Entity * entityPtr = (Entity *) body->GetUserData();

		if(entityPtr->getType() >= DYNAMIC_ENTITY_START) {
			const b2Vec2 position = body->GetPosition();
			entityPtr->setX(position.x);
			entityPtr->setY(position.y);

			// TODO change. Copy entities, before passing them to the client: will no longer be necessary when using sockets
			entities.push_back(*entityPtr);
		}

		body = body->GetNext();
	}

	return entities;
}
