#ifndef DOOR_LOGICA_H
#define DOOR_LOGICA_H

#include <string>
#include <memory>

class DoorLogica;
typedef std::unique_ptr<DoorLogica> DoorLogicaPtr;

#include "server/entities/attributes/with_subscribable_state.h"

class DoorLogica {
public:
	virtual bool value() const = 0;
	virtual void attach(DoorEntity * door, subscribablesMap & subscribables) = 0;
};

class Value_DL : public DoorLogica {
public:
	explicit Value_DL(YAML::Node yaml);

	virtual bool value() const override;
	virtual void attach(DoorEntity * door, subscribablesMap & subscribables) override;

private:
	std::string subscribableName;
	WithSubscribableState * subscribable;
};

class Double_DL : public DoorLogica {
public:
	Double_DL(YAML::Node yaml);

	virtual bool value() const = 0;
	virtual void attach(DoorEntity * door, subscribablesMap & subscribables) override;

protected:
	DoorLogicaPtr logicaA;
	DoorLogicaPtr logicaB;
};

class Or_DL : public Double_DL {
public:
	using Double_DL::Double_DL; // inherit constructor

	virtual bool value() const override;
};

class And_DL : public Double_DL {
public:
	using Double_DL::Double_DL; // inherit constructor

	virtual bool value() const override;
};

class Not_DL : public DoorLogica {
public:
	explicit Not_DL(YAML::Node yaml );

	virtual bool value() const override;
	virtual void attach(DoorEntity * door, subscribablesMap & subscribables) override;

private:
	DoorLogicaPtr logica;
};

DoorLogicaPtr loadDoorLogica(YAML::Node yaml);

#endif  // DOOR_LOGICA_H