#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;  // to store the user's integer

    cout << "Please enter an integer: ";
    cin >> x;

    if (x < 0) {
        cout << "Your integer is negative\n";
    } else if (x < 100) {
        cout << "Your integer is fairly small\n";
    } else {
        cout << "Your integer is fairly large\n";
    }

    if (x % 2 == 0)
        cout << "Your integer is even\n";
    else
        cout << "Your integer is odd\n";

    if (x % 3 == 0)
        cout << "Your integer is evenly divisible by 3\n";
    else
        cout << "Your integer is not evenly divisible by 3\n";

    return 0;  // success
}

