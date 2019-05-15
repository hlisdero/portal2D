#include "static_scene.hpp"
#include "yaml-cpp/yaml.h"

StaticScene::StaticScene(const char * filename) {
	YAML::Node file = YAML::LoadFile(filename);

	this->name = file["name"].as<std::string>();
	this->minPlayers = file["min-players"].as<uint>();

	for(uint i = 0; i < file["elements"].size(); i++) {
		StaticElement element;
		switch(file["elements"][i]["type"]) {
			case StoneBlock:
				element = StoneBlock(file["elements"][i]);
				break;
			case MetalBlock:
				element = MetalBlock(file["elements"][i]);
				break;
			case MetalDiagBlock:
				element = MetalDiagBlock(file["elements"][i]);
				break;
			case Acid:
				element = Acid(file["elements"][i]);
				break;
			case Door:
				element = Door(file["elements"][i]);
				break;
			case EnergyBar:
				element = EnergyBar(file["elements"][i]);
				break;
			case EnergyEmittor:
				element = EnergyEmittor(file["elements"][i]);
				break;
			case EnergyReceiver:
				element = EnergyReceiver(file["elements"][i]);
				break;
			case PlayerSpawn:
				element = PlayerSpawn(file["elements"][i]);
				break;
			case EndCake:
				element = EndCake(file["elements"][i]);
				break;
			case Button:
				element = Button(file["elements"][i]);
				break;
			default:
				throw std::runtime_exception("Element type not recognized.");
		}

		this->elements.push_back(element);
	}
}