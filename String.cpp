//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "String.h"
void StringAutomaton::S0(const std::string& input) {
    if(!input.empty()){
        if(input[index] == '\''){
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
    else{
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {
    if(!input.empty()){
        if(input[0] == '\''){
            inputRead++;
            index++;
            S2(input.substr(1));
        }
        else{
            if (input[0] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
    else{
        Serr();
    }
}
void StringAutomaton::S2(const std::string& input){
    if(!input.empty()){
        if(input[0] == '\''){
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
    else{
        inputRead++;
    }
}
