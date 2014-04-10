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

    int i = 0;
    while (i < 3) {

        int j = 0;
        while (j < 5) {
            cout << "*";
            j++;
        }

        cout << "\n";
        i++;
    }

    cout << "\n";

    return 0;  // success
}

