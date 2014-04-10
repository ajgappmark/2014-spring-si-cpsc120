/**
 * Ben Blazak
 * CPSC 120
 * lab week 3
 *
 *
 * Notes:
 *
 * - Remember, this is only one possible solution.  As long as another works
 *   well and is just as readable, it's just as good.
 *
 * - In this program, the comments next to the variables are a bit redundant,
 *   the program being so short that their uses are apparent.  In longer
 *   programs though, such comments are sometimes very helpful.
 *
 * - Note that each line is wrapped at not more than 80 characters.  This is an
 *   old convention (from when terminals only displayed 25 lines by 80 columns
 *   worth of text), but some consider it polite, and I prefer it.
 *
 * - Note also that if you don't use `using namespace std;` it's not only
 *   `cout` and `cin` that must be prefixed with `std::`, but also `std::endl`,
 *   and a few other things that we'll get to in following weeks.
 */

#include <iostream>

int main() {
    int classes;          // number of classes the user is taking
    int graduation_year;  // year in which the user graduated
    int siblings;         // number of siblings the user has
    int roommates;        // number of roommates the user has
    int professor_age;    // the age of the professor

    std::cout << "How many classes do you have? ";
    std::cin >> classes;

    std::cout << "What year did you graduate from high school? ";
    std::cin >> graduation_year;

    std::cout << "How many siblings they have? ";
    std::cin >> siblings;

    std::cout << "How many roommates do you have? ";
    std::cin >> roommates;

    std::cout << "Hold old do you think the professor is? ";
    std::cin >> professor_age;

    std::cout << std::endl;

    std::cout << "1. You have " << classes << " classes.\n";
    std::cout << "2. You graduated from high school in " << graduation_year
              << "\n";
    std::cout << "3. You have " << siblings << " siblings\n";
    std::cout << "4. You have " << roommates << " roommates\n";
    std::cout << "5. The professor is " << professor_age << " years old.\n";

    return 0;  // success
}

