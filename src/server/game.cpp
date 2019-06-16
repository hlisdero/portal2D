#include "server/game.h"

#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

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

	for (size_t i = 0; i < getMinPlayers(); ++i) {
		client_manager.addSelectPlayer(i, createPlayer());
	}
}

void Game::run() {
	ClockLoop<LOOPS_PER_SECOND> clock;
	while (!quit) {
		client_manager.joinInputQueues();
		processQueue();
		update();
		client_manager.broadcast();
		clock.waitNextLoop();
	}
}

void Game::update() {
	// Update contacts => generate events
	world.updatePhysics(event_creator);
	// With events, do things => change position, state,...
	processGameEvents();

	// With new position, update entity position
	world.updateDynamics();
	// Then, send the new positions
	event_creator.addPositionUpdates(world.getDynamicEntities());
}

void Game::processGameEvents() {
	std::vector<GameEvent> events = eventsQueue.popAll();
	for (const GameEvent& event : events) {
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
			case POTENTIAL_VICTORY:
				if(world.getPlayersCount() == event.playerCount) {
					gameEventCreator.addGameStateChange(VICTORY);
				}
				break;
			case GAME_STATUS_CHANGE:
				// TODO use status
				quit = true;
				event_creator.addEndGame();
				break;
			case KILL_PLAYER:
				event.entity->as<PlayerEntity>()->resetPortals(world.getb2World(), event_creator);
				event_creator.addEntityDestruction(event.entity);
				world.killPlayer(event.entity->as<PlayerEntity>());

				if(world.getPlayersCount() == 0 ||
					world.getPlayersCount() < map.getMinPlayers() - 1) {
					gameEventCreator.addGameStateChange(DEFEAT);
				}
				// TODO notify client
				// event_creator.addEntityDestruction(event.entity);
				break;
			case ENERGY_BALL_DESTRUCTION:
				event_creator.addEntityDestruction(event.entity);
				world.destroyEntity(event.entity->as<BodyLinked>());
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

        if (!player) {
		    continue;
        }
		switch(event.type) {
		case MOVE:
			player->move(event.direction, event.pressed);
			break;
		case RESET_PORTALS:
			player->resetPortals(world.getb2World(), event_creator);
			break;
		case GRAB_RELEASE_ROCK:
			player->grabReleaseRock(world.getb2World());
			break;
		case PIN_TOOL:
			// TODO pin tool
			break;
		case MOUSE:
			world.createPortal(player, stateToPortalColor(event.state),
                               event.click_direction, event_creator);
			break;
		case QUIT:
			gameEventCreator.addKillPlayer(player);
			break;
		default:
			throw std::runtime_error("Unsupported view event type");
			break;
		}
	}
}

PortalColor Game::stateToPortalColor(const State& state) const {
    if (state == PORTAL_COLOR_ORANGE) {
        return COLOR_ORANGE;
    } else {
        return COLOR_BLUE;
    }
}
