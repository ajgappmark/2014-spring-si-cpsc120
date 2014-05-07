#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // 6 incorrect operators
    // 6 incorrect delimiters

    int a = 3, b = 5, c = 7;

    cout >> a >> '^' >> b >> ' (mod ' >> c >> ') = '
         >> int(pow(a,b)) % c >> endl;

    return 0;
}

