#include "server/physics/world.h"

#include "common/entities/entities_settings.h"
#include "server/physics/portal_aabb_callback.h"
#include "server/objects/math.h"
#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

// Initialize the world with the gravity vector
World::World(Map& map, GameEventCreator & gameEventCreator) :
	world(b2Vec2(0.0f, SETTINGS.GRAVITY)),
	bodyFactory(world),
	gameEventCreator(gameEventCreator),
	playerSpawn(map.getSpawn()),
	emitterInterval(SETTINGS.ENERGY_EMITTER_INTERVAL) {
	world.SetContactListener(&contactListener);

	const std::vector<Entity*> & staticEntities = map.getStaticEntities();
	for(auto & staticEntity : staticEntities) {
		bodyFactory.createBody(staticEntity);

		if(staticEntity->getType() == TYPE_ENERGY_EMITTER) {
			energyEmitters.push_back(staticEntity->as<EnergyEmitterEntity>());
		}
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

	for(auto& energyBall : energyBalls) {
		delete energyBall;
	}
}

PlayerEntity * World::createPlayer() {
	PlayerEntity * newPlayer = new PlayerEntity(playerSpawn, gameEventCreator);
	bodyFactory.createBody(newPlayer);

	players[newPlayer->getId()] = newPlayer;

	return newPlayer;
}

PlayerEntity * World::getPlayerById(size_t playerId) {
	auto it = players.find(playerId);
	return (it == players.end()) ? nullptr : it->second;
}

void World::killPlayer(PlayerEntity * player) {
	players.erase(player->getId());
	deleteEntity(player);
}

void World::deleteEntity(BodyLinked * entity) {
	b2Body * body = entity->getBody();
	body->SetUserData(nullptr);
	world.DestroyBody(body);

	delete entity;
}

void World::destroyEntity(BodyLinked * entity) {
	if(dynamic_cast<Entity*>(entity)->getType() == TYPE_ENERGY_BALL) {
		energyBalls.remove(dynamic_cast<EnergyBallEntity*>(entity));
	}

	deleteEntity(entity);
}

bool World::isPortalPositionAllowed(PortalRayCastCallback & raycast) {
	double rotation = atan2(raycast.m_normal.y, raycast.m_normal.x);

	b2AABB aabb = bodyFactory.createPortalAABB(raycast.m_point, rotation);

	b2Vec2 edgeA(-1 * sin(rotation), cos(rotation));
	edgeA *= SETTINGS.PORTAL_SENSIBILITY * entitiesSettings[TYPE_PORTAL][HALF_HEIGHT];
	b2Vec2 edgeB = -1 * edgeA;

	edgeA += raycast.m_point;
	edgeB += raycast.m_point;

	PortalAABBCallback creationQuery(edgeA, edgeB, raycast.m_normal, raycast.entity);
	world.QueryAABB(&creationQuery, aabb);

	return creationQuery.isOk();
}

bool World::isPortalAllowed(PortalRayCastCallback & raycast) {
	if(raycast.entity->getType() != TYPE_METAL_BLOCK &&
			raycast.entity->getType() != TYPE_METAL_DIAG_BLOCK) {
		return false;
	}

	if(!isPortalPositionAllowed(raycast)) {
		// Try with assisted center
		Math::toEdgeMiddle(raycast.m_point, raycast.m_normal);

		return isPortalPositionAllowed(raycast);
	}

	return true;
}

void World::createPortal(PlayerEntity * player, PortalColor color, 
	ClickDirection& direction, EventCreator & eventCreator) {

    b2Vec2 dir_vec(direction.x, direction.y);
	const b2Vec2 & origin = player->getBody()->GetPosition();
	b2Vec2 end = origin + (SETTINGS.PORTAL_REACH * dir_vec);

	PortalRayCastCallback callback;

	world.RayCast(&callback, origin, end);

	if(callback.hit && isPortalAllowed(callback)) {
		// create a portal
		PortalEntity * portal = player->getPortal(color);
		if(portal != nullptr) {
			eventCreator.addEntityDestruction(portal);
			portal->move(callback.m_point.x, callback.m_point.y, callback.m_normal);
			eventCreator.addPortalCreation(portal);
		} else {
			portal = new PortalEntity(callback.m_point.x, callback.m_point.y, callback.m_normal, color);


			bodyFactory.createBody(portal);
			player->setPortal(color, portal);

			eventCreator.addPortalCreation(portal);
		}
	} else {
		// TODO send "error" to client
	}
}

void World::createPinTool(PlayerEntity * player, ClickDirection& direction, EventCreator & eventCreator) {
    b2Vec2 dir_vec(direction.x, direction.y);
	const b2Vec2 & origin = player->getBody()->GetPosition();
	b2Vec2 end = origin + (SETTINGS.PORTAL_REACH * dir_vec);

	PortalRayCastCallback callback;

	world.RayCast(&callback, origin, end);

	if(callback.hit) {
		callback.m_point -= entitiesSettings[TYPE_PIN_TOOL][X_OFFSET]*callback.m_normal;
		eventCreator.addPinToolCreation(callback.m_point, Math::getRotationDegFromNormal(callback.m_normal));
	}
}

void World::emitEnergyBalls(EventCreator & eventCreator, std::chrono::system_clock::time_point & now) {
	if(nextEmit > now) {
		return;
	}

	for(auto & energyEmitter : energyEmitters) {
		if(!energyEmitter->hasABall()) {
			EnergyBallEntity * entity = energyEmitter->emit(gameEventCreator);
			bodyFactory.createBody(entity);
			eventCreator.addEntityCreation(entity);
			energyBalls.push_back(entity);
		}
	}
	nextEmit = now + emitterInterval;
}

void World::destroyEnergyBalls(EventCreator & eventCreator, std::chrono::system_clock::time_point & now) {
	while(!energyBalls.empty() && energyBalls.front()->getDeathTP() < now) {
		eventCreator.addEntityDestruction(energyBalls.front());
		deleteEntity(energyBalls.front());
		energyBalls.pop_front();
	}
}

void World::updatePhysics(EventCreator & eventCreator) {
	for(auto& player : players) {
		player.second->applyMovement();
	}

	auto now = std::chrono::system_clock::now();
	emitEnergyBalls(eventCreator, now);
	destroyEnergyBalls(eventCreator, now);

	world.Step(SETTINGS.TIME_STEP, SETTINGS.VELOCITY_ITERATIONS, SETTINGS.POSITION_ITERATIONS);
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
				} else {
					entity->setRotationRad(body->GetAngle());
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