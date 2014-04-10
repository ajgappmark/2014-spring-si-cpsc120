/**
 * Ben Blazak
 * week 5
 * example-3
 *
 * Notes:
 * - Everyone solved this one, that I know of, and there's really not much more
 *   to say about it, lol.  But here it is, working, just for fun.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int main() {

    int choice;  // to hold an integer representing the user's choice

    cout << "------- Menu -------\n"
         << " 1: Charles Dickens\n"
         << " 2: Dr. Seuss\n"
         << " 3: Albert Einstein\n"
         << " 4: Anna of Arendell\n"
         << "--------------------\n"
         << "\n";
    cout << "Enter the number of the person to display a quote from"
         << " (1, 2, 3, or 4): ";
    cin >> choice;

    cout << "\n";

    cout << "-----------------------------------------"
         << "--------------------------------------\n";

    if (choice == 1) {
        cout << "It was the best of times,\n"
             << "it was the worst of times,\n"
             << "it was the age of wisdom,\n"
             << "it was the age of foolishness,\n"
             << "it was the epoch of belief,\n"
             << "it was the epoch of incredulity,\n"
             << "...\n"
             << "  -- Charles Dickens, \"A Tale of Two Cities\"\n";
    } else if (choice == 2) {
        cout << "You have brains in your head.\n"
             << "You have feet in your shoes.\n"
             << "You can steer yourself in any direction you choose.\n"
             << "You're on your own, and you know what you know.\n"
             << "And you are the guy who'll decide where to go.\n"
             << "  -- Dr. Seuss, \"Oh, the Places You'll Go!\"\n";
    } else if (choice == 3) {
        cout << "A person who never made a mistake never tried anything new.\n"
             << "  -- Albert Einstein\n";
    } else if (choice == 4) {
        cout << "Do you wanna build a ☃ ?\n"
             << "  -- Anna of Arendell, \"Frozen\"\n";
    } else {
        cout << "That is not a valid option!\n";
    }

    cout << "-----------------------------------------"
         << "--------------------------------------\n"
         << "\n";

    return 0;  // success
}

