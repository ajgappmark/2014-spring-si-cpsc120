# Week 13

## Contents

- Exercise: Selection Sort
    - Part 1: Implementation
    - Part 2: Measuring Performance
- Continuing Challenges



## Exercise: Selection Sort

### Part 1: Implementation

**Please don't look this up online.  It's easy to find (in fact, it's mostly on
wikipedia, if you're going to look it up anyway) but you'll learn more if you
struggle throuh it.  Thanks :)**

Selection sort, as we covered in class, is an O(n^2) sorting algorithm (more on
that later) with the following high-level pseudocode:

1. Use a variable to keep track of the first unsorted element in the list (or
   the last sorted element; up to you).  Initially, the first element (element
   `0`) will be the first unsorted element, because the whole list is unsorted.
2. Find the smallest element in the part of the list that has not yet been
   sorted
3. Move this element to the beginning of the unsorted part of the list
4. Update your variable so that this element is now considered to be in the
   sorted part of the list (i.e. increment the variable)
5. If the whole list is not yet sorted, go back to step 2

Write a program that does the following:
- Create an array of 10 integers, and initialize each element to a random value
  in the range \[0, 999\] (i.e., in between 0 and 999, inclusive).
- Print out the contents of the array
- Sort the array using selection sort
- Print out the contents of the array again

Challenge:
- Write your selection sort as a function, which you call from main()

Hints:
- You will probably want to be using a nested for loop when writing your
  selection sort.
- If you haven't seen it before, you may also want to look up how to swap
  variables (this part's okay to look online for; but maybe you could *try* to
  figure it out, just to make me extra happy :) )


### Part 2: Measuring Performance

Using (mostly) the code that you wrote for Part 1, fill in the TODO sections of
the following code (note that we're *not* printing the contents of the array
this time):
```C++
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


int main() {
    // TODO: declare and initialize your array

    // start the clock
    clock_t time_begin = clock();

    // TODO: sort the array

    // stop the clock
    clock_t time_end = clock();

    // output the size of the array and the amount of time taken
    cout << "size of the array: " << size << "\n";
    cout << "time taken to sort the array: "
         << double(time_end - time_begin) / CLOCKS_PER_SEC
         << " seconds\n";

    return 0;  // success
}
```

Now use this program to test how long your selection sort algorithm takes for
arrays of various sizes :) .  You should notice that doubling the size of the
array roughly squares the time that selection sort takes to complete.  This is
why selection sort is called an O(n^2) algorithm: because the time it takes to
run is proportional to the square of the number of elements in the list.  There
are faster algorithms for sorting, but they're a bit more complicated.  If
you're a CS major, you'll get to them soon :) .

Paste a copy of the terminal output in a comment at the bottom of your program
before you turn it in.

Sample output (on my laptop):
```
ben@ben-mba:~/Desktop/lab-13$ clang++ selection-sort-timed.cpp; ./a.out
size of the array: 25000
time taken to sort the array: 0.805903 seconds
ben@ben-mba:~/Desktop/lab-13$ clang++ selection-sort-timed.cpp; ./a.out
size of the array: 50000
time taken to sort the array: 3.22144 seconds
ben@ben-mba:~/Desktop/lab-13$ clang++ selection-sort-timed.cpp; ./a.out
size of the array: 100000
time taken to sort the array: 12.7209 seconds
```



## Continuing Challenges

- [Learn how to use Git](http://git-scm.com/documentation)

- Lean how to use Vim (type `vimtutor` into the terminal, and follow the
  instructions)

- [Learn Python](http://docs.python.org/3.3/tutorial/)

- Learn [one of the languages on codecademy] (http://www.codecademy.com)
    - Especially Python, Ruby, or JavaScript

- Write a [bash script](http://www.tldp.org/LDP/abs/html/) (or an [expect
  script](http://w2home.blogspot.com/2007/11/expect-tutorial.html) if you're
  feeling *super* ambitious) (or an [applescript
  script](http://macosxautomation.com/applescript/firsttutorial/index.html) if
  you like) to automate the testing of the code in this project for you.
    - There may be better tutorials for expect and applescript; I have a lot of
      experience with the page linked above for bash scripting though, and IMO
      it's really good.
    - Necessarily, this is a Linux / Mac / Cygwin (on Windows) only challenge.



-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

