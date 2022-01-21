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

class Scanner {
private:
    std::vector<Token*> tokens;
    std::string input;
    int line = 1;
public:
    Scanner(const std::string& input) : input(input){}
    ~Scanner() {
        while (!tokens.empty()) {
            tokens.pop_back();
        }
    }

    void scanToken(){
        TokenType type;
        int size;
        while(input.length() > 0){
            while (isspace(input.at(0))){
                if(input.at(0) == '\n'){
                    line += 1;
                }
                input = input.substr(1);
            }
            switch(input.at(0)){
                case ',':
                    type = COMMA;
                    size = 1;
                    break;
            }
            std::string value = input.substr(0, size);
            Token* newToken = new Token(type, value, line);
            tokens.push_back(newToken);

            input = input.substr(size);
        }
    }

    std::string toString() const{
        std::string printMe = "";
        for(unsigned int m = 0; m < tokens.size(); ++m){
            printMe += tokens.at(m)->toString() + "\n";
        }
        return printMe;
    }
};

#endif //INC_236PROJECT1_0_SCANNER_H
