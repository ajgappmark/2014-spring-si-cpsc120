#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));

    int a = rand()%10, b = rand()%10, c = rand()%10;
    int smallest = 0;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    if (b < c)
        smallest = b;

    if (c <= b)
        smallest = c;

    if (a <= b && a <= c) {
        smallest = a;
        cout << "a is smallest" << endl;
    }

    return 0;
}

