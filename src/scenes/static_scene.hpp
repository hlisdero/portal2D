#ifndef STATIC_SCENE_HPP
#define STATIC_SCENE_HPP

#include <string>
#include <vector>

#include "static_element.hpp"

class StaticScene {
public:
	StaticScene(const char * filename);
	
	void save(const char * filename);

private:
	std::string name;
	uint minPlayers;
	std::vector<StaticElement> elements;
};

#endif  // STATIC_SCENE_HPP
