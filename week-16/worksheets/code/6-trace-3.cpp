#include <iostream>
using namespace std;

int main() {
    // declare and initialize the array
    int a[7];
    for (int i=0; i<7; i++)
        a[i] = (i*7)%5;

    // print the array
    cout << "a = { ";
    for (int i=0; i<7; i++)
        cout << a[i] << ", ";
    cout << "};\n";

    // --- find the sum and print the average ---

    int sum = 0;
    for (int i=0; i<7; i++)
        sum += a[i];

    cout << "the average of these elements is " << sum/7.0 << endl;

    return 0;
}

