/**
 * Ben Blazak
 * week 6
 * hint -- boolean expressions -- part 3
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b, c;  // to store 3 integers from the user

    cout << "Enter 3 integers, separated by spaces: ";
    cin >> a >> b >> c;

    // ------------------------------------------------------------------------
    // method 1

    cout << "The smallest of these integers is: ";

    int smallest = a;

    if (b < smallest)
        smallest = b;
    if (c < smallest)
        smallest = c;

    cout << smallest << endl;

    // ------------------------------------------------------------------------
    // method 2

    cout << "The smallest of these integers is: ";

    if (a <= b && a <= c)
        cout << a;
    else if (b <= a && b <= c)
        cout << b;
    else if (c <= a && c <= b)
        cout << c;

    cout << endl;

    // ------------------------------------------------------------------------

    return 0;
}

