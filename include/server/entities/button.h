#ifndef BUTTON_ENTITY_H
#define BUTTON_ENTITY_H

#include <vector>
#include "Box2D/Box2D.h"

#include "server/entities/state_entity.h"

class ButtonEntity;

#include "server/entities/door.h"

class ButtonEntity : public StateEntity {
public:
	ButtonEntity(const float x, const float y);

	virtual void beginContactWith(MEntity * other, b2Contact * contact) override;
	virtual void endContactWith(MEntity * other, b2Contact * contact) override;

	void registerDoor(DoorEntity * door);
	void broadcastChange();
private:
	std::vector<DoorEntity*> doors;
};

#endif  // BUTTON_ENTITY_H