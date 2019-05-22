#ifndef DOOR_LOGICA_H
#define DOOR_LOGICA_H

class DoorLogica;

#include "server/entities/button.h"

class DoorLogica {
public:
	virtual bool value() const = 0;
};

class Value_DL : public DoorLogica {
public:
	explicit Value_DL(ButtonEntity & button);

	virtual bool value() const override;
private:
	ButtonEntity & button;
};

class Or_DL : public DoorLogica {
public:
	Or_DL(DoorLogica & logicaA, DoorLogica & logicaB);

	virtual bool value() const override;

private:
	DoorLogica & logicaA;
	DoorLogica & logicaB;
};

class And_DL : public DoorLogica {
public:
	And_DL(DoorLogica & logicaA, DoorLogica & logicaB);

	virtual bool value() const override;

private:
	DoorLogica & logicaA;
	DoorLogica & logicaB;
};

class Not_DL : public DoorLogica {
public:
	explicit Not_DL(DoorLogica & logica);

	virtual bool value() const override;

private:
	DoorLogica & logica;
};

#endif  // DOOR_LOGICA_H