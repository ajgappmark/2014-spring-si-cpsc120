/**
 * Ben Blazak
 * week 5
 * calculator - challenge 2
 *
 * Notes:
 * - In this solution, we use the `pow()` function instead of raising `a` to
 *   the `b`th power by ourselves.  This is because 1) it's easier, and 2)
 *   we're going to go over library functions soon, whereas doing it ourselves
 *   would require a loop, which we won't cover till a bit later.
 * - For documentation on `pow()` see
 *   http://en.cppreference.com/w/cpp/numeric/math/pow
 */


#include <cmath>
// pow()

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

    cout << "Please enter an operation (+, - , *, /, ^): ";
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
        case '^': cout << pow(a,b); break;
        default: cout << "ERROR: Operation not supported";
    }

    cout << endl;

    return 0;  // success
}

