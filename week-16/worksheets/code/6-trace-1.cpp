#include <iostream>
using namespace std;

int main() {
    int a[7];

    for (int i=0; i<7; i++)
        a[i] = (i*7)%5;

    // print the array
    cout << "a = { ";
    for (int i=0; i<7; i++)
        cout << a[i] << ", ";
    cout << "};\n";

    return 0;
}

