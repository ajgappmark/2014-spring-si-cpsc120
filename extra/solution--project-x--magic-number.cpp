/**
 * Ben Blazak
 * week 8
 * solution to TODO
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


// ----------------------------------------------------------------------------
// function prototypes
// ----------------------------------------------------------------------------

string to_words(int n, int power=0);


// ----------------------------------------------------------------------------
// main()
// ----------------------------------------------------------------------------

int main() {
    int number;  // the user's integer

    cout << "Please enter an integer: ";
    cin >> number;

    cout << "\n";

    while ( number != to_words(number).length() ) {
        cout << to_words(number) << " is "
             << to_words( to_words(number).length() )
             << endl;
        number = to_words(number).length();
    }

    cout << to_words(number) << " is the magic number!\n";

    return 0;  // success
}


// ----------------------------------------------------------------------------
// helper functions
// ----------------------------------------------------------------------------

string to_words(int n, int power) {
    const string BASIC[] = { "zero", "one", "two", "three", "four", "five",
                             "six", "seven", "eight", "nine", "ten", "eleven",
                             "twelve", "thirteen", "fourteen", "fifteen",
                             "sixteen", "seventeen", "eighteen", "nineteen" };
    const string TENS[] = { "", "", "twenty", "thirty", "forty", "fifty",
                            "sixty", "seventy", "eighty", "ninety" };
    const string POWERS[] = { "thousand", "million", "billion", "trillion",
                              "quadrillion", "quintillion", "sextillion",
                              "septillion", "octillion", "nonillion",
                              "decillion" };

    if (n < 0)
        return "negative " + to_words(-n);
    else if (power == 0) {
        if (n < 20)
            return BASIC[n];
        else if (n < 100)
            return TENS[n/10] + (n%10 ? " "+to_words(n%10) : "");
        else if (n < 1000)
            return to_words(n/100) + " hundred"
                                   + (n%100 ? " "+to_words(n%100) : "");
    }

    return ( n/1000 ? to_words(n/1000, power+3) : "" )
           + ( n/1000 && n%1000 ? " " : "" )
           + ( n%1000 ? to_words(n%1000) + (power ? " "+POWERS[power/3-1] : "")
                      : "" );

    return "";
}

