#include <iostream>
using namespace std;

int main() {
    int a[7] = { 6, 7, 3, 5, 2, 1, 4 };

    int sum = 0;
    for (int i=0; i<7; i++)
        sum += a[i];

    cout << "the average of these elements is " << sum/7.0 << endl;

    return 0;
}

