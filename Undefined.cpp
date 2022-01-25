//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "Undefined.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[0] == '\'') {
        inputRead++;
        index++;
        S1(input.substr(1));
    }
    else if (input[index] == '#') {
        if (input.length() > 1 && input[index + 1] == '|') {
            index += 2;
            inputRead += 2;
            S3(input);
        }
    }
    else {
        Serr();
    }
}
void UndefinedAutomaton::S1(const std::string& input) {
    if(!input.empty()){
        if(input[0] == '\''){
            inputRead++;
            index++;
            S2(input.substr(1));
        }
        else{
            if(input[0] == '\n'){
                newLines++;
            }
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }

}
void UndefinedAutomaton::S2(const std::string& input){
    if(!input.empty()){
        if(input[0] == '\''){
            index++;
            inputRead++;
            S1(input.substr(1));
        }
        else{
            Serr();
        }
    }
}
//fix multiline commment fail (not needed for this project)
void UndefinedAutomaton::S3(const std::string &input) {
    while (input[index] != '|' && input[index] != EOF) {
        if(input[index] == '\n'){
            newLines +=1;
        }
        inputRead++;
        index++;
    }
    if (input[index] == '|'&& input[index + 1] == '#') {
        Serr();
    }
    else{
        inputRead++;
    }
}