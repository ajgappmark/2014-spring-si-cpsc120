#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));

    int a = rand()%10, b = rand()%10, c = rand()%10;
    int smallest;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    if (a <= b && a <= c) {
        smallest = a;
        cout << "a is smallest" << endl;
    } else if (b <= a && b <=c) {
        smallest = b;
        cout << "b is smallest" << endl;
    } else {
        smallest = c;
        cout << "c is smallest" << endl;
    }

    cout << "smallest = " << smallest << endl;

    return 0;
}

