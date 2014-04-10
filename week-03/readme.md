# Week 3

**BEFORE YOU START.** Turns out, now that I don't have time to change this
drastically, that it contains a whole bunch of words.  I like to think they're
important words...  but if you find yourself getting bored, kindly blame it on
me, absorb what you happily can, and move on to something interesting.  I mean
that.  I'll try to get some fun programming challenges in here soon.  I'll also
try not to lose those of you who haven't seen this stuff before.  Both are more
challenging than you realize, until you try to do it :)


## Contents
- [Exercise] (#exercise): For everybody!
- [Challenges] (#challenges): To those of you who had extra time during
  week-2's lab, I hereby challenge you to at least one of the items on in this
  list.


## Exercise

The purpose of our last exercise was in large part to expose ourselves to a
bunch of things that may not have been very familiar.  This exercise slows down
a bit with regard to the terminal, and leaves Make and makefiles for those who
have time and feel themselves equal to the challenge.


### Setup

- Start up the handy Terminal and run the following commands:
    - If you're not already familiar with the terminal, please type them in
      yourself instead of copying and pasting.  At least for this session :)
    - In the terminal, everything following a `#` is a comment.  You don't need
      to include comments when you type in your command (so, for example, when
      you type in the first line you only need to enter `cd ~/Desktop` (without
      any quotes or backticks)).
    - Also, in the terminal, if you type the beginning of something and then
      press the tab key, it will often auto-complete, saving you a lot of
      typing.

  ```bash
  cd ~/Desktop      # navigate to the desktop
  mkdir lab-week-3  # create a new directory
  cd lab-week-3     # navigate to this new directory
  pwd               # "print working directory": to make sure we're in the
                    #   right place
  touch lab.cpp     # also create a file called "lab.cpp"
  ls                # "list" the contents of the directory: to make sure the
                    #   files actually got created
  ```


- Open "lab.cpp" for editing by typing the following into the terminal:

  ```bash
  open lab.cpp  # OS X specific: open "lab.cpp" in the default program
  ```

  then edit it to contain the following "hello world" program:

  ```C++
  #include <iostream>
  using namespace std;

  int main() {
      cout << "hello world\n" << endl;
      return 0;
  }
  ```

    - We'll make things more interesting once we're sure we have everything set
      up correctly.
    - Don't forget to save the file (by typing Command+s, or though the
      drop-down menus) before moving on :)


- Compile the "hello world" program by typing the following into the terminal:

  ```bash
  clang++ lab.cpp -o lab
  ```

  and then run it (still in the terminal) by typing the following:

  ```bash
  ./lab
  ```

  The text

  ```
  hello world
  ```

  should be printed to the terminal.


- Note that:
    - Last week we appended ".exe" to our executable file, so that above we
      would have said `clang++ lab.cpp -o lab.exe` to compile the program, and
      `./lab.exe` to run it.  Using no extension at all is a more Unix-y (and
      therefore Mac and Linux like) way of doing things.  Appending ".exe" is
      a very Windows thing to do.  You should probably stick to the conventions
      of whatever system you're working with unless you have a reason not to.
      In the end though, all that really matters is that what you're doing is
      clear to whoever is using the program.

    - You can remove your compiled file (a.k.a. "executable" or "binary" file)
      by typing `rm lab` into the terminal.

    - You can regenerate or update your compiled file at any time with the
      command `clang++ lab.cpp -o lab`.
        - This must be done every time you make a change to "lab.cpp", before
          running the program again, otherwise you'll be running the old
          version of the executable.
        - Also, before recompiling, be sure to save your edited file :) ,
          otherwise you'll be compiling the old version of the source.

    - On a Mac, in the terminal, you can open a Finder window in the current
      directory by typing `open .`.


### Variables

