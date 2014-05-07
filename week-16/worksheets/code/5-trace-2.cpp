#include <iostream>
using namespace std;

int main() {
    int a = 3;

    int i = 7;
    while (i > a) {

        int j = 11;
        while (j > i) {

            cout << "*";
            j--;

        }

        cout << endl;
        i--;

    }

    return 0;
}

