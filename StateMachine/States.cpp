#include "States.h"
#include <iostream>



AbstractState::~AbstractState() {
}

void AbstractState::setState(FiniteStateMachine& machine, AbstractState* state) {
    AbstractState* aux = machine.mState;
    machine.mState = state;
    delete aux;
}


// LOCKED ////////////////////////////////////

void Locked::coin(FiniteStateMachine & machine)
{
    std::cout << "Gate opened" << std::endl;
    setState(machine, new Unlocked());
}

void Locked::pass(FiniteStateMachine & machine)
{
    std::cout << "Alarm: Unauthorized entry detected" << std::endl;
    machine.setAlarm(true);
    setState(machine, new Violation());
}

void Locked::ready(FiniteStateMachine & machine)
{
    std::cout << "State : Locked" << std::endl;
}

void Locked::reset(FiniteStateMachine & machine)
{
    std::cout << "State : Locked" << std::endl;
}

// UNLOCKED ////////////////////////////////////
void Unlocked::coin(FiniteStateMachine & machine)
{
    std::cout << "Thank you for your donation" << std::endl;
}

void Unlocked::pass(FiniteStateMachine & machine)
{
    std::cout << "Locking gate" << std::endl;
    setState(machine, new Locked());
}

void Unlocked::ready(FiniteStateMachine & machine)
{
    std::cout << "State : Unlocked" << std::endl;
}

void Unlocked::reset(FiniteStateMachine & machine)
{
    std::cout << "State : Unlocked" << std::endl;
}

// VIOLATION ////////////////////////////////////

void Violation::coin(FiniteStateMachine & machine)
{
    std::cout << "State : Violation" << std::endl;

}

void Violation::pass(FiniteStateMachine & machine)
{
    std::cout << "State : Violation" << std::endl;

}

void Violation::ready(FiniteStateMachine & machine)
{
    if (machine.getCurrentAlarm() == false)
    {
        std::cout << "Returning to normal operation" << std::endl;
        setState(machine, new Locked());
    }
    else
    {
        std::cout << "Please turn of alarm before readying gate" << std::endl;
    }
}

void Violation::reset(FiniteStateMachine & machine)
{
    std::cout << "Alarm reseted" << std::endl;
    machine.setAlarm(false);
}