Before we get started, we need to talk about variables.  I'm sure most of you
know that computers (at least, typical laptop and desktop computers; and
smartphones, incidentally) have Hard Drives (or Flash Drives, or some other
form of persistent storage) and RAM (i.e. volatile storage, that looses its
data when you turn the computer off).  There are also a couple other kinds of
memory [(notes)](#notes) in a typical desktop, but for the moment we're only
really concerned with RAM.

- In C++, **variables live in RAM**.  When your code says
  ```C++
  int x;
  ```
  this means that a variable is created: there are now 32 bits (4 bytes) (since
  that's the size of an `int` on most systems) of memory in the computer that
  have no other purpose in the world other than to store the value of `x`.

- With one important exception **variables are not initialized by the
  compiler** [(notes)](#notes).  This means that when you write
  ```C++
  int x;
  ```
  the value of `x` is undefined: it might be anything!  And frequently, it will
  be something you don't want it to be.  Be careful.  Better, for now, to just
  always write
  ```C++
  int x = 0;
  ```
  (replacing `0`, of course, with whatever value you want `x` to have).

- Just for fun, we should also note that **variables have an address**, or more
  accurately, the memory where any particular variable lives has an address.
  This will be important when we get to arrays.  Try this inside the body of
  your `main()` function (i.e., right before `return 0;`):

  ```C++
  int x = 5;
  int y = 7;

  cout << "x = " << x << ", y = " << y << endl;

  cout << "the address of x is: " << &x
       << ", and the address of y is: " << &y << endl;
  ```

  Save the file, compile it, and run the newly generated executable.

  Notice that the addresses of `x` and `y` (`&x` and `&y` respectively) are
  quite large (unless I miss my guess: it's not that they have to be, it's just
  that they usually are).  This is because many many things, like the operating
  system, and every other program you're currently running, were loaded into
  memory before your small C++ program was, and therefore are already using
  most of the lower memory addresses.

  Note also that the addresses of `x` and `y` are very close to each other,
  probably only one number different (again, this doesn't have to be the case,
  but it almost always will be when you declare them like we did).  This is
  because they are located very close to each other (probably right next to
  each other) in memory.
  

#### Notes

- **... other kinds of memory**: Processor cache and registers come to mind,
  and the motherboard probably also has a smallish ROM somewhere to contain the
  BIOS.  Embedded systems often do things quite differently.

- **... variables are not initialized by the compiler**: Specifically, static
  variables are automatically initialized to 0 (or whatever the default value
  is for their type), and there may be other exceptions in C++ that I can't
  think of right now.  This is important on embedded systems, where memory is
  precious -- but for now you may as well assume that there is no such thing as
  an initialized variable until you initialize it yourself.


### Assignment

Now that we've talked about variables, lets go over one of the most basic
things we can do with them: assign them values.

- Consider the code (again, inside the body of your `main()` function)

    - If you feel comfortable with assignment already, please skip this bullet.

  ```C++
  int x;      // declare a variable; call it "x"

  // at this point, the value of x is undefined (we don't know what it is)

  x = 5;      // put the value of 5 into the location of memory assigned to x

  // at this point, the value of x is 5

  x = 7;      // put the value of 7 into the location of memory assigned to x

  // at this point, the value of x is 7


  int y = 5;  // declare a variable; call it "y"; put the value of 5 into the
              //   location of memory assigned to it

  y = 11;     // now, replace the previous value of y by placing the value of
              //   11 into the location of memory assigned to y

  // at this point, the value of y is 11

  int z = x;  // declare a variable; call it "z"; copy the data from the memory
              //   assigned to x into the memory assigned to z

  // at this point, the value of z is 7.  if we change the value of x right
  //   now, the value of z will still be 7.  if we change the value of z, the
  //   value of x will still be 7.

  z = y;      // now, replace the pervious value of z with a copy of the value
              //   currently stored in y

  // at this point, the value of z is 11

  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  ```

  Apart from the fact that all the comments make it hard to read, you should
  have a fairly good idea of what this code will print to the screen.

- The important thing to remember is that **variables are names for locations
  in memory** and that computers do things **step by step**.

- Now consider this code

  ```C++
  int x;
  int y;
  int z;

  // we could also write "int x, y, z;", and accomplish exactly the same thing.
  //   most of the time it's considered better practice to do it the way we did
  //   above though.

  x = y = z;
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  // be careful with this one

  x = y = z = 5;
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

  x = 5;
  y = 7;
  z = 11;
  x = x + 1;
  y = y + 2;
  z = x + y + 3;
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

  x = 5;
  y = 7;
  z = 11;
  z = y;
  y = x;
  x = z;
  z = 11;
  cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
  ```

  What do you think will be printed?

  It's okay, by the way, to write stuff down on a scratch paper, or to "just
  compile" or "just run" the program to see what will happen if you're not
  sure.  This experimentation is actually invaluable, especially when you're
  first starting out.  Keep in mind though that the goal is to *understand*
  what's going on.  Eventually, you should be able to know what code like the
  above will do without having to run it.


### Operators
Finally, on to operators in general!  We'll only discuss a few, but the ones we
don't learn about now, I imagine we'll learn about as we need (which, you'll
find, is a recurring theme).

At this point, it'll be good for you start finding things on your own, so
please do a quick google for "c++ operators".  If you see a link to
"cplusplus.com", you might try that one first, but you don't have to.  Just
skim whatever you find for now, to see if you can locate something that looks
like a table of all the different operators C++ has.

- How many are familiar to you?

- How many are there that you have no idea what they mean (which is completely
  fine for the moment: there a quite a few you could get away with ignoring for
  this entire class, and possibly the next one)?

- If you wanted to figure out what one of those obscure ones meant, how would
  you do it?  Try to figure out what `%` means.
    - Hint: It has nothing at all to do with "percent".  Once you figure out
      the name, if you don't find a few minutes of googling helpful, ask a
      friend.  If none of your friends know, ask a math major.  If they haven't
      taken Math 302 yet, ask me or the professor.  We will most likely need
      this one in weeks to come.

- If one wrote

  ```C++
  int x = 1 - 2 * 3 + 4;
  cout << x << endl;
  ```

  what would be printed?

- Based on the above (and whatever documentation you can find), what is
  "precedence"?

- If one wrote

  ```C++
  cout << 2 * 3 % 2 * 3 << endl;
  ```

  what would be printed?

- Based on the above, what is "associativity" (aka "grouping") (left to right,
  and right to left)?
    - Hint: Does `4 * 6 / 2` mean "multiply 4 and 6, and divide the answer by
      2" or does it mean "divide 6 by 2, and then multiply the answer by 4"?
      In this example the answer will be the same, since there is no rounding,
      and one may multiply and divide in any order.  With other examples,
      however, it will matter.
    - Note also that, if you think there is the least chance someone will
      misunderstand what's happening, you might want to consider using
      parenthesis.  Just because you test it and it works doesn't mean that
      anyone else (including yourself, in the future) will be able to tell what
      you meant.  And we're really writing code for humans to read first -- the
      fact that it's later turned in to something a computer can understand is
      only super convenient.

- Note: There are two broad categories of operators that we will mostly be
  dealing with: binary and unary.  The "bi" in "binary" is like the "bi" in
  "bicycle", and means two.  The "u" unary is like the "u" in "unique" (or
  "uno" if you prefer) and means one.
    - Binary operators take two things and return one thing.  In the code `2 +
      3` for example, `+` takes `2` and `3` and turns them into `5`.  I find it
      helpful to think of it as if `2 + 3` was *replaced* with 5, when the
      program is run.  Anywhere (that I can think of) where you could write `5`
      in your program, you could also write `(2+3)` and achieve exactly the
      same result.
    - Unary operators take one thing, and turn it into some other thing.  The
      best example for now is probably `-`.  "Minus" is also a binary operator,
      of course, but we also use it as a unary operator.  In the code `-5`, we
      don't just have a negative number.  What we really have is a positive
      number, `5`, and a unary operator, `-`, that takes 5 and turns it into
      negative 5.  This is why we're allowed to write things like

      ```C++
      int x = 5;
      cout << -x << endl;

      x = -3;
      cout << -x << endl;
      ```

- Now, just for fun, if one wrote

  ```C++
  cout << 'a' + 5 << endl;
  ```

  what do you think would be printed?

  Note that in general, you should have a reason for doing things like this
  besides just to confuse people.  But for an exercise, it's fun.  Things are
  not always as they seem :) .  More about that in Data Types, hopefully next
  week.


### Things to Think About Next Time You're Bored

- [Is `using namespace std;` bad practice?] (https://www.google.com/search?client=safari&rls=en&q=%5Cn+vs+endl&ie=UTF-8&oe=UTF-8#q=is+using+namespace+std+bad+practice%3F&rls=en)

- [What's the difference between `\n` and `endl`] (https://www.google.com/search?client=safari&rls=en&q=%5Cn+vs+endl&ie=UTF-8&oe=UTF-8#q=what's+the+difference+between+%5Cn+and+endl&rls=en)
    - Or similarly: [`\n` vs `endl`] (https://www.google.com/search?client=safari&rls=en&q=%5Cn+vs+endl&ie=UTF-8&oe=UTF-8#q=%5Cn+vs+endl&rls=en)


## Challenges

- Use your own laptop
    - Preferably running either OS X or Linux... Though if you insist on using
      Windows, and still want to play with fun command line stuff, you could
      try installing [Cygwin] (http://www.cygwin.com).
    - If you own a PC, I recommend [Linux Mint] (http://www.linuxmint.com) (or
      [Ubuntu] (http://www.ubuntu.com)).  If you don't know the difference
      between Cinnamon and MATE, and don't feel like reading about it, I'd
      personally recommend Cinnamon.  Installing clang++ should be pretty easy:
      something like `sudo apt-get install clang llvm` should work, or be close
      to working (shouldn't hurt to try).  If it doesn't work, you may have to
      google a bit.
    - If you own a Mac, life will probably be a bit easier at this stage.
      Assuming you're running OS X 10.9 (Mavericks) just install the most
      recent version of Xcode.  After that, test to see if clang++ is available
      on the command line.  If it doesn't seem to be, do a google search for
      "mavericks install command line tools".
    - Of course, you could always use always use Visual Studio on your Windows
      machine, or Xcode on your Mac.  I feel like this would be a slightly
      smaller and (in the long run) less enlightening challenge, but it'd still
      be worthwhile.

- Instead of using TextWrangler as your editor, use Vim
    - Type `vimtutor` into the terminal to start an interactive tutorial on how
      to use it.  Or find a tutorial online.
    - You may eventually wish to download MacVim (a version of Vim with a
      native OS X GUI), and use that (if it's possible to install it on these
      computers without admin privledges).
    - My configuration files, if you'd like to use them, are [on github]
      (https://github.com/benblazak/.vim).  You'll need to copy the folder
      (`.vim`) to your home directory after you download it, and then move
      `.vimrc` and `.gvimrc` out of your new `~/.vim` directory and into your
      home directory.  You may wish to do all this in the terminal rather than
      trying to fight with Finder to get it to show you dotfiles (as they're
      called -- files beginning with a `.`)

- Instead of using TextWrangler as your editor, use Emacs
    - I'm afraid I can't help you here, as I've never gotten around to learning
      Emacs myself.  I hear it's an awesome editor though.

- Instead of compiling in the way the instructions say, write a makefile, or
  find one online and modify it to do what you want.  The makefile from the
  previous exercise may be helpful (or it may not).  The clang++ documentation
  can be accessed by typing `man clang++` in the terminal, as you may recall,
  and the GNU Make documentation is [here]
  (http://www.gnu.org/software/make/manual/make.html).

- Search and read about what a Revision Control System (or Version Control
  System, etc.) is.  There are a few you should probably know about just for
  fun: especially RCS and CVS.  You may run into others.  Especially, read
  about Git.  If git is installed on these computers (try `man git` on the
  command line), experiment a little, and try revision controlling your current
  project.  If you're especially adventurous, perhaps you'll open a github
  account, and play around with pushing code from a local repository to github
  (the github help pages are especially helpful).

- Start going through [The Python Tutorial]
  (http://docs.python.org/3.3/tutorial/).  Yes, this is a C++ class... but
  learning other (good) languages will only make you a better programmer, and
  [Python is awesome](http://xkcd.com/353/)!  Most of the concepts you learn
  will translate fairly directly to C++.  Also, eventually somebody (probably a
  professor, likely during a test) is going to ask you to write pseudocode for
  something.  Whenever that happens to me, I usually just write whatever they
  wish in Python :)


-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

