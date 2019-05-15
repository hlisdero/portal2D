#ifndef STATIC_SCENE_H
#define STATIC_SCENE_H

#include <string>
#include <vector>

#include "static_element.h"

class StaticScene {
public:
	StaticScene(const char * filename);

	void save(const char * filename);

private:
	std::string name;
	uint minPlayers;
	std::vector<StaticElement> elements;
};

#endif  // STATIC_SCENE_H
