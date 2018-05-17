#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine(bool b) :
     m_alarm(b), mState(new Locked()) 
{
}

FiniteStateMachine::~FiniteStateMachine() {
    delete mState;
}

void FiniteStateMachine::coin()
{
    mState->coin(*this);
}

void FiniteStateMachine::pass()
{
    mState->pass(*this);

}

void FiniteStateMachine::ready()
{
    mState->ready(*this);

}

void FiniteStateMachine::reset()
{
    mState->reset(*this);

}

bool FiniteStateMachine::getCurrentAlarm()
{
    return m_alarm;
}

void FiniteStateMachine::setAlarm(bool b)
{
    m_alarm = b;
}

