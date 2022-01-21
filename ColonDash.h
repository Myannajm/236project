//
// Created by Myanna Jean Moody on 1/21/22.
//

#ifndef INC_236PROJECT1_0_COLONDASH_H
#define INC_236PROJECT1_0_COLONDASH_H
#include "Automaton.h"

class ColonDashAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    ColonDashAutomaton(): Automaton(TokenType::COLON_DASH) {}  // Call the base constructor
    void S0(const std::string& input);
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
};



#endif //INC_236PROJECT1_0_COLONDASH_H
