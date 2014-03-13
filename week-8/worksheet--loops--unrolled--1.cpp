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
    // --- while loop ---

    {
        int i = 0;
        while (i < 5) {
            cout << i << " ";
            i++;
        }

        cout << endl;
    }

    // --- unrolled ---

    {
        int i = 0;

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
            }
        }

        cout << endl;
    }

    return 0;  // success
}

