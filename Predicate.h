//
// Created by Myanna Jean Moody on 2/4/22.
//

#ifndef INC_236PROJECT1_0_PREDICATE_H
#define INC_236PROJECT1_0_PREDICATE_H
#include <string>
#include "Parameter.h"

class Predicate{
public:
    std::string name;
    std::vector<Parameter> parameters;

    Predicate(const std::string &name) : name(name) {}

    /* ~Predicate() {
        while(!parameters.empty()){
            parameters.pop_back();
        }
    }*/

    void addValue(Parameter input){parameters.push_back(input);}
    std::string getName(){return name;}
    std::vector<Parameter> getParameters(){return parameters;}
    std::string predToString(){
        std::string out;
        out += getName() + "(";
        for(unsigned int i = 0; i < parameters.size()-1; ++i){
            out += parameters.at(i).toString() + ",";
        }
        out += parameters.back().toString() + ")" + "\n";
        return out;
    }
};
#endif //INC_236PROJECT1_0_PREDICATE_H
