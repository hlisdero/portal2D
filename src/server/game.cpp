#include "server/game.h"

Game::Game(const char* mapName, EventCreator& eventCreator) :
	gameEventCreator(eventsQueue),
	map(mapName, gameEventCreator),
	world(map, eventCreator),
	eventCreator(eventCreator) {}

void Game::addPlayer(PlayerEntity* player) {
	world.createPlayer(player);

	// TODO Check in progress (enough player to play)
	if(status == WAITING_FOR_PLAYERS
		&& world.getPlayersCount() >= map.getMinPlayers()) {
		status = IN_PROGRESS;
	}
}

void Game::createPortal(PlayerEntity& player, ClickDirection& direction) {
	world.createPortal(player, direction);
}

void Game::update() {
	// Check victory
	if(map.getEndZone().getNumberOfPlayersInZone()
		>= map.getMinPlayers() - 1) {
		status = VICTORY;
	}
	// TODO Check defeat

	world.updatePhysics();

	processGameEvents();
}

const std::vector<Entity*>& Game::getStaticEntities() const {
	return map.getStaticEntities();
}

const std::vector<Entity*>& Game::getDynamicEntities() const {
	return world.getDynamicEntities();
}

void Game::processGameEvents() {
	std::vector<GameEvent> events = eventsQueue.popAll();
	for(GameEvent event : events) {
		switch(event.type) {
			case ENTITY_STATE_UPDATE:
				eventCreator.addStateUpdate(event.entity);
				break;
			case ENTITY_SET_ACTIVE:
				event.entity->as<BodyLinked>()->getBody()->SetActive(event.active);
				break;
			default:
				throw std::runtime_error("Unsupported game event type");
		}
	}

	eventCreator.addPositionUpdates(world.getDynamicEntities());

	// if player join
	//	createPlayer
	// if playerCount > map.getRequiredPlayersCount(): status= In progress

	// if player move
	//	move player
}
