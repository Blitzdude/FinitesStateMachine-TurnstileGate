#include <iostream>
#include <stdexcept>
#include "FiniteStateMachine.h"
#include "States.h"

// https://stackoverflow.com/questions/14676709/c-code-for-state-machine << hyvä malli löyty täältä :)

int main() {
    FiniteStateMachine gate(false);
    bool run = true;

    int input = -1;

    std::cout << "Gate is Locked\n" << std::endl;
    while (run)
    {
        std::cout << "coin = 1, ready = 2, pass = 3, reset = 4, exit = 5\n>> ";
        std::cin >> input;

        switch (input)
        {
        case 1: // coin
            gate.coin();
            break;
        case 2: // ready
            gate.ready();
            break;
        case 3: // pass
            gate.pass();
            break;
        case 4: // reset
            gate.reset();
            break;
        case 5: // exit
            run = false;
            break;
        default:
            std::cout << "invalid input\n";
            break;
        }
    }

   
    return 0;
}