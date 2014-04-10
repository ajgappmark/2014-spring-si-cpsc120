# Week 8

## Contents

- Instructions
    - Converting Numbers to Roman Numerals



## Instructions

### Setup

This exercise should be compiler agnostic -- that is, you should be able to do
it in Visual Studio, the Terminal, or any environment you like.


### Converting Numbers to Roman Numerals

**Please read this entire prompt before starting** so you have a better idea
about what's going on.

The exercise below is a bit vague, on purpose.  Today, the main goal is to
design a program :) .  We'll start with the instructions below.  Read them
carefully, and take note of the things that it's not clear how to do.

Write a program that does the following:

0. Asks the user to enter an integer
0. Prints the integer in Roman numerals
0. Asks the user if they'd like to convert another integer
    - If the user enters `'n'` or `'N'`: end the program (`return 0;`)
    - If the user enters anything else: go back to step 1

So, we know how to ask the user for integers.  Not hard, right?  We'll type it
up when it's clear where it should go.

Do we know how to print Roman numerals?  No?  We'll work on that in a bit.

Do we know how to go back to step 1 if the user doesn't enter `'n'` or `'N'`?
That sounds easier than converting things to Roman numerals -- and it doesn't
sound like it depends on anything else -- so we'll work on that first.  In
groups.  The whiteboards are open!

- Hint: We want to do something unconditionally the first time, and
  conditionally every time after that.  Have we heard of some kind of loop that
  might help us?

Once you get this done, you should probably type it out and test it.  You can
put a placeholder in the spot where you're eventually going to convert the
number into a Roman numeral -- perhaps just `cout << "(this is a Roman
numeral)\n";` or something like that.

*Now* it's time for Roman numerals.  You can google them if you want (I had to)
to refresh your memory on their finer points.  Then *find a group!* (or go back
to the one you already have) and talk about it a bit.  The whiteboards are
still open!  And I will find extra markers if need be.  Suggestions:

- Try writing out a few of the numerals, starting from 1.  What kind of
  patterns do you notice?
- What's the smallest number we can represent in Roman numerals?  We should
  probably report an error if the user tries to convert a number smaller than
  this.
- What's the largest number we can represent in Roman numerals?  We should
  probably report an error if the user tries to convert something larger than
  this.
- Do we need a loop?  If so, which kind do you think we need?  If not, can we
  use one anyway to make our code cleaner and less redundant?
- Do we need a function?  You can take a look at 
  [the examples from week 6](../week-06#preview-user-defined-functions)
  if you like.
    - If you're not feeling good about using functions today, I would recommend
      you not to.  If you do feel comfortable though, it might make your code a
      bit cleaner -- but definitely don't waste time being frustrated with it.

Please note that this step will probably be the most difficult.  You'll have to
think about it, really hard, until you reach a revelation.  If you don't right
away, that's okay!  Keep trying.  If you feel stuck, start trying things out on
paper.  See if you can experiment your way into something that looks promising.

Sample run:

```
Please enter an integer: 123
--> CXXIII

Would you like to convert another integer (Y/N)? y

Please enter an integer: 401
--> CDI

Would you like to convert another integer (Y/N)? y

Please enter an integer: 1299
--> MCCXCIX

Would you like to convert another integer (Y/N)? n
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

