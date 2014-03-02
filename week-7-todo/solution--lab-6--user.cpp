/**
 * Ben Blazak
 * week 6
 * user defined functions
 *
 * Notes:
 * - The output of this program for the `convert-usd-eur` operation is a little
 *   more than what the assignment asked for.  But I thought I'd include it, as
 *   an example of how one would do such a thing :)
 * - The <iomanip> header contains functions for Manipulating I/O; i.e., doing
 *   things like only outputting 2 decimal places of a `double`, or helping to
 *   print strings where the text is right justified (and the left hand side is
 *   filled in with spaces, or some other fill character).
 */


#include <iomanip>
using std::fixed;
using std::setprecision;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


double abs(double a);
double mod(double a, double b);
double convert_usd_eur(double a);
double convert_f_c(double a);


int main() {
    double a;          // to hold the user's first number
    double b;          // to hold the user's second number
    string operation;  // to hold the user's operation

    cout << "Please enter an expression (like `4 * 5` or `abs -5`): ";

    // ignore all initial whitespace
    while (    cin.peek() == ' '  || cin.peek() == '\t'
            || cin.peek() == '\n' || cin.peek() == '\v'
            || cin.peek() == '\f' || cin.peek() == '\r' )
        cin.get();

    // when we have a unary operator, we only use `b`, and leave `a`
    // uninitialized
    if ( cin.peek() >= 'a' && cin.peek() <= 'z' ) {
        cin >> operation >> b;
        cout << operation << " " << b << " = ";
    } else if ( (cin.peek() >= '0' && cin.peek() <= '9')
                || cin.peek() == '-' ) {
        cin >> a >> operation >> b;
        cout << a << " " << operation << " " << b << " = ";
    } else {
        cout << "ERROR: First symbol not recognized\n";
        return 1;  // error
    }

    if ( operation.compare("+") == 0 )
        cout << a + b;
    else if ( operation.compare("-") == 0 )
        cout << a - b;
    else if ( operation.compare("*") == 0 )
        cout << a * b;
    else if ( operation.compare("/") == 0 )
        cout << a / b;
    else if ( operation.compare("abs") == 0 )
        cout << abs(b);
    else if ( operation.compare("mod") == 0 )
        cout << mod(a,b);
    else if ( operation.compare("convert-usd-eur") == 0 )
        cout << fixed << setprecision(2) << "€" << convert_usd_eur(b);
    else if ( operation.compare("convert-f-c") == 0 )
        cout << convert_f_c(b);
    else {
        cout << "ERROR: Operation not supported\n";
        return 1;  // error
    }

    cout << endl;

    return 0;  // success
}


double abs(double a) {
    if (a < 0)
        return -a;
    else
        return a;
}

/**
 * Notes:
 * - This function accepts doubles, and returns a double, but internally, it
 *   converts these numbers to integers, and performs modular arithmetic as
 *   usual.  This is done for simplicity's sake, even though it is not
 *   mathematically correct.
 */
double mod(double a, double b) {
    return int(a) % int(b);
}

double convert_usd_eur(double a) {
    return a * 0.727484;
}

double convert_f_c(double a) {
    return (a - 32) * 5.0/9.0;
}

