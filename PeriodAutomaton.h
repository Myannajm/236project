//
// Created by Myanna Jean Moody on 9/13/21.
//

#ifndef INC_236PROJECT1_PERIODAUTOMATON_H
#define INC_236PROJECT1_PERIODAUTOMATON_H

#include "Automaton.h"
class PeriodAutomaton: public Automaton {
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor
    void S0(const std::string& input);
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
};


#endif //INC_236PROJECT1_PERIODAUTOMATON_H
