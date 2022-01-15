//
// Created by Myanna Jean Moody on 1/12/22.
//

#ifndef INC_236PROJECT1_0_TOKEN_H
#define INC_236PROJECT1_0_TOKEN_H
//could also use #pragma once for ^^
#pragma once
#include <string>
#include <sstream>


enum TokenType {
    COMMA, ID, STRING
};
class Token {
private:
    TokenType type;
    std::string value;
    int line;

public:
    Token(TokenType type, std::string value, int line)
    :type(type), value(value), line(line)
    {}
    std::string typeName(TokenType type) const {
        switch (type){
            case COMMA: return "COMMA";
            case ID: return "ID";
            case STRING: return "STRING";
        }
        return "ERROR";
    }
    std::string toString() const{
        std::stringstream out;
        out << "("<< typeName(type) <<",\"" << value << "\"," << line << ")";
        return out.str();
    }
};


#endif //INC_236PROJECT1_0_TOKEN_H
