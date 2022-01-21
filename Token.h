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
            case TokenType::COLON: return "COLON"; break;
            case TokenType::COLON_DASH: return "COLON_DASH"; break;
            case TokenType::COMMA: return "COMMA"; break;
            case TokenType::PERIOD: return "PERIOD"; break;
            case TokenType::Q_MARK: return "Q_MARK"; break;
            case TokenType::LEFT_PAREN: return "LEFT_PAREN"; break;
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN"; break;
            case TokenType::MULTIPLY: return "MULTIPLY"; break;
            case TokenType::ADD: return "ADD"; break;
            case TokenType::SCHEMES: return "SCHEMES"; break;
            case TokenType::FACTS: return "FACTS"; break;
            case TokenType::RULES: return "RULES"; break;
            case TokenType::QUERIES: return "QUERIES"; break;
            case TokenType::ID: return "ID"; break;
            case TokenType::STRING: return "STRING"; break;
            case TokenType::COMMENT: return "COMMENT"; break;
            case TokenType::EOF_TYPE: return "EOF"; break;
            case TokenType::UNDEFINED: return "UNDEFINED"; break;
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
