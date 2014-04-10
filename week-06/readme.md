# Week 6

## Contents

- Instructions
- Exercise
    - Setup
    - Review: Boolean Expressions
    - Warm-up: Broken Code
    - Predefined Functions (a.k.a Library Functions)
    - Preview: User Defined Functions
- Challenge
- Continuing Challenges



## Instructions

- Once again, today's exercise is also today's lab.  Please make sure to let
  the professor see your code (and show him that it works correctly) before you
  submit it, so he can check you off.

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

Start with
[the calculator program](./solution--lab-5--calculator.cpp)
from last week (or your solution, if you prefer), and modify it to
- ask for the user to enter their equation all at once (i.e., as "4 * 5", with
  each piece separated by whitespace) instead of prompting for each piece
  separately.
- read in `double`s instead of `int`s.
- read in a `string` instead of a `char` for the operator.

You will need to use a `string` member function to compare strings for
equality; see the references below.  If you get a little stuck, you can see
[a solution for challenge 4](./solution--lab-5--calculator--challenge-4.cpp)
from last week.

After you're done with that, see the references below for the cmath library (or
look it up online yourself), and add the following operator to your calculator:
- `**` for exponentiation

Again, you can see
[a solution for challenge 4](./solution--lab-5--calculator--challenge-4.cpp)
from last week if you get a little stuck.

At this point, we're going to do something a little different.  Most of the
functions in cmath are unary -- that is, they only accept one argument (one
number) (like sqrt(), which accepts one number and returns its square root, as
in `sqrt(9)` which returns `3`).  But our calculator right now only accepts
expressions in the form `4 * 5` or `1 / 3` (that is, it only accepts
expressions using binary operators).  To fix this, we'll use a function called
cin.peek() (take a look at the references below for documentation).  This
function "peeks" at the first character in the input stream, without actually
reading it in.

Delete the line(s) you're currently using to read in the user's input, and in
its place put the following code (to ignore all initial whitespace on the input
stream):
```C++
// ignore all initial whitespace
while (    cin.peek() == ' '  || cin.peek() == '\t'
        || cin.peek() == '\n' || cin.peek() == '\v'
        || cin.peek() == '\f' || cin.peek() == '\r' )
    cin.get();
```
Directly below this (using `cin.peek()` to read the next character on the input
stream without consuming it), write some if/else statements that do the
following:
- If the first character on the input stream is a lower case letter
    - Read in the operation and the single number following it
        - In this case, user input should look like "sqrt 9" or "ln 5"
    - Output the expression given by the user, followed by an equals sign
        - That is, if the user enters "   sqrt   5", the program should output
          "sqrt 5 = "
        - Since we're handling two different kinds of expressions, it's more
          convenient to do this here, inside the if/else block where we're
          reading things in, than it is to do this later
- Otherwise, if the first character on the input stream in a number or the
  negative sign ('-')
    - Read in the number, the operation, and the following number
        - In this case, user input should look like "4 * 5" or "1 / 3", as
          before
    - Output the expression given by the user, followed by an equals sign
        - That is, if the user enters "   4   * 5", the program should output
          "4 * 5 = "
- Otherwise
    - Output an error message
    - Return `1` (or something other than `0`)
        - Since we weren't able to read in any valid input, we really shouldn't
          execute the rest of the program, in this case.

Note that there are (many) other ways to accomplish the same thing.  This is
the simplest way I was able to come up with :) .

Now add the following unary operators to your calculator (again from the cmath
library, though they may have different names there):
- `ln` for the natural logarithm
- `sqrt` for square root
- `sin` for the trig function
- `cos` for the trig function
- `tan` for the trig function

Be sure to change your prompt to ask for an equation in either of the forms we
can now accept (like `4 * 5` or `ln 5`).

Yay!  Our calculator is now pretty cool :)

