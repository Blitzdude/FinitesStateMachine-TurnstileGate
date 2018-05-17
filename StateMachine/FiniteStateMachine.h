#pragma once
#include "States.h"
class AbstractState;
class FiniteStateMachine
{
public:
    FiniteStateMachine() {};
    FiniteStateMachine(bool b);
    ~FiniteStateMachine();
    friend class AbstractState;
public:
    void coin  ();
    void pass  ();
    void ready ();
    void reset ();

    bool getCurrentAlarm();
    void setAlarm(bool b);
private:
    bool m_alarm;
    AbstractState* mState;
};

