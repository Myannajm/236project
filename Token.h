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
    COLON, COLON_DASH, COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, MULTIPLY, ADD,
    SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, EOF_TYPE,
    UNDEFINED
};
class Token {
private:
    TokenType type;
    std::string value;
    unsigned int line;

public:
    Token(TokenType type, std::string value, int line)
    :type(type), value(value), line(line)
    {}


    std::string typeName(TokenType type) const {
        switch (type){
            case TokenType::COLON: return "COLON";
            case TokenType::COLON_DASH: return "COLON_DASH";
            case TokenType::COMMA: return "COMMA";
            case TokenType::PERIOD: return "PERIOD";
            case TokenType::Q_MARK: return "Q_MARK";
            case TokenType::LEFT_PAREN: return "LEFT_PAREN";
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
            case TokenType::MULTIPLY: return "MULTIPLY";
            case TokenType::ADD: return "ADD";
            case TokenType::SCHEMES: return "SCHEMES";
            case TokenType::FACTS: return "FACTS";
            case TokenType::RULES: return "RULES";
            case TokenType::QUERIES: return "QUERIES";
            case TokenType::ID: return "ID";
            case TokenType::STRING: return "STRING";
            case TokenType::COMMENT: return "COMMENT";
            case TokenType::EOF_TYPE: return "EOF";
            case TokenType::UNDEFINED: return "UNDEFINED";
        }
        return "ERROR";
    }

    TokenType getToken()const{
        return type;
    }
    std::string getValue() const{
        return value;
    }
    std::string getLine() const{
        return std::to_string(line);
    }
    std::string toString() const{
        std::stringstream out;
        out << "("<< typeName(type) <<",\"" << value << "\"," << line << ")";
        return out.str();
    }
};


#endif //INC_236PROJECT1_0_TOKEN_H
