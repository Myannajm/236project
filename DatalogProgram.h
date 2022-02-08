//
// Created by Myanna Jean Moody on 2/4/22.
//

#ifndef INC_236PROJECT1_0_DATALOGPROGRAM_H
#define INC_236PROJECT1_0_DATALOGPROGRAM_H
#include <vector>
#include "Predicate.h"
#include "Parser.h"
#include "Rule.h"
#include <set>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>

class DatalogProgram{
protected:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
    std::set<std::string> domains;
public:
    DatalogProgram(const std::vector<Predicate> &schemes, const std::vector<Predicate> &facts,
                   const std::vector<Predicate> &queries, const std::vector<Rule> &rules) : schemes(schemes), facts(facts), queries(queries), rules(rules){}

    virtual ~DatalogProgram() {}
    void setDomain(){
        for(unsigned int i = 0; i < facts.size(); ++i){
            std::vector<Parameter> temp = facts.at(i).getParameters();
            for(unsigned int j = 0; j < temp.size(); ++j){
                domains.insert(temp.at(j).toString());
            }
        }
    }
    std::string printScheme(){
        std::stringstream out;
        out << "Schemes(" << schemes.size() << "):" << "\n";
        for(unsigned int i = 0; i < schemes.size(); ++i){
            out << schemes.at(i).predToString() << "\n";
        }
        return out.str();
    }
    std::string printFacts(){
        std::stringstream out;
        out << "Facts(" << facts.size() << "):" << "\n";
        for(unsigned int i = 0; i < facts.size(); ++i){
            out << facts.at(i).predToString() << "\n";
        }
        return out.str();
    }
    std::string printRules(){
        std::stringstream out;
        out << "Rules(" << rules.size() << "):" << "\n" << rules.at(0).headString() << "\n";
        for(unsigned int i = 1; i < rules.size(); ++i){
            out << rules.at(i).ruleToString() << "\n";
        }
        return out.str();
    }
    std::string printQueries(){
        std::stringstream out;
        out << "Queries(" << queries.size() << "):" << "\n";
        for(unsigned int i = 1; i < queries.size(); ++i){
            out << queries.at(i).predToString() << "\n";
        }
        return out.str();
    }

    std::string dataToString(){
        std::stringstream out;
        out << "Success!" << "\n";
        out << printScheme() << printFacts() << printRules() << printQueries();
        /*out << "Domain(" << domains.size() << "):";
        std::set<std::string>::const_iterator iter = domains.begin();
        for(iter = domains.begin(); iter!=domains.end();++iter){
            out << "\n" << *iter;
        }*/
        return out.str();
    }

//datalog program starts w a scheme, then facts, then facts, rules, queries
//fail on empty file, doesn't start w schemes

};
#endif //INC_236PROJECT1_0_DATALOGPROGRAM_H
