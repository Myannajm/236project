//
// Created by Myanna Jean Moody on 2/4/22.
//

#ifndef INC_236PROJECT1_0_ENDOF_H
#define INC_236PROJECT1_0_ENDOF_H
#include "Automaton.h"
#include <fstream>
#include <iostream>
#include <cctype>

class endAutomaton: public Automaton {
public:
    endAutomaton() : Automaton(TokenType::EOF_TYPE){}
    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
    void S0(const std::string& input){
        if (input[index+1] ==  EOF) {
            std::cout << "here!" << std::endl;
            inputRead = 1;
            newLines++;
        }
        else {
            Serr();
        }
    }
};

#endif //INC_236PROJECT1_0_ENDOF_H
