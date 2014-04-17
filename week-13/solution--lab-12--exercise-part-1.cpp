/**
 * ben blazak
 * week 12
 * array exercise part 1
 */


#include <cstdlib>
// rand()
// srand()

#include <ctime>
// time()

#include <iostream>
using std::cout;
using std::endl;


int main() {
    // declare an array with 100 elements
    int a[100];

    // seed the random number generator
    srand(time(NULL));

    // initialize the array with 100 random values
    for (int i=0; i<100; i++)
        a[i] = rand()%999;

    // - print out all the elements of array `a`, with a space between each
    for (int i=0; i<100; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    // - print the smallest element of array `a`
    // - print the largest element of array `a`
    // - print the sum of all the elements in array `a`
    // - print the average of all the elements in array `a`
    int smallest;
    int largest;
    int sum;
    double average;

    // start by assuming that the first element is the smallest and the
    // largest.  then look through the array to see if we can find an element
    // that's smaller than the smallest one we know about, or larger than the
    // largest one we know about.  also keep track of the sum of all the
    // elements as we go along.  we'll use this to calculate the average
    // afterwards.
    smallest = a[0];
    largest = a[0];
    sum = a[0];
    for (int i=1; i<100; i++) {
        if (a[i] < smallest)
            smallest = a[i];

        if (a[i] > largest)
            largest = a[i];

        sum += a[i];  // this only works because `i` started at `1`
    }

    average = sum/100;

    cout << "smallest: " << smallest << endl;
    cout << "largest: " << largest << endl;
    cout << "sum: " << sum << endl;
    cout << "average: " << average << endl;

    return 0;
}

