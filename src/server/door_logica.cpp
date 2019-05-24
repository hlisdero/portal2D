#include "server/door_logica.h"

Value_DL::Value_DL(ButtonEntity & button) : button(button) {}

bool Value_DL::value() const {
	return this->button.getState();
}

Or_DL::Or_DL(DoorLogica & logicaA, DoorLogica & logicaB) : logicaA(logicaA), logicaB(logicaB) {}

bool Or_DL::value() const {
	return this->logicaA.value() || this->logicaB.value();
}

And_DL::And_DL(DoorLogica & logicaA, DoorLogica & logicaB) : logicaA(logicaA), logicaB(logicaB) {}

bool And_DL::value() const {
	return this->logicaA.value() && this->logicaB.value();
}

Not_DL::Not_DL(DoorLogica & logica) : logica(logica) {}

bool Not_DL::value() const {
	return !this->logica.value();
}
