#include <iostream>
#include "Token.h"
#include "Scanner.h"
using namespace std;

int main() {
    Scanner s = Scanner(",\n,");
    s.scanToken();
    cout << s.toString();
    return 0;
}
