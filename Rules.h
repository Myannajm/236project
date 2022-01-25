//
// Created by Myanna Jean Moody on 1/21/22.
//

#ifndef INC_236PROJECT1_0_RULES_H
#define INC_236PROJECT1_0_RULES_H
#include "Automaton.h"

class RulesAutomaton: public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
    void S0(const std::string& input);
};


#endif //INC_236PROJECT1_0_RULES_H
