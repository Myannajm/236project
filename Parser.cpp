//
// Created by Myanna Jean Moody on 1/29/22.
//

#include "Parser.h"
Parser::~Parser(){
    while(!tokens.empty()){
        tokens.pop_back();
    }
};
TokenType Parser::tokenType() const {
    return tokens.at(index).getToken();
}
void Parser::advanceToken() {
    tokens.erase(tokens.begin());
}
void Parser::throwError() {
    throw tokens.at(index);
}

std::string Parser::match(TokenType t){
    if (tokenType() == t){
        std::string returnVal = tokens.at(index).getValue();
        index++;
        return returnVal;
    }
    else{
        throw tokens.at(index);
    }
    return "";
}


Predicate Parser::parseScheme() {
    Predicate p(match(ID));
    match(LEFT_PAREN);
    p.addValue(match(ID));
    parseIdList(p );
    match(RIGHT_PAREN);
    return p;
}

Predicate Parser::parseFact(){
    Predicate f(match(ID));
    match(LEFT_PAREN);
    //add domains into a set
    f.addValue(match(STRING));
    parseStringList(f);
    match(RIGHT_PAREN);
    match(PERIOD);
    return f;
}
Rule Parser::parseRule(){
    std::vector<Predicate> body;
    Predicate head(parseHeadPredicate());
    match(COLON_DASH);
    body.push_back(parsePredicate());
    parsePredList(body);
    match(PERIOD);
    Rule r(head, body);
    return r;
}
Predicate Parser::parseQuery(){
    Predicate p(parsePredicate());
    match(Q_MARK);
    return p;
}
void Parser::parseSchemeList(std::vector<Predicate>& scheme){
    if(tokenType() == FACTS){return;}
    scheme.push_back(parseScheme());
    parseSchemeList(scheme);
}
void Parser::parseFactList(std::vector<Predicate>& fact){
    if(tokenType() == RULES){return;}
    fact.push_back(parseFact());
    parseFactList(fact);
}
void Parser::parseRuleList(std::vector<Rule>& rule){
    if(tokenType() == QUERIES){return;}
    rule.push_back(parseRule());
    parseRuleList(rule);
}
void Parser::parseQueryList(std::vector<Predicate>& query){
    if(tokenType() == EOF_TYPE){return;}
    query.push_back(parseQuery());
    parseQueryList(query);
}
Predicate Parser::parseHeadPredicate(){
    Predicate hp(match(ID));
    match(LEFT_PAREN);
    hp.addValue(match(ID));
    parseIdList(hp);
    match(RIGHT_PAREN);
    return hp;
}
Predicate Parser::parsePredicate(){
    Predicate pred(match(ID));
    match(LEFT_PAREN);
    pred.addValue(parseParameter());
    parseParamList(pred);
    match(RIGHT_PAREN);
    return pred;
}
void Parser::parsePredList(std::vector<Predicate>& body){
    if(tokenType() == COMMA){
        match(COMMA);
        body.push_back(parsePredicate());
        parsePredList(body);
    }

}
void Parser::parseParamList(Predicate& p){
    if(tokenType() == COMMA){
        match(COMMA);
        p.addValue(parseParameter());
        parseParamList(p);
    }
}
void Parser::parseStringList(Predicate& s){
    if (tokenType() == COMMA){
        match(COMMA);
        s.addValue(match(STRING));
        parseStringList(s);
    }
}
void Parser::parseIdList(Predicate &p) {
    if (tokenType() == COMMA){
        match(COMMA);
        p.addValue(match(ID));
        parseIdList(p);
    }
}
Parameter Parser::parseParameter(){
    if(tokenType() == STRING ){
        return match(STRING);
    }
    else if(tokenType() == ID){
        return match(ID);
    }
    return match(UNDEFINED);
}

DatalogProgram Parser::parseDatalog() {
    std::vector<Predicate> scheme;
    std::vector<Predicate> fact;
    std::vector<Predicate> query;
    std::vector<Rule> rule;

    match(SCHEMES);
    match(COLON);
    parseSchemeList(scheme);

    match(FACTS);
    match(COLON);
    parseFactList(fact);

    match(RULES);
    match(COLON);
    parseRuleList(rule);

    match(QUERIES);
    match(COLON);
    parseQueryList(query);

    DatalogProgram datalog_program(scheme, fact, query, rule);
    return datalog_program;
}

void Parser::runParser(){
    std::cout << "running the parser..." << std::endl;
    DatalogProgram dp = parseDatalog();
    std::cout << dp.dataToString();
}