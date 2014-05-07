#include <iostream>
using namespace std;

int main() {
    // 2 mistakes

    a[7] = {1, 3, 5, 7, 9, 11, 13};

    cout << "a = { ";

    for (int i=0; i<=7; i++)
        cout << a[i] << ", ";

    cout << "};\n";

    return 0;
}

