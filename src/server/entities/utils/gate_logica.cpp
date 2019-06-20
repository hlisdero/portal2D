#include "server/entities/utils/gate_logica.h"

#include <string>

// Constructors
Value_DL::Value_DL(const YAML::Node & yaml) :
	subscribableName(yaml.as<std::string>()) {}

Double_DL::Double_DL(const YAML::Node & yaml) : 
	logicaA(loadGateLogica(yaml["a"])), logicaB(loadGateLogica(yaml["b"])) {}

Not_DL::Not_DL(const YAML::Node & yaml) : logica(loadGateLogica(yaml)) {}

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
void Value_DL::attach(GateEntity * gate, subscribablesMap & subscribables) {
	try {
		this->subscribable = subscribables.at(this->subscribableName);
		this->subscribable->subscribe(gate);
	} catch(...) {
		throw std::runtime_error("Impossible to attach gate logica");
	}
}

void Double_DL::attach(GateEntity * gate, subscribablesMap & subscribables) {
	this->logicaA->attach(gate, subscribables);
	this->logicaB->attach(gate, subscribables);
}

void Not_DL::attach(GateEntity * gate, subscribablesMap & subscribables) {
	this->logica->attach(gate, subscribables);
}

// Load
GateLogicaPtr loadGateLogica(const YAML::Node & yaml) {
	GateLogica * logica;

	if(yaml["value"]) {
		logica = new Value_DL(yaml["value"]);
	} else if(yaml["and"]) {
		logica = new And_DL(yaml["and"]);
	} else if(yaml["or"]) {
		logica = new Or_DL(yaml["or"]);
	} else if(yaml["not"]) {
		logica = new Not_DL(yaml["not"]);
	} else {
		throw std::runtime_error("Unsupported gate logica type");
	}

	return std::move(GateLogicaPtr(logica));
}