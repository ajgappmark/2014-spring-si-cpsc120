/**
 * group members:
 * week 8
 * worksheet
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main() {

    int i = 1;

    while (i < 10) {

        int j = 0;
        while (j < i) {
            cout << "*";
            j++;
        }

        cout << "\n";
        i+=2;
    }

    i = 1;

    while (i < 10) {

        int j = i;
        while (j < 10) {
            cout << "*";
            j++;
        }

        cout << "\n";
        i+=2;
    }

    cout << "\n";

    return 0;  // success
}

