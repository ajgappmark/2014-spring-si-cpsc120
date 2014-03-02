/**
 * Ben Blazak
 * week 8
 * worksheet -- truth tables
 */

#include <iostream>
using std::cout;

int main() {

    cout << "\n\n";

    cout << " true   false   bool(-2)   bool(-1)   bool(0)   bool(1)   bool(2)   bool(3)\n"
         << " ----   -----   --------   --------   -------   -------   -------   -------\n"
         << "   "        << ( true )
         << "      "     << ( false )
         << "         "  << ( bool(-2) )
         << "          " << ( bool(-1) )
         << "         "  << ( bool(0) )
         << "         "  << ( bool(1) )
         << "         "  << ( bool(2) )
         << "         "  << ( bool(3) )
         << "\n";

    cout << "\n\n";

    cout << " bool('\\0')  bool('y')  bool('n')  bool(\"yes\")  bool(\"no\")  bool(\"hello\")\n"
         << " ----------  ---------  ---------  -----------  ----------  -------------\n"
         << "      "       << ( bool('\0') )
         << "          "   << ( bool('y') )
         << "          "   << ( bool('n') )
         << "           "  << ( bool("yes") )
         << "            " << ( bool("no") )
         << "            " << ( bool("hello") )
         << "\n";

    cout << "\n\n";

    cout << " bool(-5.7)   bool(0.0)   bool(5.7)   bool(42.8)\n"
         << " ----------   ---------   ---------   ----------\n"
         << "      "   << ( bool(-5.7) )
         << "           "  << ( bool(0.0) )
         << "           "  << ( bool(5.7) )
         << "            " << ( bool(42.8) )
         << "\n";

    cout << "\n\n";

    cout << " a   b   a == b   a != b   a && b   a || b\n"
         << " -   -   ------   ------   ------   ------\n";
    for (int a=0; a<=1; a++)
        for (int b=0; b<=1; b++)
            cout << " "       << ( a )
                << "   "      << ( b )
                << "      "   << ( a == b )
                << "        " << ( a != b )
                << "        " << ( a && b )
                << "        " << ( a || b )
                << "\n";

    cout << "\n\n";

    cout << " a   b   a == b && 'y'   a == b || 'y'   a != b && 'y'   a != b || 'y'\n"
         << " -   -   -------------   -------------   -------------   -------------\n";
    for (int a=0; a<=1; a++)
        for (int b=0; b<=1; b++)
            cout << " "               << ( a )
                 << "   "             << ( b )
                 << "         "       << ( a == b && 'y' )
                 << "               " << ( a == b || 'y' )
                 << "               " << ( a != b && 'y' )
                 << "               " << ( a != b || 'y' )
                 << "\n";

    cout << "\n\n";

    cout << " a  b  c  a == b && a == c  a == b || a == c  a != b && a != c  a != b || a != c\n"
            " -  -  -  ----------------  ----------------  ----------------  ----------------\n";
    for (int a=0; a<=1; a++)
        for (int b=0; b<=1; b++)
            for (int c=0; c<=1; c++)
                cout << " "                 << ( a )
                     << "  "                << ( b )
                     << "  "                << ( c )
                     << "          "        << ( a == b && a == c )
                     << "                 " << ( a == b || a == c )
                     << "                 " << ( a != b && a != c )
                     << "                 " << ( a != b || a != c )
                     << "\n";

    cout << "\n\n";

    return 0;
}

