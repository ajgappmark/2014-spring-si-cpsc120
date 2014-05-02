#include <iostream>
#include <string>
using namespace std;

int main() {
    int    i = '5' + 4.7;  // '5' == 53
    char   c = 42;         // '*' == 42
    bool   b = 10;
    double d =  7;
    string s = "hello world!";

    int u;

    cout << i << " " << c << " " << b << " "
         << d << " " << s << " " << u << endl;

    return 0;
}

