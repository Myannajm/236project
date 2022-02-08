//
// Created by Myanna Jean Moody on 2/4/22.
//

#ifndef INC_236PROJECT1_0_PARAMETER_H
#define INC_236PROJECT1_0_PARAMETER_H
#include "Token.h"
#include "Predicate.h"
#include "Parser.h"
#include <vector>
#include <string>

class Parameter{
public:
    std::string data;

    Parameter(const std::string &data) : data(data) {}
    std::string toString(){
        return data;
    }
};


#endif //INC_236PROJECT1_0_PARAMETER_H
