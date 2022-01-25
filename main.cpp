#include <iostream>
#include <fstream>
#include <string>
#include "Scanner.h"
using namespace std;

int main(int argc, char** argv) {
    std::ifstream in;
    in.open(argv[1]);
    std::string data;

    if (argc < 2) {std::cerr << "Please provide name of input file";}
    if (!in) {std::cout << "Unable to open file";}

    Scanner* scanner = new Scanner();
    getline(in, data);
    std::string wholeFile = data;
    while(getline(in, data)){
        wholeFile += '\n'+data;
    };
    scanner->Run(wholeFile);
    std::cout << scanner->toString();

    delete scanner;
    return 0;
}
