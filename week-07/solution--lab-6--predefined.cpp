/**
 * Ben Blazak
 * week 6
 * predefined functions
 */


#include <cmath>
// pow()
// log()
// sqrt()
// sin()
// cos()
// tan()

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int main() {
    double a;          // to hold the user's first number
    double b;          // to hold the user's second number
    string operation;  // to hold the user's operation

    cout << "Please enter an expression (like `4 * 5` or `ln 5`): ";

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
    else if ( operation.compare("**") == 0 )
        cout << pow(a,b);
    else if ( operation.compare("ln") == 0 )
        cout << log(b);
    else if ( operation.compare("sqrt") == 0 )
        cout << sqrt(b);
    else if ( operation.compare("sin") == 0 )
        cout << sin(b);
    else if ( operation.compare("cos") == 0 )
        cout << cos(b);
    else if ( operation.compare("tan") == 0 )
        cout << tan(b);    
    else {
        cout << "ERROR: Operation not supported\n";
        return 1;  // error
    }

    cout << endl;

    return 0;  // success
}

