/**
 * Ben Blazak
 * week 9
 * solution to exercise
 *
 *
 * Design:
 *
 * - Note that at most one leading and one trailing whitespace character is
 *   allowed
 *
 * - Original shape
 *
 *         *
 *       * * *
 *     * * * * *
 *   * * * * * * *
 *     * * * * *
 *       * * *
 *         *
 *
 * - Replacing ' ' with '.', and noting how many '.'s we now have initially,
 *   and how many "*"s we have after that
 *
 *   i  .  *
 *   0  6  1   ......*
 *   1  4  3   ....*.*.*
 *   2  2  5   ..*.*.*.*.*
 *   3  0  7   *.*.*.*.*.*.*
 *   4  2  5   ..*.*.*.*.*
 *   5  4  3   ....*.*.*
 *   6  6  1   ......*
 *
 *   so . occurres abs(i*2-6) times in each row
 *   so * occurres 7-abs(i*2-6) times in each row
 */


#include <cmath>
using std::abs;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main() {

    {
        // using for loops

        for (int i=0; i<7; i++) {

            for (int j=0; j<abs(i*2-6); j++)
                cout << " ";

            for (int j=0; j<7-abs(i*2-6); j++)
                cout << "* ";

            cout << endl;
        }
    }

    cout << endl;

    {
        // using while loops

        int i, j;

        i=0;
        while (i<7) {

            j=0;
            while (j<abs(i*2-6)) {
                cout << " ";
                j++;
            }

            j=0;
            while (j<7-abs(i*2-6)) {
                cout << "* ";
                j++;
            }

            cout << endl;
            i++;
        }
    }

    cout << endl;

    {
        // using do-while loops
        // - it's not possible to do this with this structure without having a
        //   leading space, because do-while loops always execute once before
        //   checking their condition.

        int i, j;

        i=0;
        do {

            j=0;
            do {
                cout << " ";
                j++;
            } while(j<abs(i*2-6)+1);

            j=0;
            do {
                cout << "* ";
                j++;
            } while(j<7-abs(i*2-6));

            cout << endl;
            i++;
        } while (i<7);
    }

    return 0;  // success
}

