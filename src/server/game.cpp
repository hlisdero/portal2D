#include "server/game.h"

Game::Game(const std::string& map_name, ClientManager& client_manager) :
    world_events(client_manager.getSendQueue()),
    view_events(client_manager.getReceiveQueue()),
    client_manager(client_manager),
    event_creator(world_events),

	gameEventCreator(eventsQueue),
	map(map_name, gameEventCreator),
	world(map, gameEventCreator) {}

size_t Game::createPlayer() {
    PlayerEntity * player = world.createPlayer();

    event_creator.addEntityCreation(player);
    // Send immediately to every client but 
    // most importantly to the current client who need it to attach its camera
    client_manager.broadcast();

    return player->getId();
}

size_t Game::getMinPlayers() const {
    return map.getMinPlayers();
}

void Game::init() {
    event_creator.addEntityCreations(map.getStaticEntities());
    event_creator.addEntityCreations(world.getDynamicEntities());
    client_manager.broadcast();
}

void Game::run() {
    ClockLoop<60> clock;
    while (!quit) {
        client_manager.joinInputQueues();
        processQueue();
        update();
        client_manager.broadcast();
        clock.waitNextLoop();
    }
}

void Game::update() {
	// Check victory
	// TODO Check defeat

	// Update contacts => generate events
	world.updatePhysics();
	// With events, do things => change position, state,...
	processGameEvents();

	// With new position, update entity position
	world.updateDynamics();
	// Then, send the new positions
	event_creator.addPositionUpdates(world.getDynamicEntities());
}

void Game::processGameEvents() {
	std::vector<GameEvent> events = eventsQueue.popAll();
	for(GameEvent event : events) {
		switch(event.type) {
			case ENTITY_STATE_UPDATE:
				event_creator.addStateUpdate(event.entity);
				break;
			case ENTITY_SET_ACTIVE:
				event.entity->as<BodyLinked>()->getBody()->SetActive(event.active);
				break;
			case ENTITY_TELEPORT:
				event.entity->as<TeleportableEntity>()->teleport();
				break;
			case PORTALS_RESET:
				event.entity->as<PlayerEntity>()->resetPortals(world.getb2World(), event_creator);
				// TODO notify client
				break;
			case GAME_STATUS_CHANGE:
				// status = event.status;
				// TODO notify client
				break;
			case KILL_PLAYER:
				event_creator.addEntityDestruction(event.entity);
				world.killPlayer(event.entity->as<PlayerEntity>());

				if(world.getPlayersCount() < map.getMinPlayers()) {
					gameEventCreator.addGameStateChange(DEFEAT);
				}
				// TODO notify client
				break;
			default:
				throw std::runtime_error("Unsupported game event type");
		}
	}
}

void Game::processQueue() {
    while (!view_events.empty()) {
        ViewEvent event = view_events.front();
        view_events.pop();

        PlayerEntity * player = world.getPlayerById(event.player_id);

        if (event.type == KEYBOARD) {
            player->move(event.direction, event.pressed);
        } else if (event.type == MOUSE) {
            world.createPortal(player, event.click_direction, event_creator);
        } else if (event.type == QUIT) {
            quit = true;
        }
    }
}