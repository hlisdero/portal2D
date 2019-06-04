#ifndef ENTITY_POSITION_H
#define ENTITY_POSITION_H

class EntityPosition {
public:
	EntityPosition(int id, float x, float y, float rotation);

	int id;
	float x;
	float y;
	float rotation;
};

#endif