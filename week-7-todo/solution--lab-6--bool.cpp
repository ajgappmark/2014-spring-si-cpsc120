/**
 * Ben Blazak
 * week 6
 * boolean expressions
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 1

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test whether it is 0: ";
        cin >> i;

        // - Fill in a correct expression in place of `true` in the conditional
        //   below, using exactly one relational operator.

        if (i != 0)
            cout << "+++ You did not enter 0\n";
        else
            cout << "--- Ha! You did enter 0\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 2

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test whether it is 0: ";
        cin >> i;

        // - Fill in a correct expression in place of `true` in the conditional
        //   below, without using any operators at all.

        if (i)
            cout << "+++ You did not enter 0\n";
        else
            cout << "--- Ha! You did enter 0\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 3

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test divisibility: ";
        cin >> i;

        // - Fill in a correct expression in place of `true` in the conditional
        //   below.

        if ( (i%2==0 && i%3==0) || (i%5==0 && i%7==0) )
            cout << "+++ The integer you entered is either divisible by 2 and"
                    " 3, or divisible by 5\n"
                 << "and 7, or both.\n";
        else
            cout << "--- The integer you entered is not divisible by 2 and 3,"
                    " or by 5 and 7, or\n"
                 << "both.\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 4

    {
        char c;  // to store input from the user

        cout << "Enter a character to test whether it is a symbol: ";
        cin >> c;

        // - *Without looking at last week's assignment*, fill in a correct
        //   expression in place of `true` in the conditional below.

        if (    (c >= '!' && c <= '/')
             || (c >= ':' && c <= '@')
             || (c >= '[' && c <= '`')
             || (c >= '{' && c <= '~') ) {

            cout << "+++ '" << c << "' is a symbol.\n";

        } else {

            cout << "--- '" << c << "' is not a symbol.\n";

        }
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 5

    {
        int a, b, c;  // to store 3 integers from the user

        cout << "Enter 3 integers, separated by spaces: ";
        cin >> a >> b >> c;

        cout << "The largest of these integers is: ";

        // - Output the largest of the 3 integers input by the user (probably
        //   using if statements).

        int largest = a;

        if (b > largest)
            largest = b;
        if (c > largest)
            largest = c;

        cout << largest << endl;
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------

    return 0;
}

