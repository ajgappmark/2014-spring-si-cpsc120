/**
 * Ben Blazak
 * CPSC 120
 * lab week 4
 *
 *
 * Notes:
 *
 * - Again, please remember that this is only one possible solution.  Anything
 *   just as clear is just as good :)
 *
 * - Again also, note that I could have 1) used `using namespace std;` or 2)
 *   fully qualified `string`, `cin`, and `cout` by writing `std::string`,
 *   `std::cin`, and `std::cout`, rather than 3) importing each relevant symbol
 *   into the current namespace with `using std::cin;`, `using std::cout;`, and
 *   `using std::string;`.  Each method has its benefits.  I've read that using
 *   either the second or the third method is considered good practice --
 *   though to this point I've been using the second exclusively, because of
 *   its relative simplicity.
 *
 * - I've included the steps from the assignment as comments.  This isn't
 *   strictly necessary, but when practical it does emphasize the fact that you
 *   followed the directions precisely (which seems like a good thing to
 *   emphasize when you can... lol).
 */

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main() {

    // 0 - declare all variables
    string name;               // the user's name
    double kelvins_entered;    // kelvins, entered by the user
    double newtons_converted;  // newtons, converted from `kelvins_entered`
    double kelvins_converted;  // kelvins, converted from `newtons_converted`

    // 1 - ask the for the users name
    cout << "What is your name: ";
    cin >> name;

    // 2 - ask them to enter the value for kelvin and convert it to newtons
    cout << "Please enter the Kelvin value you would like to convert to"
         << " Newtons: ";
    cin >> kelvins_entered;

    // 3 - convert the users input to newtons
    //   - Kelvins to Newtons [°N] = ([°K] − 273.15) × 33⁄100
    newtons_converted = (kelvins_entered - 273.15) * 33.0 / 100.0;

    // 4 - convert the newtons back to kelvins
    //   - Newtons to Kelvins [°K] = [°N] × 100⁄33 + 273.15
    kelvins_converted = newtons_converted * 100.0 / 33.0 + 273.15;

    // 5 - display users name ad tell them the results
    cout << "Okay, " << name << " your Kelvin value of " << kelvins_entered
         << " is " << newtons_converted << " Newton(s)\n";
    cout << "Here is the Kelvin value again (" << kelvins_converted
         << ") that was converted from Newtons\n";

    return 0;  // success
}

