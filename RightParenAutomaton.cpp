//
// Created by Myanna Jean Moody on 9/13/21.
//

#include "RightParenAutomaton.h"
void RightParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}