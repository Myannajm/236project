//
// Created by Myanna Jean Moody on 1/15/22.
//

#ifndef INC_236PROJECT1_0_SINGLECHAR_H
#define INC_236PROJECT1_0_SINGLECHAR_H
#pragma once
#include "Token.h"

class singleChar : public Automaton{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA){}
    PeriodAutomaton() : Automaton(TokenType::PERIOD){}
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK){}
    LeftAutomaton() : Automaton(TokenType::LEFT_PAREN){}
    RightAutomaton() : Automaton(TokenType::RIGHT_PAREN){}
    ColonAutomaton() : Automaton(TokenType::COLON){}
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY){}
    AddAutomaton() : Automaton(TokenType::ADD){}

    unsigned int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }
    void S0(const std::string& input){
        switch(input.at(0)){
            case ',':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case '.':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case '?':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case '(':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case ')':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case ':':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case '*':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            case '+':
                type = COMMA;
                size = 1;
                inputRead = 1;
                break;
            default:
                Serr();

    }
};
#endif //INC_236PROJECT1_0_SINGLECHAR_H
