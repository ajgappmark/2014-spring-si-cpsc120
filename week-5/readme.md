# Week 5

**Important:** If you felt like last lab lost you a little bit, *now* is the
time to start reviewing before the test.  Go over the previous exercises at
home, and try writing test programs (like the kind found in the exercises)
yourself until you're comfortable.  If you need help, please ask a friend, me,
Josh, the instructor, or whoever you're most comfortable with.  You can do it!
But you have to try.

**Important:** Today's exercise is also today's lab.  Please let the Professor
or me see your code before you submit it.  You will have 4 things all together
to turn in (on Titanium, preferably as separate files):
- example-1.cpp
- example-2.cpp
- example-3.cpp
- calculator.cpp

For each of these, before turning the file in, make sure to add a comment at
the top containing

0. Your name
0. The week ("week 5" today)
0. The name of the program (the same as the filename, except without the
   ".cpp" at the end)



## Contents

- Exercise
    - Setup
    - Simple Control Flow (`if`, `else`)
        - Example 1
        - Example 2
        - Example 3
    - Calculator
    - Challenge
- Continuing Challenges



## Exercise

Again, if you get done early, please help a friend :)


### Setup

You are now free to use any programming environment you wish for the exercise.
One environment may be better than another in some specific circumstance (e.g.,
if you're programming in Windows you probably want Visual Studio, and if you're
writing an app for your iPhone you probably want Xcode) but in general, now
that you've been exposed to two or three, it's up to you which you prefer :) .
- If you need instructions for using the terminal, please see [week-3's
  lab](../week-3/readme.md).
- If you need instructions for using Visual Studio, please see the lovely Word
  document Josh made up.  (If you're in the Tuesday section, you should have
  this already.  If not, please get it from someone who got it from someone who
  is :) I've seen it around on Thursday.)

Along with this newfound freedom, most any code you see from now on may be
copied and pasted, if you like, instead of you having to type it out yourself.
Just make sure you *understand* what you're putting in your program, or it'll
end up biting you later.  If you're not feeling confident with something, you
may wish to type it out yourself anyway, for practice.

Now, please get your favorite programming environment ready, so you can try out
the code below :)


### Simple Control Flow (`if`, `else`)

We have finally gotten to that part of the course where everything you haven't
seen before can be googled with relative ease.  Learning from the internet is a
skill I've found to be extremely valuable in programming, and for that reason
(and not because I'm lazy, I hope), you are going to teach yourself about
`if`/`else` statements today.

Visit [this page](http://www.cplusplus.com/doc/tutorial/control/) (on
cplusplus.com) and read *only* the intro (at the top) and the section titled
"Selection statements: if and else".  (Reading more won't hurt you, but we'll
cover that stuff later.)  If you don't understand something, ask :) .

#### Example 1

Consider the following code:
```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;  // to store the user's integer

    cout << "Please enter an integer: ";
    cin >> x;

    if (x < 0) {
        cout << "Your integer is negative\n";
    } else if (x < 100) {
        cout << "Your integer is fairly small\n";
    } else {  // x >= 100
        cout << "Your integer is fairly large\n";
    }

    return 0;  // success
}
```

- Read this program very carefully, run it a few times with different values
  (try `-4`, `42`, and `100`, if you like), and get a feel for what it's doing.
  Especially, think about which values cause which outputs.  When you're sure
  that you know what the program will do for any output, then continue.

- Change the program so that it only outputs "Your integer is fairly large"
  with the integer is greater than or equal to 1000.

Now we wish to be able to tell the user where their integer is even or odd, in
addition to whether it is large or small.  Recall that the modulus operator,
`%`, returns the remainder after the left hand number is divided by the right
hand one, so that `3 % 2` gives the remainder after 3 is divided by 2, which
equals 1.  We write:
```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;  // to store the user's integer

    cout << "Please enter an integer: ";
    cin >> x;

    if (x < 0) {
        cout << "Your integer is negative\n";

        if (x % 2 == 0)
            cout << "Your integer is even\n";
        else
            cout << "Your integer is odd\n";

    } else if (x < 1000) {
        cout << "Your integer is fairly small\n";

        if (x % 2 == 0)
            cout << "Your integer is even\n";
        else
            cout << "Your integer is odd\n";

    } else {  // x >= 1000
        cout << "Your integer is fairly large\n";

        if (x % 2 == 0)
            cout << "Your integer is even\n";
        else
            cout << "Your integer is odd\n";
    }

    return 0;  // success
}
```

- Read this program carefully as well.  Make sure you know what it will do for
  any input you can think of.

- Notice that, when we have only one statement inside the body of our if
  statement, we don't need the braces (`{` and `}`), so that
  ```C++
  if (x < 0) {
      cout << "Your integer is negative\n";
    }
  ```
  is the same as
  ```C++
  if (x < 0)
      cout << "Your integer is negative\n";
  ```

- Also notice that we may have if statements inside of one another; these are
  called *nested if statements*.

- Finally, notice that we do not put a semicolon after the ending `}` of our if
  statement, but we do put a semicolon after each statement inside the body of
  the if statement.

- Remember that if there is more than one statement inside the body of the if,
  you **always** need braces.

Repeated (copy and pasted) code is kind of lame though.  We have
```C++
if (x % 2 == 0)
    cout << "Your integer is even\n";
else
    cout << "Your integer is odd\n";
```
repeated three times in our code above!  Not cool.

- Delete this repeated code from the body of each if statement, and then put it
  back into the program *only once*, right before the `return 0;`.  The program
  should do the same thing.  If it doesn't, that's okay: keep working on it
  till it does.

Finally, we also want to know whether the integer is evenly divisible by 3.  We
know that if an integer is evenly divisible by 3, the remainder when that
integer is divided by 3 will be 0.  Add to your program so that when the user
enters `5`, the output looks like this:
```
Please enter an integer: 5
Your integer is fairly small
Your integer is odd
Your integer is not evenly divisible by 3
```

Once you're done (and not before) take a look at
[example-1.cpp](./example-1.cpp).  Your program should look something like this
:) -- but if it doesn't, that's okay, as long as it works, and you like the way
it looks.

