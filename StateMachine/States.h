#pragma once

#include "FiniteStateMachine.h"
#include <exception>
#include <stdexcept>

class FiniteStateMachine;


class AbstractState {
public:
    virtual void coin(FiniteStateMachine& machine) = 0;
    virtual void pass(FiniteStateMachine& machine) = 0;
    virtual void ready(FiniteStateMachine& machine) = 0;
    virtual void reset(FiniteStateMachine& machine) = 0;

    virtual ~AbstractState();
protected:
    void setState(FiniteStateMachine& machine, AbstractState* st);
};

class Locked : public AbstractState {
public:
    virtual void coin(FiniteStateMachine& machine)  override;
    virtual void pass(FiniteStateMachine& machine)  override;
    virtual void ready(FiniteStateMachine& machine) override;
    virtual void reset(FiniteStateMachine& machine) override;


    virtual ~Locked() {};
};

class Unlocked : public AbstractState {
public:
    virtual void coin(FiniteStateMachine& machine)  override;
    virtual void pass(FiniteStateMachine& machine)  override;
    virtual void ready(FiniteStateMachine& machine) override;
    virtual void reset(FiniteStateMachine& machine) override;

    virtual ~Unlocked() {};
};

class Violation : public AbstractState {
public:
    virtual void coin(FiniteStateMachine& machine)  override;
    virtual void pass(FiniteStateMachine& machine)  override;
    virtual void ready(FiniteStateMachine& machine) override;
    virtual void reset(FiniteStateMachine& machine) override;

    virtual ~Violation() {};
};