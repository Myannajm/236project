//
// Created by Myanna Jean Moody on 1/21/22.
//

#include "Schemes.h"
void SchemesAutomaton::S0(const std::string& input) {
    if (input[index] == 'S') {
        inputRead = 1;
        index = 1;
        S1(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S1(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S2(const std::string& input) {
    if (input[index] == 'h') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S4(const std::string& input) {
    if (input[index] == 'm') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S6(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}