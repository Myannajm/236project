//
// Created by Myanna Jean Moody on 1/21/22.
//
#include "Lexer.h"
#include "Token.h"
#include "ColonDash.h"
#include "ColonAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QuestionMarkAuto.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "ID.h"
#include "String.h"
#include "Comment.h"
#include "Undefined.h"
#include "endOf.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}
Lexer::~Lexer() {
    //prevent memory leaks by clearing out dynamic vectors
    while(!tokens.empty()){
        tokens.pop_back();
    }
    while(!automata.empty()){
        automata.pop_back();
    }
}
void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionMarkAuto());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new endAutomaton());
}
void Lexer::Run(std::string& input){
    if(input.empty()){
        line_num = 0;
    }
    else{
        line_num = 1;
    }
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    char c;
    Automaton* max_automata;
    for (unsigned int i = 0; i < input.length(); i++){
        c = input[i];
        std::string tokenInfo;
        unsigned int maxRead = 0;
        unsigned int inputRead = 0;

        //DEAL WITH WHITESPACE

        if(isspace(c)){
            if(c == '\n'){
                line_num++;
            }
            continue;
        }
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for(unsigned int j =0; j < automata.size(); j++){
            Automaton* curr_automata = automata.at(j);
            inputRead = curr_automata->Start(input.substr(i));
            if (inputRead > maxRead) {
                maxRead = inputRead;
                max_automata = curr_automata;
            }
        }
        // Here is the "Max" part of the algorithm
        if(maxRead > 0) {
            tokenInfo = input.substr(i, maxRead);
            Token newToken = max_automata->CreateToken(tokenInfo, line_num);
            line_num += max_automata->NewLinesRead();
            //.push_back(newToken);
            if(max_automata != automata.at(14)){
                tokens.push_back(newToken);
            }

        }
        else {
            maxRead = 1;
            max_automata = new UndefinedAutomaton();
            Token undefinedToken = max_automata->CreateToken(input.substr(i,1), line_num);
            tokens.push_back(undefinedToken);
        }
        if(!input.empty()){
            i += maxRead-1;
        }
    }
    max_automata = new endAutomaton();
    Token endOf = max_automata->CreateToken("", line_num+1);
    tokens.push_back(endOf);
}

std::string Lexer::toString() const{
    std::string printMe = "";
    for(unsigned int m = 0; m < tokens.size(); ++m){
        printMe += tokens.at(m).toString() + "\n";
    }
    printMe += "Total Tokens = ";
    printMe += std::to_string(tokens.size()) + "\n";
    return printMe;
}

