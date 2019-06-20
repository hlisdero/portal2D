#ifndef GATE_LOGIC_H
#define GATE_LOGIC_H

#include <string>
#include <memory>

class GateLogica;
typedef std::unique_ptr<GateLogica> GateLogicaPtr;

#include "server/entities/attributes/with_subscribable_state.h"

class GateLogica {
public:
	virtual bool value() const = 0;
	virtual void attach(GateEntity * gate, subscribablesMap & subscribables) = 0;

	virtual ~GateLogica() = default;
};

class Value_DL : public GateLogica {
public:
	explicit Value_DL(const YAML::Node & yaml);

	virtual bool value() const override;
	virtual void attach(GateEntity * gate, subscribablesMap & subscribables) override;

private:
	std::string subscribableName;
	WithSubscribableState * subscribable;
};

class Double_DL : public GateLogica {
public:
	Double_DL(const YAML::Node & yaml);

	virtual bool value() const = 0;
	virtual void attach(GateEntity * gate, subscribablesMap & subscribables) override;

protected:
	GateLogicaPtr logicaA;
	GateLogicaPtr logicaB;
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

class Not_DL : public GateLogica {
public:
	explicit Not_DL(const YAML::Node & yaml );

	virtual bool value() const override;
	virtual void attach(GateEntity * gate, subscribablesMap & subscribables) override;

private:
	GateLogicaPtr logica;
};

GateLogicaPtr loadGateLogica(const YAML::Node & yaml);

#endif  // GATE_LOGIC_H
