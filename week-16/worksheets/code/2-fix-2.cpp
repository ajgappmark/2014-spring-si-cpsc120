#include <iostream>
using namespace std;

int main() {
    // formula (in math notation): C = (F-32)*(5/9)

    double fahrenheit = 100;  // getting close to summer!

    cout << "The temperature is:\n";
    cout << "    " << fahrenheit << " degrees Fahrenheit\n";
    cout << "    " << fahrenheit-32 * 5/9
         << " degrees Celcius\n";

    return 0;
}

