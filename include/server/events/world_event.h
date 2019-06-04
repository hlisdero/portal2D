#ifndef WORLD_EVENT_H
#ifndef WORLD_EVENT_H

enum WorldEventType {
	DYNAMICS_UPDATE,
	DOOR_UPDATED,
	BUTTON_UPDATED,
	ENTITY_DESTROYED,
	PORTAL_CREATED,
	PORTAL_MOVED,
	PORTALS_RESET
}

class WorldEvent {
public:
	WorldEvent(WorldEventType type) = default;

private:
	WorldEventType type;
}

#endif

/*

updateDynamics: dynamicsUpdated
	entities(id, pos)
updateDoor: doorUpdated
	id, state
updateButton: buttonUpdated
	id, state
destroyEntity: entityDestroyed
	id
(respawnRock)
createPortal: portalCreated
	id, position, color
movePortal
	id, pos
resetPortal
	id1, id2
win/lose

*/