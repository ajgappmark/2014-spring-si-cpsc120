#include <iostream>
using namespace std;

int main() {
    int a = 3;

    if (a == 5) {
        cout << "true" << endl;
        a++;
    } else {
        cout << "false" << endl;
        a--;
    }

    cout << "a = " << a << endl;

    return 0;
}

