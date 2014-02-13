# Week 4

## Contents

- Exercise
    - Setup
    - Data Types (and I/O)
        - Intro
        - More About Integers
        - Characters, Floats, and Casting
        - Strings
        - Boolean Expressions (Specifically)
    - Simple Control Flow (`if`, `else`)
- Continuing Challenges
- Notes



## Exercise

If you get done early, please help a friend.  If you don't have a friend, and
you can possibly stand it, please make one, and then help them :)


### Setup

One last time, before I decide that it doesn't matter and you can use whatever
you want, please **start up the lovely Terminal**.

- It's okay to use the terminal for the lab on titanium as well, if you like
  (though of course you don't have to).
- Pressing the tab key after typing part of a command will often complete the
  command for you (and save you typing).
- Pressing the up arrow will cycle through commands you have previously entered
  (and save you typing).

Look back at the [week-3 instructions](../week-3/readme.md) if you'd like more
detail.  Here are the commands, for your convenience:

```bash
  cd ~/Desktop      # navigate to the desktop
  mkdir lab-week-4  # create a new directory
  cd lab-week-4     # navigate to this new directory
  pwd               # "print working directory": to make sure we're in the
                    #   right place
  touch lab.cpp     # also create a file called "lab.cpp"
  ls                # "list" the contents of the directory: to make sure the
                    #   files actually got created
  open lab.cpp      # OS X specific: open "lab.cpp" in the default program
```

and of course, you can still compile using

```bash
clang++ lab.cpp -o lab
```

and run your program using

```bash
./lab
```


### Data Types (and I/O)

#### Intro

We saw a little bit about data types last week when we wrote

```C++
  cout << 'a' + 5 << endl;
```

which resulted in `102`.  As a few of you saw, 

```C++
  cout << 'a' + 0 << endl;
```

resulted in `97`, and 

```C++
  cout << char('a' + 5) << endl;
```

resulted in `f`.

Do a quick search for an ASCII table [(notes)](#notes) online, if you haven't
already.  That should explain the numbers, at least.

As for the rest, that's most of what this lab is about.

#### More About Integers

Here are some references (please don't visit them quite yet):
- [cplusplus.com tutorial: Variables and Data Types]
  (http://www.cplusplus.com/doc/tutorial/variables/)
- [cppreference.com: Data Types]
  (http://en.cppreference.com/w/cpp/language/types)
- [cppreference.com: Fixed Width Integer Types]
  (http://en.cppreference.com/w/cpp/header/cstdint)
- [stackoverflow.com: Implicit type conversion rules in C++ operators]
  (http://stackoverflow.com/questions/5563000/implicit-type-conversion-rules-in-c-operators)
- [C++ Working Draft Standard]
  (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf)
    - See especially section 4.5 (Integral promotions)
    - Also available in [LaTeX source on github]
      (https://github.com/cplusplus/draft)
- [cplusplus.com tutorial: Type conversions]
  (http://www.cplusplus.com/doc/tutorial/typecasting/)

Now, using the above references, google, and especially the people next to you,
do your best to understand the following code.  Does the output surprise you?

```C++
#include <iostream>

int main() {
             int a = 2147483647;  // 2^31-1 = 2147483647
    unsigned int b = 4294967295;  // 2^32-1 = 4294967295

    std::cout << "a   = " << a   << std::endl;
    std::cout << "a+1 = " << a+1 << std::endl;
    std::cout << "b   = " << b   << std::endl;
    std::cout << "b+1 = " << b+1 << std::endl;

    return 0;
}
```

What you saw above was an example of signed (in the case of `a`) and unsigned
(in the case of `b`) integer overflow.  When an integer type is set to its
maximum value and we add 1, its value "wraps around" to the lowest value it can
store [(notes)](#notes).  But how did I know what the maximum values of `int`
and an `unsigned int` were?  I'm glad you asked :)

```C++
#include <iostream>

// The code `sizeof(int)` is an example of function notation, which we'll get
// to in a few weeks I think.  Similar notation is used for the type of casting
// described later in this exercise.  For now, just think of it as in math:
// "f(x)" is a function taking an input "x" and returning (or evaluating to, or
// equaling) some value; "sizeof(int)" is a function taking a type, "int", and
// returning (or evaluating to, or being replaced by) the number of bytes it
// takes to store that type.

int main() {
    std::cout << "The size of an `int` is "
              << sizeof(int) << " bytes\n";
    std::cout << "The size of an `unsigned int` is "
              << sizeof(unsigned int) << " bytes\n";
    return 0;
}
```

A byte (if you didn't know) is 8 bits.  A bit (if you didn't know) is a single
on/off value, which we usually represent as a 1 (on) or a 0 (off)
[(notes)](#notes).  So if an `int` is 4 bytes long, it is 4\*8 = 32 bits long,
and it can store... how many values?  Before we continue, we need to review
some terminology:

- A decimal number is a number written using the characters 0..9, as in `255`.
  We call this the "base 10" system, because it uses 10 different characters.
- A hexadecimal number is a number written using the characters 0..9 and A..F.
  In C++, we represent literal hexadecimal numbers by preceding them with `0x`
  as in `0xFF`, which equals `255` in decimal.  We call this the "base 16"
  system, because it uses 16 different characters.
- A binary number is a number written using only the characters 0..1.  In C++,
  we represent literal binary numbers by preceding them with `0b` as in
  `0b11111111` which equals `0xFF` which equals `255`.  We call this the "base
  2" system, because is uses 2 different characters.
- Octal numbers (which you won't see very often, but you should still know what
  they are) are written using only 0..7.  In C++, we represent literal octal
  numbers by preceding them with `0` as in `0377` which equals `0xFF`, etc.  We
  call this the "base 8" system, because it uses 8 different characters.

Now, how many values do you think we can represent with an n digit binary
number?  Let's do an experiment:

```C++
#include <iostream>

int main() {
    std::cout << "0b0000 == " << 0b0000 << std::endl;
    std::cout << "0b0001 == " << 0b0001 << std::endl;
    std::cout << "0b0010 == " << 0b0010 << std::endl;
    std::cout << "0b0011 == " << 0b0011 << std::endl;
    std::cout << "0b0100 == " << 0b0100 << std::endl;
    std::cout << "0b0101 == " << 0b0101 << std::endl;
    std::cout << "0b0110 == " << 0b0110 << std::endl;
    std::cout << "0b0111 == " << 0b0111 << std::endl;
    std::cout << "0b1000 == " << 0b1000 << std::endl;
    std::cout << "0b1001 == " << 0b1001 << std::endl;
    std::cout << "0b1010 == " << 0b1010 << std::endl;
    std::cout << "0b1011 == " << 0b1011 << std::endl;
    std::cout << "0b1100 == " << 0b1100 << std::endl;
    std::cout << "0b1101 == " << 0b1101 << std::endl;
    std::cout << "0b1110 == " << 0b1110 << std::endl;
    std::cout << "0b1111 == " << 0b1111 << std::endl;

    std::cout << std::endl;

    std::cout << "0b00011111 == " << 0b00011111 << std::endl;
    std::cout << "0b00111111 == " << 0b00111111 << std::endl;
    std::cout << "0b01111111 == " << 0b01111111 << std::endl;
    std::cout << "0b11111111 == " << 0b11111111 << std::endl;

    return 0;
}
```

What do you think?

It turns out that in general, we can represent 2^n different numbers with an n
bit integer.  For unsigned types, we start with the number 0, so the range of
an n bit unsigned integer is 0 to 2^n-1.  For signed types, we use the most
significant bit (i.e. the "largest" bit, usually written on the left) as the
sign bit, so we have 31 bits left for the actual number.  Most typically, we
use something called
[2's compliment](http://en.wikipedia.org/wiki/Two's_complement)
to represent negative numbers conveniently, and we end up with a range of from
-2^(n-1) to 2^(n-1)-1.  Break out your calculator, and you'll see that
[-2^(32-1)](https://www.google.com/search?client=safari&rls=en&q=2%5E32-1&ie=UTF-8&oe=UTF-8#q=-2%5E(32-1)&rls=en)
is indeed the value of `a+1` in our first example, and the initial value of `b`
was precisely
[2^32-1](https://www.google.com/search?client=safari&rls=en&q=2%5E32-1&ie=UTF-8&oe=UTF-8#q=2%5E32-1&rls=en).

If you ever need to reference this, and don't happen to remember (which you
probably won't unless you use it a lot), just look up "c++ integer ranges", or
something like that, and you should be able to find
[something useful](http://en.wikipedia.org/wiki/Integer_(computer_science)).

Finally, before we move on, you should know that there are other integer types
in C++ besides just `int` and `unsigned int`.  In general, if you have a reason
to care how wide your integer type is, you should be using one of the fixed
width types [here](http://www.cplusplus.com/reference/cstdint/).  These will
become important when you take assembly, and maybe algorithms.  Now that you
know about them, you may as well let them go for the moment, and just use `int`
unless you have a super good reason not to.

#### Characters, Floats, and Casting

Now that we've gone over the hard part, we can go much more quickly through the
other things we need to know.

- Characters in C++ are of type `char` (pronounced "kayr").  You should use
  them only to represent single characters.

- There are multiple types of floating point numbers (which you can look up if
  you like) but the one we'll mostly use is `double`.  It gets it's name from
  being a
  [double precision](http://en.wikipedia.org/wiki/Double-precision_floating-point_format)
  (or, twice as wide as `float`) floating point number, according to the IEEE
  754 standard.  You should use it whenever you need to store a number with a
  decimal point, and it's too inconvenient to use something else.

- Casting is the act of taking data of one type, and "turning it into" data of
  another type.

Example!

```C++
#include <iostream>

int main() {
    int    i = 97;
    char   c = 'x';
    double d = 5.57;

    std::cout << "i == " << i << "   c == '" << c << "'   d == " << d << "\n";

    return 0;
}
```

and all is well and good.  Let's mix things up a little bit.

```C++
#include <iostream>

int main() {
    char c = 97;
    // when you assign an `int` (like `97`) to a `char` variable, it is
    // automatically converted to type `char`.  this is an example of
    // implicit type conversion.

    double d = 4/5;
    // what does `d` equal?  probably not what you think.

    std::cout << "c == '" << c << "'   d == " << d << "\n";

    return 0;
}
```

What happened to the value of `d`?  First, note that `4` and `5` are both
integers.  When `/` operates on two integers, it returns an integer.  Since
integers have no way to store decimal points, the decimal part of the number is
thrown away (or cut off -- *not rounded* -- we call this truncation).

Instead of `4/5` try `double d = 4/5.0;`.  What happens now?

Lets return to (and extend) our example of `'a'+5` from last week:

```C++
#include <iostream>

int main() {

    std::cout << "'a' == " << 'a' << "\n";
    std::cout << "char(97) == " << char(97) << "\n";
    std::cout << "'a'+5 == " << 'a'+5 << "\n";
    std::cout << "char(97)+5 == " << char(97)+5 << "\n";
    std::cout << "char('a'+5) == " << char('a'+5) << "\n";
    std::cout << "char(char(97)+5) == " << char(char(97)+5) << "\n";
    std::cout << "char(97)+char(5) == " << char(97)+char(5) << "\n";

    std::cout << std::endl;

    std::cout << "int('a') = " << int('a') << "\n";
    std::cout << "double('a') = " << double('a') << "\n";
    std::cout << "int(97) = " << int(97) << "\n";
    std::cout << "double(97) = " << double(97) << "\n";
    std::cout << "int(5.7) = " << int(5.7) << "\n";
    std::cout << "double(5.7) = " << double(5.7) << "\n";
    std::cout << "char(98) = " << char(98) << "\n";
    std::cout << "char(98.6) = " << char(98.6) << "\n";

    return 0;
}
```

Whereas `char c = 97` is an example of implicit type conversion, most of these
are examples of explicit conversion.  When you say `int(...)`, you explicitly
tell the compiler to turn whatever is between the parenthesis into an `int` (if
that's possible; and if it's not, you'll get an error, which is fine; you'll
just have to fix it an recompile).

C++ has other types of casting
[which you can read about](http://www.cplusplus.com/doc/tutorial/typecasting/)
if you wish.  You'll find that casting has many wonderful (and sometimes
dangerous) uses once you get to learning about pointers and objects.

#### Strings

Finally, we get to strings :) .  Strings are not included above, along with
`chahr`s, `int`s, and the like, because strings are not what we call "primitive
data types"; that is, strings are not just a bunch of `chars`, all in a row,
living in some static location in memory.  Strings are *objects*.  And we don't
really care about objects yet, but it's important to know that they're
different than primitive data types.  The practical upshot of all this is that
we'll need to include another header file in order to be able to use them.

```C++
#include <iostream>
#include <string>    // needed for `std::string`

int main() {
    std::string s = "hello world!";
    std::cout << s << "\n";
    return 0;
}
```

Not so hard :) .  Note that we could also write this as

```C++
#include <iostream>
#include <string>    // needed for `std::string`
using namespace std;

int main() {
    string s = "hello world!";
    cout << s << "\n";
    return 0;
}
```

or even (as you may see at some point in the future) like this

```C++
#include <iostream>
using std::cout;

#include <string>
using std::string;

int main() {
    string s = "hello world!";
    cout << s << "\n";
    return 0;
}
```

Since strings are objects, in addition to just being able to store string
literals oh so conveniently, they also have what are called "member functions"
(don't worry about this for now, except for the syntax):

```C++
#include <iostream>
#include <string>    // needed for `std::string`

int main() {
    std::string s = "hello world!";

    // printing normally
    std::cout << "This string says: " << s << "\n";

    // how long is my string?
    std::cout << "This string is " << s.length() << " characters long\n";

    // what is the third character of our string?
    // - not to get ahead of ourselves.  this method of accessing a string is
    //   the same as the way we will access arrays later on.  there are some
    //   dangers to watch out for.  for now, just be careful not to ask for a
    //   character that doesn't exist.
    // - note that the first character of this string is `s[0]`, not `s[1]`
    std::cout << "The third character of this string is '" << s[2] << "'\n";

    // we can append things to our string using the `+` operator
    s = s + " i am happy to see you.";
    std::cout << "Now this string says: " << s << "\n";

    return 0;
}
```

The `string` class has other member functions as well, which
[you can read about](http://en.cppreference.com/w/cpp/string/basic_string)
if you like.

Before we move on, quick question: why can we write

```C++
#include <iostream>

int main() {
    std::cout << "hello world\n";
    return 0;
}
```

without including the string library (that is, without `#include <string>`),
even though it obviously uses strings? [(note)](#notes)

#### Boolean Expressions (Specifically)

One important thing that we haven't mentioned yet is the boolean type (`bool`,
named after
[George Bool](http://en.wikipedia.org/wiki/George_Boole),
who did a lot of cool stuff with logic in the 1800's).  Boolean variables are
variables that are either `true` (often represented as `1`) or `false` (often
represented as `0`).  It's surprising how often such a simple thing turns out
to be useful.

Take a look at these examples:

- Note that this should generate 3 warnings.  What is it complaining about?
  Before looking below, how would you fix it?  I had to look this up too...
  but that's programming :)

```C++
#include <iostream>

/**
 * Notes:
 * - Sometimes (especially in documentation) we say "lvalue" instead of "the
 *   value on the left hand side" and "rvalue" instead of "the value on the
 *   right hand side".
 *
 * References:
 * - http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
 */

int main() {
    bool a = true;
    bool b = false;
    bool c = 1;
    bool d = 0;
    bool e = 5;  // remember automatic type conversion?

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << b << std::endl;
    std::cout << "d = " << b << std::endl;
    std::cout << "e = " << b << std::endl;

    std::cout << std::endl;

    std::cout << "(5 < 2) : " << (5 < 2) << std::endl;
    std::cout << "(2 < 5) : " << (2 < 5) << std::endl;
    std::cout << "(2 <= 5) : " << (2 <= 5) << std::endl;
    std::cout << "(5 >= 5) : " << (5 >= 5) << std::endl;

    std::cout << std::endl;

    // does this make sense? what is it doing? :)
    std::cout << "(\"hello\" < \"world\") : "
              << ("hello" < "world") << std::endl;

    std::cout << std::endl;

    // in C++, `=` is for assignment (so `a = 5` means "set a to 5"), while
    // `==` is for comparison (so `a == 5` means "is a equal to 5?")
    std::cout << "(2 == 5) : " << (2 == 5) << std::endl;
    std::cout << "(5 == 5) : " << (5 == 5) << std::endl;
    std::cout << "('c' == 'c') : " << ('c' == 'c') << std::endl;
    std::cout << "(4.5 == 4.5) : " << (4.5 == 4.5) << std::endl;
    std::cout << "(true == false) : " << (true == false) << std::endl;
    std::cout << "(true == true) : " << (true == true) << std::endl;
    std::cout << "(\"this\" == \"that\") : "
              << ("this" == "that") << std::endl;
    std::cout << "(\"this\" == \"this\") : "
              << ("this" == "this") << std::endl;

    std::cout << std::endl;

    // we often read `!` as "not"
    std::cout << "(!true) : " << (!true) << std::endl;    // not true
    std::cout << "(!false) : " << (!false) << std::endl;  // not false
    std::cout << "(5 != 2) : " << (5 != 2) << std::endl;  // does 5 not equal 2?

    std::cout << std::endl;

    // `&&` means "and": true only if the left value *and* the right value are
    // true
    std::cout << "(true && true) : " << (true && true) << std::endl;
    std::cout << "(true && false) : " << (true && false) << std::endl;
    std::cout << "(false && true) : " << (false && true) << std::endl;
    std::cout << "(false && false) : " << (false && false) << std::endl;

    std::cout << std::endl;

    // `||` means "or": true if either the left value *or* the right value is
    // true
    std::cout << "(true || true) : " << (true || true) << std::endl;
    std::cout << "(true || false) : " << (true || false) << std::endl;
    std::cout << "(false || true) : " << (false || true) << std::endl;
    std::cout << "(false || false) : " << (false || false) << std::endl;

    return 0;
}
```

It looks to me like string comparisons using `==` and such aren't defined by
the standard.  Instead, we should replace the offending lines with something
like this:

```C++
#include <iostream>
#include <string>    // needed for `std::string`
#include <cstring>   // needed for `strcmp()`

/**
 * Notes:
 * - The code `std::string("this")` casts the string literal (which is really a
 *   cstring) to a `string` object.  If we were using `using namespace std;` it
 *   would only be `string("this")`, and would look a little more normal.
 *
 * References:
 * - string library reference (see the "compare" function, near the bottom)
 *   http://www.cplusplus.com/reference/string/string/
 * - `strcmp` function reference, from the cstring library
 *   http://www.cplusplus.com/reference/cstring/strcmp/
 */

int main() {

    // can't really rewrite this one.  what would it mean to say one string was
    // less than another anyway?

//     std::cout << "(\"hello\" < \"world\") : "
//               << ("hello" < "world") << std::endl;

    // the second two can be rewritten though

    std::cout << "std::string(\"this\").compare(\"that\") : "
              << std::string("this").compare("that")
              << std::endl;

    std::cout << "std::string(\"this\").compare(\"this\") : "
              << std::string("this").compare("this")
              << std::endl;

    // note that we could also avoid the string library altogether, using the
    // cstring library functions instead.  it would probably be better not to
    // do this though, at least during this class, as it's really better form
    // in C++ to do things the C++ way; unless for performance reasons you find
    // you can't.

    std::cout << "strcmp(\"this\", \"that\") : " 
              << strcmp("this", "that") 
              << std::endl;

    std::cout << "strcmp(\"this\", \"this\") : " 
              << strcmp("this", "this") 
              << std::endl;

    return 0;
}
```

Now that we've cleared that up, remember how binary operators are evaluated?
`<` is one such operator, for example, taking two things, comparing them, and
returning `true` if the left value is "smaller" than the right value, and
`false` otherwise.  When `2 < 5;` is evaluated, the operator `<` takes `2` and
`5`, and since 2 is less than 5, it returns `true`; which is to say that
(almost?) anywhere you could write `true`, you could also write `(2 < 5)`.

Knowing this, consider the following code.  Keep in mind that `0` is used for
`false`, and `1` (or sometimes any other nonzero value) is used for `true`.
What do you think will be printed?

```C++
#include <iostream>

int main() {
    std::cout << (10 < 5 < 7) << std::endl;
    return 0;
}
```

The problem is, remember that `<` is a binary operator?  And that `true` is
silently converted to `1`, and `false` is silently converted to `0`?  This is
about what's happening, step by step, when the code is executed:

0. `(10 < 5  < 7)`
0. `((10 < 5) < 7)`
0. `(( false ) < 7)`
0. `(( 0 ) < 7)`
0. `(0 < 7)`
0. `( true )`
0. `( 1 )`
0. `1`

and as we saw, `1` is precisely what gets printed.


### Simple Control Flow (`if`, `else`)

This exercise is getting pretty long, but I feel like it'd at least be good to
see this again, before going over it in more detail later.

Have a look at the following code:

```C++
#include <iostream>

int main() {

    if (2 < 5) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    if (5 < 2) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}
```

Try changing the conditions (the parts inside the parenthesis after `if`), even
to things that you think won't work.  See if it compiles, and see what it does
:)



## Continuing Challenges

- [Learn how to use Git](http://git-scm.com/documentation)

- Lean how to use Vim (type `vimtutor` into the terminal, and follow the
  instructions)

- [Learn Python](http://docs.python.org/3.3/tutorial/)



## Notes

- **... ASCII table**: ASCII, as an independent standard, is actually not used
  that much anymore.  It's largely been superseded by utf-8, which is backwards
  compatible with non-extended ASCII, and capable of representing vastly more
  characters.  [Take a look](http://unicode-table.com/en/) if you like.  We
  typically use and talk about ASCII in intro programming courses because it's
  simpler (utf-8 is a variable length encoding, with characters occupying
  between 1 and 4 bytes, while ASCII characters each occupy exactly 1 byte) and
  has been around since the beginning of time.

- **... a 1 (on) or a 0 (off)**: When dealing with embedded systems, we say
  that a bit is "set" if it is on, and "cleared" if it is off.  I find the
  terms useful, but you'll rarely hear them outside of embedded (or maybe
  systems) programming, as higher level code rarely explicitly cares about
  single bits.

- **... its value "wraps around" ...**: First of all, integer overflow for
  signed types is undefined by the standard (please forgive the lack of
  reference... but it's well agreed upon on stackoverflow), even if our
  machines do seem to do the reasonable thing.  Regarding unsigned integer
  overflow, the standard says:

  > ... a result that cannot be represented by the resulting unsigned integer
  > type is reduced modulo the number that is one greater than the largest
  > value that can be represented by the resulting unsigned integer type.

- **... we represent a literal binary number**: Technically, this is an
  extension to the C++ standard.  But it's implemented in GCC and Clang, and
  it's quite convenient, so we'll just use it for now.

- **... why can we write ... without including the string library ...**: There
  are multiple ways to represent a string in C++.  What we've been working with
  up to this point have been string literals, which are really C strings, which
  are really character arrays, and not `string` objects.  This information is a
  good bit ahead of where we are right now, but I think it's pretty fun :) and
  good to know.


-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

