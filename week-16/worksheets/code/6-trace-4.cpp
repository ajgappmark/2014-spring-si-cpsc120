#include <iostream>
using namespace std;

int main() {
    int a[7] = { 6, 7, 3, 5, 2, 1, 4 };

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

