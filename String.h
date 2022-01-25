//
// Created by Myanna Jean Moody on 1/21/22.
//

#ifndef INC_236PROJECT1_0_STRING_H
#define INC_236PROJECT1_0_STRING_H
#include "Automaton.h"

class StringAutomaton:public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
    void S0(const std::string& input);
};


#endif //INC_236PROJECT1_0_STRING_H
