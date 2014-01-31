/**
 * Author : Ben Blazak
 * Date   : 2014-01-26
 *
 * This is a test program to use when illustrating what happens to a bit of C++
 * code when it is
 * 1) preprocessed
 * 2) converted to assembly
 * 3) compiled into an object file
 * 4) linked into an executable
 */

// ----------------------------------------------------------------------------
// version 0
//
// This is the version we saw in class.
// ----------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    cout << "hello world\n";
    return 0;
}

// ----------------------------------------------------------------------------
// version 1
//
// This version has no "using namespace std;", but does use "std::cout" instead
// of "cout".
//
// Notes:
// - In the classroom, "using namespace std;" is almost always used.  In the
//   real world, I've read that it's considered bad practice.  You should be
//   aware that there are different ways to do things.  If the instructor
//   cares, of course, you kind of have to write it how they wish.  Past that
//   though, just think about who you're writing for -- whether it's your
//   friend (because what friend doesn't want to see your C++ projects? duh),
//   or your future self in a few months when you're studying for your midterm.
//   Think about what they would find prettier and easier to read, and write it
//   that way.
// ----------------------------------------------------------------------------

/*
#include <iostream>

int main() {
    std::cout << "hello world\n";
    return 0;
}
*/

// ----------------------------------------------------------------------------
// version 2
//
// This version uses macros to define the message we print to stdout and the
// value (the integer, or "int") we return to the operating system.
// ----------------------------------------------------------------------------

/*
#include <iostream>  // needed for std::cout

#define  MESSAGE       "hello world\n"
#define  RETURN_VALUE  0

int main() {
    std::cout << MESSAGE;
    return RETURN_VALUE;
}
*/

// ----------------------------------------------------------------------------
// version 3
//
// Here, we only return a value, we don't "cout" anything.  As a consequence we
// do not need the "#include <iostream>" at the beginning.  How does this
// effect the generated files?
// ----------------------------------------------------------------------------

/*
int main() {
    return 0;
}
*/

// ----------------------------------------------------------------------------
// version 4
//
// What if we return a value other than 0?
//
// Notes:
// - In real code, returning anything other than 0 from main() usually means
//   that an error occurred.
// - Notice that 42 and 0 are both integers.  The "int" in front of "main()" is
//   what tells the compiler that we're planning to return an integer.  Since
//   main() is a special function -- it's the function that the operating
//   system calls when you ask it to run your program by typing "./run.sh" or
//   "./test.exe" into the terminal -- it must have this signature (i.e. it
//   must return an integer).  Other functions can return different things.
// ----------------------------------------------------------------------------

/*
int main() {
    return 42;
}
*/

// ----------------------------------------------------------------------------
// version 5
//
// This version has a "return" before our "cout".
// ----------------------------------------------------------------------------

/*
#include <iostream>

int main() {
    return 0;
    std::cout << "hello world\n";
}
*/

// ----------------------------------------------------------------------------
// version 6
//
// Wait, we can have more than one "return"?  And more than one "cout"?
// ----------------------------------------------------------------------------

/*
#include <iostream>

int main() {
    std::cout << "hello world 1\n";
    return 1;
    std::cout << "hello world 2\n";
    return 2;
    std::cout << "hello world 3\n";
    return 3;
}
*/

// ----------------------------------------------------------------------------
// version 7
//
// Variables :) -- like in math, variables are names that can be assigned
// different values.
//
// What value is returned?
// ----------------------------------------------------------------------------

/*
int main() {
    int return_value = 5;
    return return_value;
}
*/

// ----------------------------------------------------------------------------
// version 8
//
// Another example about variables.  More on variables later.
// ----------------------------------------------------------------------------

/*
int main() {
    int return_value;
    return_value = 5;
    return_value = 6;
    return return_value;
    return_value = 7;
}
*/

