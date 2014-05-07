#include <iostream>
using namespace std;

int main() {
    // have to be a little careful with do-while loops:
    // it's not always possible to write one that means the
    // same thing as the corresponding for or while loop

    int a = 3;

    int i = 7;
    do {

        int j = 11;
        do {

            cout << "*";
            j--;

        } while (j > i);

        cout << endl;
        i--;

    } while (i > a);

    return 0;
}

