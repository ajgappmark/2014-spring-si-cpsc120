#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));

    int a = rand()%10, b = rand()%10, c = rand()%10;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    if (a <= b && a <= c)
        cout << "a is smallest" << endl;

    return 0;
}

