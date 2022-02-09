#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Lexer.h"
#include "Token.h"
#include "Automaton.h"
#include "Parser.h"

int main(int argc, char** argv) {
    std::ifstream in;
    in.open(argv[1]);
    std::string data;

    if (argc < 2) {std::cerr << "Please provide name of input file";}
    if (!in) {std::cout << "Unable to open file";}

    Lexer* lexer = new Lexer();
    getline(in, data);
    std::string wholeFile = data;
    while(getline(in, data)){
        wholeFile += '\n'+data;
    };
    lexer->Run(wholeFile);
    //std::cout << lexer->toString();


    Parser p(lexer->returnTokens());
    //p.runParser()
    try{
        p.runParser();
    }
    catch(Token wrong){
        std::cout <<"Failure!" <<std::endl;
        std::cout << "  " << wrong.toString();
    }

    delete lexer;
    return 0;
}
