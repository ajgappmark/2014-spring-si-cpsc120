/**
 * Ben Blazak
 * week 5
 * calculator - challenge 4
 *
 * Notes:
 * - Notice that here too (as in part 2 of this challenge) we use `pow()`, for
 *   the same reasons.
 * - Since we're using `pow()`, which handles fractional exponents quite
 *   nicely, the only thing we're missing is to allow the user to input them
 *   (since up to this point we've been asking for integers).  If we were
 *   calculating the power ourselves, this would be more difficult.
 * - Since we're using `pow()`, the differences (trade-offs) between this
 *   program and part 3 of this challenge are relatively minor.  In general,
 *   `double`s take up more memory than do `int`s (8 bytes instead of 4), and
 *   store numbers in a very different way (loop up "IEEE Double-precision
 *   floating-point format" for a (very long) discussion on what exactly that
 *   means).  If we were doing things by ourselves (with loops) the trade-offs
 *   between the different ways in which we would have to do things would be
 *   more explicit (and more important).
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
    double  a;         // to hold the user's first real number
    double  b;         // to hold the user's second real number
    string operation;  // to hold the user's operation

    cout << "Please enter a real number: ";
    cin >> a;

    cout << "Please enter an operation (+, - , *, /, **): ";
    cin >> operation;

    cout << "Please enter another real number: ";
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
        cout << a / b;
    else if ( operation.compare("**") == 0 )
        cout << pow(a,b);
    else
        cout << "ERROR: Operation not supported";

    cout << endl;

    return 0;  // success
}

