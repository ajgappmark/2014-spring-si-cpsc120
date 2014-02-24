# Week 6

## Contents

- Instructions
- Exercise
    - Setup
    - Review: Boolean Expressions
    - Warm-up: Broken Code
    - Predefined Functions (a.k.a Library Functions)
    - User Defined Functions
- Challenge
- Continuing Challenges



## Instructions

- Once again, today's exercise is also today's lab.  Please make sure to let
  the professor see your code before you submit it, so he can check you off.

- For each of the files, before turning it in, make sure to add a comment at
  the top containing

  0. Your name
  0. The week ("week 6" today)
  0. The name of the program (preferably either the name of the section the
     file corresponds to below, or same as the filename except without the
     ".cpp" at the end)



## Exercise

### Setup

Create the following files, for turning in later, and for use in each
subsection below:

0. bool.cpp
0. broken.cpp
0. predefined.cpp
0. user.cpp

- If you're using Visual Studio, you'll have to do this manually, in whatever
  way you prefer.

- If you're using the Terminal, you can copy and paste the following to create
  a new directory on your desktop with the desired files inside:
  ```bash
  mkdir ~/Desktop/lab-6
  cd ~/Desktop/lab-6
  touch bool.cpp broken.cpp predefined.cpp user.cpp
  ```

    - If you open a new terminal sometime later, you can navigate back to this
      directory with the `cd` ("change directory") command, as in
      ```bash
      cd ~/Desktop/lab-6
      ```

    - To stop a running program, press Ctrl+C.

    - If it's helpful, note that there are many different ways of compiling and
      running your program.  For example,
      ```bash
      clang++ bool.cpp
      ./a.out
      ```
      does the same thing as
      ```bash
      clang++ bool.cpp -o bool
      ./bool
      ```
      which does the same thing as
      ```bash
      clang++ -o bool bool.cpp
      ./bool
      ```
      which does the same thing as
      ```bash
      clang++ bool.cpp -o my-compiled-bool-program
      ./my-compiled-bool-program
      ```
      except that the `-o` flag changes the name of the executable file
      generated.  Also, it's possible to combine both commands on the same line
      if you like, as in
      ```bash
      clang++ bool.cpp; ./a.out
      ```
      which may save you some time.

    - Note that `~` on the command line stands for "my home directory" -- which
      is the same as `$HOME` (try typing `echo ~` and `echo $HOME` on the
      command line, and notice that their output is the same).  For example,
      writing `cd ~/Desktop/lab-6` is the same as writing `cd
      $HOME/Desktop/lab-6`.  If your current working directory is your home
      directory (which it should be when you first open Terminal.app on a Mac),
      you could leave `~` out entirely, just typing `cd Desktop/lab-6`.

    - For general knowledge, also note that we only `cd` into the directory
      where our files are to save a bit of typing.  If your files are in
      `~/Desktop/lab-6` and you want to compile the one named `bool.cpp` you
      could type `clang++ ~/Desktop/lab-6/bool.cpp` no matter what your current
      working directory was, and it would work quite happily.


### Review: Boolean Expressions

Use `bool.cpp`.

We'll begin with a review of boolean expressions.  See the code below, and
follow the instructions in the comments.

Notes:
- General:
    - Notice that `int i;` and `char c;` are declared many times.  We are able
      to do this because of *block scoping*.  Observe that each of these
      variables is declared inside a set of braces (`{ ... }`).  Variables
      declared this way are said to be *local* to the block of code between the
      braces.  Once program execution goes outside their block, block scoped
      variables are said to be *out of scope*: the program frees their memory,
      and the compiler allows us to reuse their variable names.
- Part 4:
    - See
      [a handy ASCII table](http://web.cs.mun.ca/~michael/c/ascii-table.html)
      if you don't have a photographic memory :)
    - Remember, for each character you can use either the numeric value or the
      character literal.
- Part 5:
    - If you're good with this, see [the hint](./hint--bool--part-5.cpp)
      afterwards anyway, for an alternate method :) .
    - If you're not quite sure where to start, that's okay.  Take a look at
      [the hint](./hint--bool--part-5.cpp) right now :) .