If you notice anything you need to fix, you can fix it.  Once you have
something working (but *not* directly copied from the solution on github, lol),
set the file aside, for turning in at the end of this exercise.  Be sure to
name it appropriately, and don't forget to put your name and stuff at the top.

#### Example 2

Imagine you ask the user to enter a character.  You want to tell them whether
it was a symbol, a number, an upper case character, a lower case character, or
none of those things.  Take a look at [this ASCII
table](http://www.asciitable.com).  We start out by writing:
```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    char c;  // to hold a character, entered by the user

    cout << "Please enter a character: ";
    cin >> c;

    if ( (c >= 33 && c <= 47) || (c >= 91 && c <= 96)
                              || (c >= 123 && c <= 126) ) {

        cout << "'" << c << "' is a symbol\n";

    } else if ( c >= 48 && c <= 57 ) {

        cout << "'" << c << "' is a number\n";

    } else if ( /* TODO: condition indicating c is an upper case character */ ) {

        /* TODO: cout statement for c is an upper case character */

    } else if ( /* TODO: condition indicating c is a lower case character */ ) {

        /* TODO: cout statement for c is a lower case character */

    } else {
        cout << "'" << c << "' is not in any of our categories\n";
    }

    return 0;  // success
}
```

- Fill in the code that should be in place of the `/* TODO: ... */` comments.

- Test your program thoroughly (enter as many random inputs as you can think
  of) to make sure it works.

- If you're not sure about something, ask :)

Once you're done, set this file aside as well.  You will be turning it in also.

#### Example 3

This one's for review, and practice.

So, I'm sitting beside you and I wrote the following code.  But it won't
compile!  And I don't know why.  I am not happy.  What did I do wrong?

```C++
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
         << " (1, 2, 3, or 4): "
    cin >> choice;

    cout << "\n";

    cout << "-----------------------------------------"
         << "--------------------------------------\n";

    if (choice == 1) {
        cout << "It was the best of times,\n"
             << "it was the worst of times,\n"
             << "it was the age of wisdom,\n";
             << "it was the age of foolishness,\n"
             << "it was the epoch of belief,\n"
             << "it was the epoch of incredulity,\n"
             >> "...\n"
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
```

Hints:
- It was working, but I changed precisely 3 things (a total of 1 character
  removed, 1 character added, and 2 characters replaced).
- Start with the topmost error message, and *read it carefully*!  Sometimes
  many of the error messages are because of only one error.
- Notice what line number it says the error is on, and look near there for
  anything that seems wrong.  Try not to guess, if you can help it: think
  carefully first, and try to remember what you've seen thus far in working
  programs.
- One of the errors might be masking another.  If you fix something that you
  know was wrong, and that makes the compiler generate *more* error messages,
  that's okay.

Once it's working, set the corrected (compiling and correctly running) file
aside for turning in.  Be sure to name it appropriately, and add your name and
stuff to the top of this one too.


### Calculator

Try to do this one, as much as possible, without looking at your notes or
anything else.  In general, it's a very good habit to look up things you're not
sure of online, but for this particular program, if you're stuck, please try to
ask a friend first.

Combining the things we've learned thus far, write a program that:
- Asks the user for an integer
- Asks the user for one of '+', '-', '\*', or '/' (as a character)
- Asks the user for another integer
- Performs the given operation on the two integers, and prints out the result

Sample run:
```
Please enter an integer: 4
Please enter an operation (+, - , *, /): *
Please enter another integer: 5

4 * 5 = 20
```

Notes:
- You may assume, for now, that the user inputs the correct type of data (i.e.,
  that you don't have to check for errors when reading from `std::cin`).
- It's fun to think that what this program does is really the beginning of how
  interpreted languages (like Python) work.  Another example is the unix
  program bc.  Try typing `bc` into the terminal; then type a few math
  expressions (like `4 * 5`), pressing "enter" after each one; type ctrl+d, or
  `quit` when you're done :)

When you're done, be sure to name the file correctly, put your name and stuff
at the top, and set the file aside for turning in.


### Challenge

You may turn these files in as well, if you like, but you don't need to.  If
you do, please use non-confusing names :) (like `calculator--challenge-1.cpp`
or so).

Keeping one file for each new version of the program, do the following:

0. Look up switch statements, and rewrite the "calculator" program using those.
0. Try adding `^` as an operator, for exponentiation.
0. Now switch to using `**` for exponentiation (like Python does).
    - Can you still use use a `char` variable to store your operator, and a
      switch statement to decide on the appropriate action?
0. If you haven't already, make exponentiation work with fractional exponents
   :)
    - What trade-offs does your approach make?



## Continuing Challenges

- [Learn how to use Git](http://git-scm.com/documentation)

- Lean how to use Vim (type `vimtutor` into the terminal, and follow the
  instructions)

- [Learn Python](http://docs.python.org/3.3/tutorial/)

- Learn [one of the languages on codecademy] (http://www.codecademy.com)
    - Especially Python, Ruby, or JavaScript
    - Someone showed this to me during week-4's lab :)



-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

