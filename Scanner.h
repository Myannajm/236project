//
// Created by Myanna Jean Moody on 1/15/22.
//

#ifndef INC_236PROJECT1_0_SCANNER_H
#define INC_236PROJECT1_0_SCANNER_H
#pragma once
#include <string>
#include <cctype>
#include <vector>
#include "Token.h"
#include "Automaton.h"

class Scanner {
private:
    std::vector<Token*> tokens;
    std::vector<Automaton*> automata;
    unsigned int line_num;
    void CreateAutomata();

public:
    Scanner();
    ~Scanner();


    void Run(std::string& input);
    std::string toString() const;

};

#endif //INC_236PROJECT1_0_SCANNER_H