Tips:
- [This page](http://www.cplusplus.com/doc/tutorial/operators/) and [this
  page](http://www.tutorialspoint.com/cplusplus/cpp_operators.htm) appear to
  have good lists of logical and relational operators, if you find that
  helpful.
- While you're working, you may wish to comment out the portions of the code
  you're not working with, so they don't get in the way.  Don't forget to
  uncomment them after you're done.

```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 1

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test whether it is 0: ";
        cin >> i;

        // TODO:
        // - Fill in a correct expression in place of `true` in the conditional
        //   below, using exactly one relational operator.
        // - Remove the "TODO" portion of this comment once you're done.

        if (true)
            cout << "+++ You did not enter 0\n";
        else
            cout << "--- Ha! You did enter 0\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 2

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test whether it is 0: ";
        cin >> i;

        // TODO:
        // - Fill in a correct expression in place of `true` in the conditional
        //   below, without using any operators at all.
        // - Remove the "TODO" portion of this comment once you're done.

        if (true)
            cout << "+++ You did not enter 0\n";
        else
            cout << "--- Ha! You did enter 0\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 3

    {
        int i;  // to store input from the user

        cout << "Enter an integer to test divisibility: ";
        cin >> i;

        // TODO:
        // - Fill in a correct expression in place of `true` in the conditional
        //   below.
        // - Remove the "TODO" portion of this comment once you're done.

        if ( true )
            cout << "+++ The integer you entered is either divisible by 2 and"
                    " 3, or divisible by 5\n"
                 << "and 7, or both.\n";
        else
            cout << "--- The integer you entered is not divisible by 2 and 3,"
                    " or by 5 and 7, or\n"
                 << "both.\n";
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 4

    {
        char c;  // to store input from the user

        cout << "Enter a character to test whether it is a symbol: ";
        cin >> c;

        // TODO:
        // - *Without looking at last week's assignment*, fill in a correct
        //   expression in place of `true` in the conditional below.
        // - Remove the "TODO" portion of this comment once you're done.

        if ( true ) {

            cout << "+++ '" << c << "' is a symbol.\n";

        } else {

            cout << "--- '" << c << "' is not a symbol.\n";

        }
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------
    // part 5

    {
        int a, b, c;  // to store 3 integers from the user

        cout << "Enter 3 integers, separated by spaces: ";
        cin >> a >> b >> c;

        cout << "The largest of these integers is: ";

        // TODO:
        // - Output the largest of the 3 integers input by the user (probably
        //   using if statements).
        // - Remove the "TODO" portion of this comment once you're done.
    }

    cout << "\n-----------------------------------------"
         << "--------------------------------------\n\n";

    // ------------------------------------------------------------------------

    return 0;
}
```


### Warm-up: Broken Code

Use `broken.cpp`.

See the code below.  There may be many errors you can spot without trying to
compile (and in general it'd probably be a good idea to start by fixing those
first) but for this program specifically, please compile and test and only fix
things that you've proved are broken.  You may (or may not, I suppose) learn
something new :) .

Also, There are things in this file that we haven't seen before -- you can look
them up if you like (we'll get to them later in class) -- but we have seen
everything needed to fix things.

Finally, beware the logic error(s)!  Test thoroughly.

```C++
#include <iostraem>
using std::cout;
using std::endl;

int main() {
    char choie;  // for the user's input


    // prompt for the user's choice
    // - in this small block specifically, some things are unnecessary (and
    //   therefore not the best coding practice).  but do they cause compiler
    //   errors? :)

    cout << "Do you like" 
            " green eggs and ham?" ""
         << "Enter 'y' or 'Y' for"
            " yes, 'n' or 'N' for no: ";
    cin >> choice;;

    cout << endl;


    // respond to the user's choice!

    if (choice == 'y' || 'Y')
        cout << "Me too!\n;
    else if (choice == 'n' || 'N')
        cout << "Me neither?\n";
    else {
        cout << "I don't understand :(\n";

    cout << endl;


    // analyze the user's choice

    switch (choice) {
        case 'y':
        case 'n': cout << "You entered a lower case letter.\n"; break;
        case 'Y':
        case 'N': cout << "You entered an upper case letter.\n"; break;
        default: cout << "You entered an invalid letter!\n"; break;
    }

    cout << endl;


    // print the letters from 'A' or 'a' to the user's choice, or exit if the
    // user's choice was invalid

    char start;  // the character to begin printing from

    if (choice == "Y" || "N") {
        start = 'A';
    } else if (choice == "y" || "n") {
        start = 'a';
    } else {
        cout << "I am unhappy.  Terminating.\n";
        return 1;  // error
    }

    cout << "The letters from '" << start << "' to '" << choice << "' are:\n";

    for (char c=start; c<=choice; c++)
        cout << c >> " ";

    cout << endl;


    return 0;  // success
}
```

Hints:
- There is precisely 1 line missing.
- There are precisely 4 lines with logic errors.
- There are precisely 7 lines with syntax or other errors.
- Some lines may have more than one kind of error, but none have more than one
  of the same type of error.
- Remember that `||` is a binary operator -- i.e. that it takes exactly two
  arguments (one on the left and one on the right) and returns either `true` or
  `false`.
- Recall that most anything nonzero (even nonzero characters) is considered
  `true` in a boolean context.


### Predefined Functions (a.k.a. Library Functions)

Use `predefined.cpp`.

TODO: like pow() :)

TODO: extend the lab-5 calculator challenge 4 to implement a whole bunch of
stuff from \<cmath\> lol :)
TODO: and ask for the input all on one line (space separated)


### User Defined Functions

Use `user.cpp`.

TODO: like implementing abs() (with conditionals!)

TODO: probably abstracting what they did with the calculator program the week
before, making functions for each operation, rather than performing it in place



## Challenge

Write a [bash script](http://www.tldp.org/LDP/abs/html/) (or an [expect
script](http://w2home.blogspot.com/2007/11/expect-tutorial.html) if you're
feeling *super* ambitious) (or an [applescript
script](http://macosxautomation.com/applescript/firsttutorial/index.html) if
you like) to automate the testing of the code in this project for you.

- There may be better tutorials for expect and applescript; I have a lot of
  experience with the page for bash scripting though, and IMO it's really good.

- Necessarily, this is a Linux / Mac / Cygwin (on Windows) only challenge.



## Continuing Challenges

- [Learn how to use Git](http://git-scm.com/documentation)

- Lean how to use Vim (type `vimtutor` into the terminal, and follow the
  instructions)

- [Learn Python](http://docs.python.org/3.3/tutorial/)

- Learn [one of the languages on codecademy] (http://www.codecademy.com)
    - Especially Python, Ruby, or JavaScript



-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

