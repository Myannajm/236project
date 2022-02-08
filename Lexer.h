//
// Created by Myanna Jean Moody on 1/15/22.
//

#ifndef INC_236PROJECT1_0_LEXER_H
#define INC_236PROJECT1_0_LEXER_H
#pragma once
#include <string>
#include <cctype>
#include <vector>
#include "Token.h"
#include "Automaton.h"

class Lexer {
private:

    std::vector<Automaton*> automata;
    unsigned int line_num;
    void CreateAutomata();

public:
    std::vector<Token> tokens;
    Lexer();
    ~Lexer();
    void Run(std::string& input);
    std::string toString() const;
    std::vector<Token> returnTokens(){return tokens;}

};

#endif //INC_236PROJECT1_0_LEXER_H
