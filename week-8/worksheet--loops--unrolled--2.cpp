/**
 * group members:
 * week 8
 * worksheet
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    // --- do-while loop ---

    {
        int i = 0;
        do {
            cout << i << " ";
            i++;
        } while (i < 5);

        cout << endl;
    }

    // --- unrolled ---

    {
        int i = 0;

        cout << i << " ";
        i++;

        if (i < 5) {
            cout << i << " ";
            i++;

            if (i < 5) {
                cout << i << " ";
                i++;

                if (i < 5) {
                    cout << i << " ";
                    i++;

                    if (i < 5) {
                        cout << i << " ";
                        i++;
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;  // success
}

