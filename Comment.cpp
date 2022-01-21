//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "Comment.h"
//
// Created by Myanna Jean Moody on 9/13/21.
//
void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#'){
        if(input.length() > 1 && input[index+1] == '|'){
            index += 2;
            inputRead += 2;
            S2(input);
        }
        else{
            S1(input);
        }
    }
    else {
        Serr();
    }
}
void CommentAutomaton::S1(const std::string& input) {
    while(input[index] != '\n' && input[index] != EOF){
        inputRead++;
        index++;
    }
    if(input[index] == '\n' || input[index] == EOF){
        inputRead++;
    }
    else {
        Serr();
    }
}
void CommentAutomaton::S2(const std::string& input) {
    while (input[index] != '|' && input[index] != EOF) {
        if(input[index] == '\n'){
            newLines +=1;
        }
        inputRead++;
        index++;
    }
    if (input[index] == '|'&& input[index + 1] == '#') {
        inputRead+=2;
    }
    else {
        Serr();
    }
}



