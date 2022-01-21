//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "ID.h"
void IDAutomaton::S0(const std::string& input) {
    if(isalpha(input[index])){
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}
void IDAutomaton::S1(const std::string &input) {
    while(isalpha(input[index]) || isalnum(input[index])){
        inputRead++;
        index++;
    }
}