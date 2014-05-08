#include <iostream>
using namespace std;

int main() {
    // 2 mistakes

    cout << "i = ";
    for (int i=0; i<5; i+1) {
        cout << i << ", ";
    }
    cout << endl;

    cout << "i*2 = ";
    for (int i=0; i<5; i+1) {
        cout << i*2 << ", ";
    }
    cout << endl;

    return 0;
}

