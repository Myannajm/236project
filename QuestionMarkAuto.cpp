//
// Created by Myanna Jean Moody on 9/13/21.
//

#include "QuestionMarkAuto.h"
void QuestionMarkAuto::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}