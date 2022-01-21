//
// Created by Myanna Jean Moody on 1/21/22.
//

#ifndef INC_236PROJECT1_0_FACTS_H
#define INC_236PROJECT1_0_FACTS_H
#include "Automaton.h"

class FactsAutomaton: public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
public:
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
};


#endif //INC_236PROJECT1_0_FACTS_H
