#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 7;

    cout << "before swapping: " << a << " " << b << endl;

    // swap
    int temp = int a;
    int a = int b;
    int b = int temp;

    cout << "after swapping: " << a << " " << b << endl;

    return 0;
}

