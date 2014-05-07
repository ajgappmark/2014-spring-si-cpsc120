#include <iostream>
using namespace std;

int main() {
    int a[7];

    for (int i=0; i<7; i++)
        cin >> a[i];

    // print the array (to see what the user entered)
    cout << "a = { ";
    for (int i=0; i<7; i++)
        cout << a[i] << ", ";
    cout << "};\n";

    return 0;
}

