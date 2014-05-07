#include <iostream>
using namespace std;

int main() {
    int a = 3;
    cout << "One third is: " << (1.0 / a) << endl;

    // any of these will also work
    cout << "One third is: " << (1 / double(a)) << " and "
                             << (double(1) / a) << " and "
                             << (double(1) / double(a)) << endl;

    double b = 5;
    cout << "One fifth is: " << (1.0 / b) << endl;

    // any of these will also work
    cout << "One fifth is: " << (1 / b) << " and "
                             << (1 / double(b)) << " and "
                             << (double(1) / b) << " and "
                             << (double(1) / double(b)) << endl;

    return 0;
}

