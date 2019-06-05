#include "server/entities/utils/door_logica.h"

#include <string>

// Constructors
Value_DL::Value_DL(YAML::Node yaml) :
	subscribableName(yaml.as<std::string>()) {}

Double_DL::Double_DL(YAML::Node yaml) : 
	logicaA(loadDoorLogica(yaml["a"])), logicaB(loadDoorLogica(yaml["b"])) {}

Not_DL::Not_DL(YAML::Node yaml) : logica(loadDoorLogica(yaml)) {}

// Values
bool Value_DL::value() const {
	return this->subscribable->getState();
}

bool And_DL::value() const {
	return this->logicaA->value() && this->logicaB->value();
}

bool Or_DL::value() const {
	return this->logicaA->value() || this->logicaB->value();
}

bool Not_DL::value() const {
	return !this->logica->value();
}

// Attach
void Value_DL::attach(DoorEntity * door, subscribablesMap & subscribables) {
	try {
		this->subscribable = subscribables.at(this->subscribableName);
		this->subscribable->subscribe(door);
	} catch(...) {
		throw std::runtime_error("Impossible to attach door logica");
	}
}

void Double_DL::attach(DoorEntity * door, subscribablesMap & subscribables) {
	this->logicaA->attach(door, subscribables);
	this->logicaB->attach(door, subscribables);
}

void Not_DL::attach(DoorEntity * door, subscribablesMap & subscribables) {
	this->logica->attach(door, subscribables);
}

// Load
DoorLogicaPtr loadDoorLogica(YAML::Node yaml) {
	DoorLogica * logica;

	if(yaml["value"]) {
		logica = new Value_DL(yaml["value"]);
	} else if(yaml["and"]) {
		logica = new And_DL(yaml["and"]);
	} else if(yaml["or"]) {
		logica = new Or_DL(yaml["or"]);
	} else if(yaml["not"]) {
		logica = new Not_DL(yaml["not"]);
	} else {
		throw std::runtime_error("Unsupported door logica type");
	}

	return DoorLogicaPtr(logica);
}