#include "server/server_interface.h"

ServerInterface::ServerInterface() : 
	game(this->mapLoader, "../data/maps/map2.yaml") {
	this->game.addPlayer(&this->player);
}

void ServerInterface::movePlayer(const MoveDirection direction, const bool pressed) {
	if(pressed) {
		this->player.keyDown(direction);
	} else {
		this->player.keyUp(direction);
	}
}

void ServerInterface::createPortal(PlayerEntity & player, float angle, PortalColor color) {
	this->game.createPortal(player, angle, color);
}

void ServerInterface::update() {
	this->game.update();
}

const std::vector<Entity*> & ServerInterface::getStaticEntities() const {
	return this->game.getStaticEntities();
}

const std::vector<Entity*> ServerInterface::getDynamicEntities() const {
	return std::move(this->game.getDynamicEntities());
}