References:
- [Documentation for the `string` type]
  (http://en.cppreference.com/w/cpp/string/basic_string)
    - Especially see the member function
      [compare](http://en.cppreference.com/w/cpp/string/basic_string/compare).
- [Documentation for the `<cmath>` header]
  (http://en.cppreference.com/w/cpp/header/cmath)
- [Documentation for `cin.peek()`]
  (http://www.cplusplus.com/reference/istream/istream/peek/)

Sample runs:
```
Please enter an expression (like `4 * 5` or `ln 5`): 4 * 5
4 * 5 = 20
```
```
Please enter an expression (like `4 * 5` or `ln 5`): ln 5
ln 5 = 1.60944
```


### Preview: User Defined Functions

Use `user.cpp`.

In the subsection above, you saw how we included the cmath library (with
`#include <cmath>`) and called various functions (with, e.g., `pow(a,b)`.  A
few quick notes on functions in general:
- As in most of C++, whitespace is not significant.  That is `pow(2,3)` is the
  same as `pow ( 2 , 3 )`, etc.
- Function calls *always* need parenthesis.  If you write `pow()` (in source
  code), it means to call the function "pow" with no arguments (which according
  to [the documentation](http://en.cppreference.com/w/cpp/numeric/math/pow) is
  not allowed... the "pow" function requires exactly 2 arguments).  If you
  write `pow` it means a function pointer pointing to the function "pow",
  which, for now, is probably not what you want.
- When writing in English, I will sometimes, for example, talk about pow()
  without any quotation marks, or anything in the parenthesis, etc.  There are
  different conventions used by different people -- in general, when I write
  "pow()" in the context of a sentence, I mean "the function called 'pow'".
- Functions (in C++, and not in C) can be *overloaded*, meaning, there may be
  more than one function with the same name, as long as it can be uniquely
  identified by its arguments.  Take another look at [the documentation for
  "pow"](http://en.cppreference.com/w/cpp/numeric/math/pow).  Notice that there
  are different versions for `float`, `double`, etc., and that these different
  functions return different types.  For the most part, right now, we won't
  have to worry about that though, since we won't typically be overloading
  functions ourselves, and functions in the standard library that are
  overloaded are generally written in a very predictable way so that they "just
  work".

There are a lot of things about functions that we won't formally cover until
later.  For now please take a look at
[this tutorial](http://www.cplusplus.com/doc/tutorial/functions/)
if you like, and especially please take a careful look at a few examples below
of how we could have written our original calculator program.

```C++
// - Best to do all our `#include`s before defining any of our own functions,
//   in general
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// - These are called "function prototypes"; they let the compiler know that,
//   hey, there's a function (say "add" for example), that takes two integers
//   as arguments, and returns an integer.  And there's another function,
//   "divide" that takes two integers, and returns a double.
// - Function prototypes just like these (except for different functions) are
//   included in some of the headers we've been using, like cmath.  (Those
//   headers that don't have any function prototypes quite like this have
//   prototypes and definitions of other things, which you'll start learning
//   about probably in CS 120.)
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);


// - This is called a "function definition".  The function "main" doesn't need
//   a prototype, because the compiler already knows what it's signature is
//   (it's the only function *required* to be in every single C or C++ program)
int main() {
    int  a;          // to hold the user's first integer
    int  b;          // to hold the user's second integer
    char operation;  // to hold the user's operation

    cout << "Please enter an expression (like `4 * 5`): ";
    cin >> a >> operation >> b;

    cout << a << " " << operation << " " << b << " = ";

    // - I know we haven't really gone over "switch" statements yet, but it
    //   makes the code shorter.  Hopefully, you can kind of see how they
    //   correspond to if/else statements, by looking at this example.  While
    //   we're here, a few quick notes:
    //   - If you leave out the `break;` statements that you see at the end of
    //     each line, the statements will "fall through".  That is, if the line
    //     that does addition didn't have a `break;` at the end, and the user's
    //     expression was "4 + 5", what we would actually see would be "4 + 5 =
    //     9-1", since first `4 + 5` would be calculated and output, and then
    //     the program would "fall through" to the one below it, in this case
    //     subtraction, which would (without outputting a space first) output
    //     "-1".
    //   - Having a `default` case is not required, but it us nearly always
    //     good practice.
    //   - Switch statements can only be used (if I'm remembering correctly)
    //     with integer and character types.  They cannot be used with strings.
    switch (operation) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/': cout << double(a) / double(b); break;
        default: cout << "ERROR: Operation not supported";
    }

    cout << endl;

    return 0;  // success
}


// - Here, we define the function "add", which we prototyped above "main".
//   Below, we'll define "subtract", and the other functions
int add(int a, int b) {
    // - Recall that `a + b` evaluates (since `a` and `b` are both integers) to
    //   an integer, and that we can use `(a + b)` in most any situation where
    //   we could normally use an integer.  Here, we make use of that fact, and
    //   return the value of our expression directly.  For something this
    //   short, this is probably the best way to write it.
    return a + b;
}

int subtract(int a, int b) {
    // - Here, we use a temporary variable to store the value of `a - b`, and
    //   then return the value of that temporary variable.  This is just as
    //   good as the method above, except that it (unnecessarily, in this case)
    //   uses an extra 4 bytes of memory.  Also (and more annoyingly, lol) it
    //   takes 2 lines to write (assuming good formating techniques) instead of
    //   taking only 1.
    int temp = a - b;
    return temp;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return double(a) / double(b);
}
```

```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// - In this version, we define all our user defined function before we use
//   them.  Because of this, we do not need function prototypes, because the
//   compiler is determine each function's signature (i.e. how many and what
//   type of arguments each function takes, and what type of value it returns)
//   without them.
// - You'll probably see this done often enough, and (especially for simple
//   cases like this) it's not at all wrong.  Sometimes, if you have a bunch of
//   user defined functions can calling each other, things can get pretty
//   complicated, and you might need to use the function prototype method
//   (or... well... you might actually need to separate out some functionality
//   into another .cpp file, and write a header (a .h file), and include that
//   in your main program... but we'll get to all that :) )

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    int temp = a - b;
    return temp;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return double(a) / double(b);
}


int main() {
    int  a;          // to hold the user's first integer
    int  b;          // to hold the user's second integer
    char operation;  // to hold the user's operation

    cout << "Please enter an expression (like `4 * 5`): ";
    cin >> a >> operation >> b;

    cout << a << " " << operation << " " << b << " = ";

    switch (operation) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/': cout << double(a) / double(b); break;
        default: cout << "ERROR: Operation not supported";
    }

    cout << endl;

    return 0;  // success
}
```

```C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


// - Note that, when you're writing function prototypes, the compiler doesn't
//   care what the names of the variables you're passing in are going to be; it
//   only cares about the type of each variable (and how many there are, and
//   the order in which they occur).  I usually include the variable names in
//   the prototypes, but it's important to know that to the compiler they don't
//   matter.
int add(int,int);
int subtract(int,int);
int multiply(int,int);
double divide(int,int);

// - Here's a slightly more complicated function, just for fun
// - Also note that if the function has no return value (i.e. if the function
//   is just going to *do* something), we declare it to be of type `void`.
void perform_operation(char,int,int);


int main() {
    int  a;          // to hold the user's first integer
    int  b;          // to hold the user's second integer
    char operation;  // to hold the user's operation

    cout << "Please enter an expression (like `4 * 5`): ";
    cin >> a >> operation >> b;

    cout << a << " " << operation << " " << b << " = ";

    perform_operation(operation, a, b);

    return 0;  // success
}


// - Notice that when we call these functions in main(), we pass them variables
//   called "a" and "b".  The names of what you're passing to a function don't
//   matter, however (you could even pass them constants instead), because when
//   the function is called, the value of what you're passing is *copied* to a
//   new variable with whatever name the function wants to use for it.  See how
//   in this version of the functions we use "x" and "y".  We could use
//   (almost) anything, as long as we remember to use the same name for that
//   variable throughout the body of the function.
// - Note also that any changes we make to the variables we pass here *are not*
//   reflected in main().  There are ways to make is so that when you change
//   the value of a variable inside a function, the value of the variable that
//   was passed to that function is also changed, but we're not quite there
//   yet (look up the C++ concept of "pass by reference" if you're curious, or
//   look up how to pass pointers to variables instead of passing the variables
//   themselves (which is how one would do it in C, and which is, on occasion,
//   a bit prettier IMHO)).

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    int temp = x - y;
    return temp;
}

int multiply(int x, int y) {
    return x * y;
}

double divide(int x, int y) {
    return double(x) / double(y);
}


// - Note that there is no `return` statement in this function.  We could write
//   `return;` at any point, if we wanted the function to stop execution early
//   (for example, if we found an error in the arguments that were passed), but
//   writing `return 0;` would be an error, since this function is `void` (i.e.
//   it is not supposed to return any data).
// - Notice that you can write pretty much anything inside a function that you
//   can write inside main().
void perform_operation(char c, int x, int y) {
    // - Our operator was passed as `c`, so we have to "switch on `c`" (as it's
    //   called) instead of switching on `operator`
    switch (c) {
        case '+': cout << x + y; break;
        case '-': cout << x - y; break;
        case '*': cout << x * y; break;
        case '/': cout << double(x) / double(y); break;
        default: cout << "ERROR: Operation not supported";
    }

    cout << endl;
}
```

We'll save most of our function fun for next week (hopefully) :) .  For now,
please copy your code from "predefined.cpp" to "user.cpp", and modify it as
follows:
- Remove `#include <cmath>`, and all the operations that depended on it
- Add the following operations to your calculator (by writing functions that
  perform each action):
    - `abs` to find the absolute value of a number
        - User input should look like "abs -5"
        - Recall that the absolute value of a number, a, is defined piecewise
          as
            - a, if a >= 0
            - -a, if a < 0
        - You can call your function whatever you like, but please use a
          reasonalble name, like "abs" or "absolute" or something similar
    - `mod` to find the remainder after dividing one number by another
        - User input should look like "5 mod 2"
        - This function only needs to work with integers.  For simplicity's
          sake (even though this isn't mathematically correct) you may write it
          to accept `double`s and return a `double`.  Internally, you may
          convert your numbers to integers using a normal function style cast
          (i.e., if you have a `double` called `a`, you can convert it to `int`
          by writing `int(a)`).
        - Note that the modulus operator, `%`, only works with integers.  If
          one wished to do modulur arithmatic on floating point numbers
          (without using third party libraries), one should probably use the
          \<cmath\> function modf(), though (as is discussed in various places
          online) this may have accuracy issues.
        - Writing this function to work with `double`s (without using library
          functions) would probably be quite difficult.  But if you think of a
          method, by all means let me know :)
    - `convert-usd-eur` to convert US Dollars to Euros
        - User input should look like "convert-usd-eur 5.99"
        - The current conversion rate can be found
          [on google](https://www.google.com/search?client=safari&rls=en&q=5+usd+in+eur&ie=UTF-8&oe=UTF-8#q=1000000+usd+in+eur&rls=en).
          Please use the most accurate rate you can (reasonably) find.
        - If you wish, you can output the result of this operator specially,
          putting a '€' in front of it, and showing exactly 2 decimal places
          (look up "fixed" and "setprecision", which belong to the \<iomanip\>
          library, if you'd like), but this is not required; printing just the
          number is good enough.
    - `convert-f-c` to convert degrees Ferenheit to degrees Celcius
        - User input should look like "convert-f-c 32"
        - You can
          [search for the formula](https://www.google.com/search?client=safari&rls=en&q=5+usd+in+eur&ie=UTF-8&oe=UTF-8#q=fahrenheit+to+celsius+formula&rls=en)
          if you don't remember it :) (I have to look it up every time,
          myself...)

Sample runs:
```
Please enter an expression (like `4 * 5` or `abs -5`): -4 * 5
-4 * 5 = -20
```
```
Please enter an expression (like `4 * 5` or `abs -5`): abs -5
abs -5 = 5
```
```
Please enter an expression (like `4 * 5` or `abs -5`): 5 mod 4
5 mod 4 = 1
```
```
Please enter an expression (like `4 * 5` or `abs -5`): convert-usd-eur 1
convert-usd-eur 1 = €0.73
```
```
Please enter an expression (like `4 * 5` or `abs -5`): convert-f-c 212
convert-f-c 212 = 100
```



## Challenge

Write a [bash script](http://www.tldp.org/LDP/abs/html/) (or an [expect
script](http://w2home.blogspot.com/2007/11/expect-tutorial.html) if you're
feeling *super* ambitious) (or an [applescript
script](http://macosxautomation.com/applescript/firsttutorial/index.html) if
you like) to automate the testing of the code in this project for you.

- There may be better tutorials for expect and applescript; I have a lot of
  experience with the page linked above for bash scripting though, and IMO it's
  really good.

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

