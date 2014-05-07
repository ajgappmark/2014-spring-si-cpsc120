#include <iostream>
using namespace std;

int main() {
    int a = 3;

    for (int i = 7; i > a; i--) {

        for (int j = 11; j > i; j--) {

            cout << "*";

        }

        cout << endl;

    }

    return 0;
}

