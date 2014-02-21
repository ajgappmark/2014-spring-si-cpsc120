/**
 * Ben Blazak
 * week 5
 * calculator - challenge 3
 *
 * Notes:
 * - Notice that here too (as in part 2 of this challenge) we use `pow()`, for
 *   the same reasons.
 * - Since we're using `**` here instead of `^`, we can no longer store the
 *   operation in a single char; we must use a string.  Because we're using a
 *   string, we can no longer use the `switch` statement.  We also can no
 *   longer use `==` to compare our operator with its possible values, since
 *   that operator is not defined for strings; instead we must use the string
 *   member function `compare()`.
 */


#include <cmath>
// pow()

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int main() {
    int  a;            // to hold the user's first integer
    int  b;            // to hold the user's second integer
    string operation;  // to hold the user's operation

    cout << "Please enter an integer: ";
    cin >> a;

    cout << "Please enter an operation (+, - , *, /, **): ";
    cin >> operation;

    cout << "Please enter another integer: ";
    cin >> b;

    cout << endl;

    cout << a << " " << operation << " " << b << " = ";

    if ( operation.compare("+") == 0 )
        cout << a + b;
    else if ( operation.compare("-") == 0 )
        cout << a - b;
    else if ( operation.compare("*") == 0 )
        cout << a * b;
    else if ( operation.compare("/") == 0 )
        cout << double(a) / double(b);
    else if ( operation.compare("**") == 0 )
        cout << pow(a,b);
    else
        cout << "ERROR: Operation not supported";

    cout << endl;

    return 0;  // success
}

