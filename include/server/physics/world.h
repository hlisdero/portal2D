#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <chrono>
#include <list>

#include "Box2D/Box2D.h"

#include "server/entities/entity.h"
#include "common/objects/click_direction.h"
#include "server/map.h"
#include "server/entities/player.h"
#include "server/entities/utils/body_factory.h"
#include "server/events/event_creator.h"
#include "server/events/game_event_creator.h"
#include "server/physics/contact_listener.h"
#include "server/physics/portal_ray_cast_callback.h"

/*
	y
	^
	|
	|
	*------ > x
*/

class World {
public:
	explicit World(Map& map, GameEventCreator & gameEventCreator);

    PlayerEntity * createPlayer();
    PlayerEntity * getPlayerById(size_t id);

    void destroyEntity(BodyLinked * entity);

    void killPlayer(PlayerEntity* player);
    void createPortal(PlayerEntity* player, PortalColor color,
    	ClickDirection& direction, EventCreator& eventCreator);
	void createPinTool(PlayerEntity * player, ClickDirection& direction, 
		EventCreator & eventCreator);

    void updatePhysics(EventCreator & eventCreator);
    void updateDynamics();

	const std::vector<Entity*>& getDynamicEntities() const;

	size_t getPlayersCount();

	b2World & getb2World();

	~World();

private:
	b2World world;
	BodyFactory bodyFactory;
	GameEventCreator& gameEventCreator;

    const b2Vec2 & playerSpawn;
	std::map<size_t, PlayerEntity*> players;

	// TODO maybe update with methods instead of b2World.getEntities()
	std::vector<Entity*> dynamicEntities;

	std::vector<EnergyEmitterEntity*> energyEmitters;

	std::list<EnergyBallEntity*> energyBalls;

	std::chrono::system_clock::time_point nextEmit = std::chrono::system_clock::now();
	std::chrono::duration<int> emitterInterval;

	ContactListener contactListener;

	bool isPortalAllowed(PortalRayCastCallback & callback);
	bool isPortalPositionAllowed(PortalRayCastCallback & raycast);

	void deleteEntity(BodyLinked * entity);

	void destroyEnergyBalls(EventCreator & eventCreator, std::chrono::system_clock::time_point & now);
	void emitEnergyBalls(EventCreator & eventCreator, std::chrono::system_clock::time_point & now);
};

#endif  // WORLD_H
