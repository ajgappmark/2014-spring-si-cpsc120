/**
 * Ben Blazak
 * week 8
 * solution to converting numbers to roman numerals
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


// ----------------------------------------------------------------------------
// function prototypes
// ----------------------------------------------------------------------------

string digit(int n);
string number_to_roman(int n);


// ----------------------------------------------------------------------------
// main()
// ----------------------------------------------------------------------------

int main() {
    int  number;  // the user's integer
    char choice;  // the user's choice (to continue or not)

    do {
        cout << "Please enter an integer: ";
        cin >> number;

        cout << "--> " << number_to_roman(number) << "\n\n";

        cout << "Would you like to convert another integer (Y/N)? ";
        cin >> choice;

        cout << "\n";
    } while (cin && choice != 'n' && choice != 'N');

    return 0;  // success
}


// ----------------------------------------------------------------------------
// helper functions
// ----------------------------------------------------------------------------

/**
 * Notes:
 * - We limit this function to converting numbers in the range [1,3999].  In
 *   actual Roman numerals, higher numbers can be represented (a bar placed
 *   above a (string of) numerals multiplies its value by 1000).
 */
string number_to_roman(int n) {
    if (n <=0 || n >= 4000)
        return "ERROR";

    string output = "";

    while (n > 0) {
        if (n >= 1000) {
            output += "M";
            n -= 1000;
        } else if (n >= 900) {
            output += "CM";
            n -= 900;
        } else if (n >= 500) {
            output += "D";
            n -= 500;
        } else if (n >= 400) {
            output += "CD";
            n -= 400;
        } else if (n >= 100) {
            output += "C";
            n -= 100;
        } else if (n >= 90) {
            output += "XC";
            n -= 90;
        } else if (n >= 50) {
            output += "L";
            n -= 50;
        } else if (n >= 40) {
            output += "XL";
            n -= 40;
        } else if (n >= 10) {
            output += "X";
            n -= 10;
        } else if (n >= 9) {
            output += "IX";
            n -= 9;
        } else if (n >= 5) {
            output += "V";
            n -= 5;
        } else if (n >= 4) {
            output += "IV";
            n -= 4;
        } else if (n >= 1) {
            output += "I";
            n -= 1;
        }
    }

    return output;
}

