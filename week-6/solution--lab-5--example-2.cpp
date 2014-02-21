/**
 * Ben Blazak
 * week 5
 * example-2
 *
 * Notes:
 * - Thanks to the people who pointed out to me that `'A'` could be used
 *   instead of `65` (and so on).  I had originally intended for the integer
 *   representations to be used (since conceptually we're dealing with integer
 *   ranges in the ASCII table), but using character literals seems cleaner in
 *   this case :) .
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    char c;  // to hold a character, entered by the user

    cout << "Please enter a character: ";
    cin >> c;

    if ( (c >= 33 && c <= 47) || (c >= 91 && c <= 96)
                              || (c >= 123 && c <= 126) ) {

        cout << "'" << c << "' is a symbol\n";

    } else if ( c >= 48 && c <= 57 ) {

        cout << "'" << c << "' is a number\n";

    } else if ( c >= 'A' && c <= 'Z' ) {

        cout << "'" << c << "' is an upper case character\n";

    } else if ( c >= 'a' && c <= 'z' ) {

        cout << "'" << c << "' is a lower case character\n";

    } else {
        cout << "'" << c << "' is not in any of our categories\n";
    }

    return 0;  // success
}

