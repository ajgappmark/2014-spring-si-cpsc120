/**
 * Ben Blazak
 * solution to project-4 (numbers to words)
 *
 * Environment:
 * - OS X 10.9.2, compiling with Apple LLVM 5.1 (clang-503.0.38)
 *
 * References:
 * - http://en.wikipedia.org/wiki/Powers_of_10
 *
 * Notes:
 * - A more advanced (and much shorter) solution would likely use array lookups
 *   instead of switch statements inside functions for to_words__ones(), etc.
 * - Recursion could be used instead of looping in to_words(), which would be
 *   shorter.  It would also feel more conceptually clean (to me), but as with
 *   arrays, the concept is a bit advanced.
 * - As of C++11, the <random> library probably provides better random number
 *   generation than is available through <cstdlib>.  But the level of domain
 *   knowledge required to use it is too high for our purposes here.
 * - For testing, I made sure that consecutive runs of the program had a couple
 *   seconds in between them: if I ran the program multiple times in quick
 *   succession (as by using a loop in the shell), the pseudo-random numbers
 *   generated were the same for every run.
 * - Also, the order of magnitude of the numbers appears to be fairly
 *   consistent, and to correlate with the size of the number passed to
 *   srand().  I suppose this is to be expected, but it's too bad, since it
 *   would be nice to see more variance in number length when testing the
 *   program.
 *
 * Algorithm:
 * - If the number is negative, output "negative", and then convert the
 *   corresponding positive number.
 * - If the number is 0, output "zero".
 * - Otherwise, we'll deal with the number in groups of three digits, from
 *   right to left (i.e. starting with the least significant group of three
 *   digits).
 * - For the first group of three digits (which we'll treat as a number between
 *   0 and 999):
 *     - If the number is less than or equal to 19:
 *         - Output "one", "two", ..., "nineteen", as appropriate.  All these
 *           numbers are special cases.
 *     - Else (the number is at least 20), if the number is less than or equal
 *       to 99:
 *         - Output "twenty", "thirty", ..., "ninety", as appropriate based
 *           only on the ten's digit.
 *         - If the one's digit is not zero, convert it as if it was a number
 *           less than or equal to 19.
 *     - Else (the number is at least 100, and we know it is at most 999)
 *         - Convert the hundred's digit as if it were a number less than or
 *           equal to 19, then write "hundred", then convert rest of the number
 *           as above.
 * - For every group of three digits after this, do the same thing as for the
 *   first group, except
 *     - If the group of three digits is 000, do nothing.
 *     - Else, write "thousand", "million", ..., etc. afterwards, as
 *       appropriate.
 */


#include <cstdlib>
// rand()
// srand()

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


// ----------------------------------------------------------------------------
// function prototypes
// ----------------------------------------------------------------------------

string to_words(int n);
string to_words__ones_and_teens(int n);
string to_words__tens(int n);
string to_words__powers_of_10(int n);


// ----------------------------------------------------------------------------
// main()
// ----------------------------------------------------------------------------

int main() {
    // seed the pseudo-random number generator
    srand(time(NULL));
    srand(rand());

    // between -2^31 and 2^31-1 inclusive (or as close as rand() will get us)
    int start = rand();
    if (rand()%2)
        start *= -1;

    // between 2 and 8 inclusive
    int offset = rand()%(8-1) + 2;

    cout << "start: " << start << endl;
    cout << "offset: " << offset << endl;

    for (; offset; start+=3, offset--) {
        cout << to_words(start) << endl;
    }

    return 0;  // success
}


// ----------------------------------------------------------------------------
// helper functions
// ----------------------------------------------------------------------------

string to_words(int n) {
    if (n < 0) {
        return "negative " + to_words(-n);

    } else if (n == 0) {
        return "zero";

    } else {  // n >= 1

        string output = "";

        int group = n%1000;  // the subgroup of three digits to covert
        int power = 0;       // the power of 10 of this subgroup

        while (n) {
            if (group) {
                if (power)
                    output = to_words__powers_of_10(power) + " " + output;

                if (group <= 19) {
                    output = to_words__ones_and_teens(group) + " " + output;

                } else if (group <= 99) {
                    if (group%10)
                        output = to_words__ones_and_teens(group%10)
                                 + " " + output;
                    output = to_words__tens(group/10) + " " + output;

                } else {  // group <= 999
                    if (group%100)
                        output = to_words(group%100) + " " + output;
                    output = to_words__ones_and_teens(group/100)
                             + " hundred " + output;
                }
            }

            n /= 1000;
            group = n%1000;
            power += 3;
        }

        // remove the last character (which will be a space) before returning
        output.pop_back();

        return output;
    }
}

string to_words__ones_and_teens(int n) {
    switch (n) {
        case  1: return "one";
        case  2: return "two";
        case  3: return "three";
        case  4: return "four";
        case  5: return "five";
        case  6: return "six";
        case  7: return "seven";
        case  8: return "eight";
        case  9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        default: return "ERROR";
    }
}

string to_words__tens(int n) {
    switch (n) {
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
        default: return "ERROR";
    }
}

/**
 * Notes:
 * - Some of these powers are unnecessary, since log10(pow(2,32)) < 10, and
 *   log10(pow(2,64)) < 20 .  But there's no harm in including them anyways :)
 */
string to_words__powers_of_10(int n) {
    switch (n) {
        case 3: return "thousand";
        case 6: return "million";
        case 9: return "billion";
        case 12: return "trillion";
        case 15: return "quadrillion";
        case 18: return "quintillion";
        case 21: return "sextillion";
        case 24: return "septillion";
        case 27: return "octillion";
        case 30: return "nonillion";
        case 33: return "decillion";
        default: return "ERROR";
    }
}

