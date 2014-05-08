#include <iostream>
using namespace std;

int main() {
    // 1 mistake

    int a = 3;

    if (a = 5)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

