/**
 * Ben Blazak
 * week 5
 * calculator - challenge 1
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int  a;          // to hold the user's first integer
    int  b;          // to hold the user's second integer
    char operation;  // to hold the user's operation

    cout << "Please enter an integer: ";
    cin >> a;

    cout << "Please enter an operation (+, - , *, /): ";
    cin >> operation;

    cout << "Please enter another integer: ";
    cin >> b;

    cout << endl;

    cout << a << " " << operation << " " << b << " = ";

    switch (operation) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/': cout << double(a) / double(b); break;
        default: cout << "ERROR: Operation not supported";
    }

    cout << endl;

    return 0;  // success
}

