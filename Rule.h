//
// Created by Myanna Jean Moody on 2/4/22.
//

#ifndef INC_236PROJECT1_0_RULE_H
#define INC_236PROJECT1_0_RULE_H
#include <vector>
#include <string>
#include <sstream>
#include "Predicate.h"

class Rule{
protected:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;
public:
    Rule(Predicate headPredicate, std::vector<Predicate>& body) : headPredicate(headPredicate), bodyPredicates(body) {}
    //void addBP(Predicate &p){bodyPredicates.push_back(p);}

    std::string headString(){return headPredicate.predToString();}
    std::string bodyToString(){
        std::string out;
        for(unsigned int i = 0; i < bodyPredicates.size()-1; ++i){
            out += bodyPredicates.at(i).predToString() + ",";
        }
        out += bodyPredicates.back().predToString() + ".";
        return out;
    }
};
#endif //INC_236PROJECT1_0_RULE_H
