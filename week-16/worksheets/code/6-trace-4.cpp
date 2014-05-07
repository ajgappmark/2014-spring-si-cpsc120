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

    // --- find and print the max and min values ---

    int min = a[0];
    int max = a[0];

    for (int i=1; i<7; i++) {

        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    cout << "the smallest of these elements is " << min << endl;
    cout << "the largest of these elements is " << max << endl;

    return 0;
}

