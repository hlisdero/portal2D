#include "server/physics/world.h"

#include "server/physics/portal_ray_cast_callback.h"

// Initialize the world with the gravity vector
World::World(Map& map, GameEventCreator & gameEventCreator) :
	world(b2Vec2(0.0f, GRAVITY)),
	bodyFactory(world),
	gameEventCreator(gameEventCreator),
	playerSpawn(map.getSpawn()) {
	world.SetContactListener(&contactListener);

	const std::vector<Entity*> & staticEntities = map.getStaticEntities();
	for(uint i = 0; i < staticEntities.size(); i++) {
		bodyFactory.createBody(staticEntities[i]);
	}

	dynamicEntities = map.getDynamicEntities();
	for(uint i = 0; i < dynamicEntities.size(); i++) {
		bodyFactory.createBody(dynamicEntities[i]);
	}
}

World::~World() {
	for(auto& player : players) {
		delete player.second;
	}
}

PlayerEntity * World::createPlayer() {
	PlayerEntity * newPlayer = new PlayerEntity(playerSpawn, gameEventCreator);
	bodyFactory.createBody(newPlayer);

	players[newPlayer->getId()] = newPlayer;

	return newPlayer;
}

PlayerEntity * World::getPlayerById(size_t playerId) {
	return players.at(playerId);
}

void World::killPlayer(PlayerEntity * player) {
	players.erase(player->getId());
	delete player;
	world.DestroyBody(player->getBody());
}

void World::createPortal(PlayerEntity * player, ClickDirection& direction, EventCreator & eventCreator) {
	// TODO remove
    portal_color = !portal_color;
    PortalColor color = portal_color ? COLOR_BLUE: COLOR_ORANGE;

    b2Vec2 dir_vec(direction.x, direction.y);
	const b2Vec2 & origin = player->getBody()->GetPosition();
	b2Vec2 end = origin + (PORTAL_REACH * dir_vec);

	PortalRayCastCallback callback;

	world.RayCast(&callback, origin, end);

	if(callback.hit) {
		// TODO check if possible to create a portal

		// create a portal

		PortalEntity * portal = player->getPortal(color);
		if(portal != nullptr) {
			portal->move(callback.m_point.x, callback.m_point.y, callback.m_normal);
			eventCreator.addPositionUpdate(portal);
		} else {
			portal = new PortalEntity(callback.m_point.x, callback.m_point.y, callback.m_normal, color);


			bodyFactory.createBody(portal);
			player->setPortal(color, portal);

			eventCreator.addEntityCreation(portal);
		}

	}
}

void World::updatePhysics() {
	for(auto& player : players) {
		player.second->applyMovement();
	}

	// TODO change to constantes
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	world.Step(timeStep, velocityIterations, positionIterations);
}

void World::updateDynamics() {
	const b2Body * body = world.GetBodyList();

	dynamicEntities.clear();

	while(body != nullptr) {
		Entity * entity = (Entity *) body->GetUserData();

		if(entity->getType() >= DYNAMIC_ENTITY_START) {
			b2Vec2 position = body->GetPosition();

			// Set grabed rock to holder position 
			if(entity->getType() == TYPE_ROCK) {
				PlayerEntity* rockHolder = entity->as<RockEntity>()->getHolder();
				if(rockHolder != nullptr) {
					position = rockHolder->getBody()->GetPosition();
				}
			}

			entity->setX(position.x);
			entity->setY(position.y);

			dynamicEntities.push_back(entity);
		}

		body = body->GetNext();
	}
}

const std::vector<Entity*>& World::getDynamicEntities() const {
	return dynamicEntities;
}

size_t World::getPlayersCount() {
	return players.size();
}

b2World & World::getb2World() {
	return world;
}