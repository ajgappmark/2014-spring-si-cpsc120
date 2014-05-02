#include <iostream>
using namespace std;

int main() {
    cout << "a b c d\n" << "--------\n";

    int a, b, c;

    a = b = c = 3;  cout << a << " " << b << " " << c << endl;
    b = c = 5;      cout << a << " " << b << " " << c << endl;
    c = 7;          cout << a << " " << b << " " << c << endl;

    int d = b;      cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

