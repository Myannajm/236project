//
// Created by Myanna Jean Moody on 1/21/22.
//

#ifndef INC_236PROJECT1_0_UNDEFINED_H
#define INC_236PROJECT1_0_UNDEFINED_H
#include "Automaton.h"

class UndefinedAutomaton: public Automaton{
private:
    //FSA that sends to error state if the function closes correctly
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}
    void S0(const std::string& input);
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
};


#endif //INC_236PROJECT1_0_UNDEFINED_H
