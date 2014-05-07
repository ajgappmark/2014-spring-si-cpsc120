#include <cmath>
#include <iostream>
using namespace std;


// This function prints "hello world!"
//
// Arguments: none
// Return value: void
void print_hello() {
    cout << "hello world!" << endl;
}


int main() {
    // 1 error

    cout << "now we are going to print \"hello world!\"\n";

    print_hello();

    return 0;
}

