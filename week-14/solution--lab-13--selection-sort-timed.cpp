/**
 * ben blazak
 * week 13
 * timed version of solution to selection sort exercise
 */


// ----------------------------------------------------------------------------
// includes
// ----------------------------------------------------------------------------

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::clock;
using std::clock_t;
using std::time;

#include <iostream>
using std::cout;
using std::endl;


// ----------------------------------------------------------------------------
// helper functions
// ----------------------------------------------------------------------------

/**
 * Sort the array, using the selection sort algorithm.
 *
 * Arguments:
 * - array: the array to sort
 * - length: the number of elements in the array
 *
 * Variable names used:
 * - sorted: the index of the first unsorted element of the array
 * - smallest: the index of the smallest (known) element of the array
 * - tested: the index of the first element of the array we have not yet tested
 *   to see if it is smaller than `array[smallest]`
 *
 * Notes:
 * - Since arrays are really pointers to the first element of the array (see
 *   the notes on github for last week), if we pass the array, what we're
 *   really passing is a pointer to the first element of the array.  In C++,
 *   variables that are not "passed by reference" (which you'll get to in CS
 *   121) are "passed by value", meaning they are copied.  In this case, the
 *   pointer to the first element of the array is indeed copied -- but the
 *   array is not copied, and remains in the same location in memory.
 *   Therefore, when we modify the array inside the function, we are modifying
 *   the same memory locations make up the array that is visible in the main()
 *   function.  You may sometimes hear people say that in cases like this the
 *   array is "shallow copied" when passed to the function.
 */
void selection_sort(int array[], int length) {
    for (int sorted = 0; sorted < length; sorted++) {

        int smallest = sorted;

        for (int tested=sorted; tested < length; tested++) {
            if (array[tested] < array[smallest]) {
                smallest = tested;
            }
        }

        // put the smallest element we found in the unsorted portion of the
        // list into the first unsorted position in the list, by swapping
        // `array[smallest]` with `array[sorted]`
        int temp = array[smallest];
        array[smallest] = array[sorted];
        array[sorted] = temp;
    }
}


// ----------------------------------------------------------------------------
// main()
// ----------------------------------------------------------------------------

int main() {
    // declare a constant for the size of the array, so we can easily change
    // it, and test with larger arrays :)
    const int size = 25000;

    // declare an array with `size` elements
    int a[size];

    // seed the random number generator
    srand(time(NULL));

    // initialize the array with `size` random values
    for (int i=0; i<size; i++)
        a[i] = rand()%999;

    // start the clock
    clock_t time_begin = clock();

    // sort the array
    selection_sort(a, size);

    // stop the clock
    clock_t time_end = clock();

    // output the size of the array and the amount of time taken
    cout << "size of the array: " << size << "\n";
    cout << "time taken to sort the array: "
         << double(time_end - time_begin) / CLOCKS_PER_SEC
         << " seconds\n";

    return 0;  // success
}

