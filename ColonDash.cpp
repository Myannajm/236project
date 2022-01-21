//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "ColonDash.h"
void ColonDashAutomaton::S0(const std::string& input) {
    if (input[index] == ':') {
        inputRead = 1;
        index = 1;
        S1(input);
    }
    else {
        Serr();
    }
}

void ColonDashAutomaton::S1(const std::string& input) {
    if (input[index] == '-') {
        inputRead++;
    }
    else {
        Serr();
    }
}