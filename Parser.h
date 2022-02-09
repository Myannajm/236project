//
// Created by Myanna Jean Moody on 1/29/22.
//

#ifndef INC_236PROJECT1_0_PARSER_H
#define INC_236PROJECT1_0_PARSER_H
#include <vector>
#include "Token.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include "DatalogProgram.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Parser {
private:
    std::vector<Token> tokens;
    unsigned int index = 0;
protected:
    std::set<std::string> domain;

public:
    Parser(const std::vector<Token>& tokens): tokens(tokens){}
    ~Parser();
    TokenType tokenType() const;
    void advanceToken();
    void throwError();
    std::string match(TokenType t);
    void parseIdList(Predicate& p);
    Predicate parseScheme();
    Predicate parseFact();
    Rule parseRule();
    Predicate parseQuery();
    void parseSchemeList(vector<Predicate>& scheme);
    void parseFactList(vector<Predicate>& fact);
    void parseRuleList(vector<Rule>& rule);
    void parseQueryList(vector<Predicate>& query);
    Predicate parseHeadPredicate();
    Predicate parsePredicate();
    void parsePredList(std::vector<Predicate>& body);
    void parseParamList(Predicate& p);
    void parseStringList(Predicate& s);
    Parameter parseParameter();
    DatalogProgram parseDatalog();
    void runParser();
    void tokenString(){
        for(unsigned int i = 0; i < tokens.size(); ++i){
            std::cout << tokens.at(i).toString() << std::endl;
        }
    }
};


#endif //INC_236PROJECT1_0_PARSER_H
