#include <iostream>
using namespace std;

int main() {
    // 'a' == 97
    cout << ('a' + 5) << endl;
    cout << char('a' + 5) << endl;

    cout << 7 << endl;
    cout << (7/3) << endl;
    cout << double(7) << endl;

    cout << 3.14159265359 << endl;
    cout << int(3.14159265359) << endl;
    cout << char( 100 + int(3.14159265359) ) << endl;

    cout << (!53) << endl;
    cout << bool(5) << endl;

    cout << "this is a string" << endl;

    cout << (3 + 5 * 3 + 5 / 2) << endl;

    cout << (10 < 5 < 7) << endl;

    return 0;
}

