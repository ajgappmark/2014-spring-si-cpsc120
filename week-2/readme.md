# Week 2

## Exercise

Hey everyone!  Today, we're going to try compiling with clang++ in the
terminal, and experiment a little with our first "hello world" program.

- First, [download all these files]
  (https://github.com/benblazak/2014-spring-si-cpsc120/archive/master.zip), and
  unzip them.

- Next, open the Terminal app, and navigate to the folder you just unzipped.
    - Use the "cd" command to do this.  If your unzipped folder is in
      Downloads, type `cd ~/Downloads/2014-spring-si-cpsc120-master`.
    - It may be helpful to keep both the terminal and a Finder window open to
      the same directory.

- Take a minute to look through all the files.  Start reading at the top, and
  stop when you feel like you have a good enough idea of what each file is for
  to move on.  Not all the information in every file is necessary, but it's
  important to have a general idea of what's happening.  If you have questions
  that aren't explained in the file you're looking at, ask a neighbor or two.
  If they don't know either, either google together, or ask me :)

- When you get to it, open `test.cpp`.


### Notes

- There are two different ways, in this exercise, to generate the files we'll be looking at for each version of the code.  You can:
    - Type `./generate-files.sh` into the terminal.  This script is easier to
      understand than the makefile.  You may use it if you wish.
    - Type `make` (or `make all`) into the terminal.  The actual makefile is
      more difficult to understand (i.e. it requires more background knowledge,
      which you'll pick up in time), but using Make is just as easy, and a much
      more standard way to do thing on Unix, so that's what I'll give
      instructions for below.

- If you just want to compile the source code into an executable directly, you
  can use
  ```
  clang++ test.cpp -o test.exe
  ```

  See the comments at the top of `generate-files.sh` for more information.  We
  won't need to do this in this exercise, but it's good to know how.



### version 0

- In the terminal, type `make` to compile your program and generate
  a number of intermediate files (`test.o`, `test.s`, etc.).

- In the terminal, type `make run`.  You should see something like
  ```
  --- running test.exe -------------------------------------
  hello world
  ----------------------------------------------------------
   The return value of test.exe was: 0
   The shell command used to run the program was: ./test.exe
  ----------------------------------------------------------
  ```

- Try typing `./test.exe` into the terminal.  This should only produce
  ```
  hello world
  ```

- Try looking at the other files, just for fun.  The end of
  `test.preprocessed.cpp` might be especially interesting -- but be careful
  opening it, since it might be a very large file (it might take quite a while
  to open).
    - If you want to, you can type `cat test.preprocessed.cpp` into the
      terminal.  This command will copy the contents of the file to stdout
      (i.e. your terminal), and the end of the file should then be visible on
      your screen.


### version 1

- Comment out the code under "version 0" (either using `/* ... */` C style
  comments around the entire block of code, or `//` C++ style comments in front
  of every line), and uncomment the code under "version 1".

- Recompile (using `make`)

- Run the program again (using `make run`) and take another look at the
  intermediate files, especially `test.preprocessed.cpp`.  Did anything change?


### version 2

- Now move on to "version 2", recompile, and look at the files again.

- Take special note of the differences between `test.cpp` and the end of
  `text.preprocessed.cpp`.  What effect did the use of the `#define`
  preprocessor directives have on this file?


### version 3

- Look at all the files again.  Take special note this time of `test.s`.
  Notice how much smaller it's gotten?  It almost looks reasonable now.

- Also, can a program really be this short?
    - Yes.  It doesn't do much though, lol.


### version 4

- Again, pay special attention to `test.s`.  See the line `movl	$42, %eax`?
  That `42` is from the `return 42` in `test.cpp`.

- Try out different return values in `test.cpp`, if you like, so you can see the
  corresponding line of `test.s` change.  You should also be able to see the
  alternate return value when you run the program with `make run`.  If you're
  having fun, go back to one of the different versions ad try out a few
  different output messages -- or maybe multiple output messages :)


### version 5

- This time, pay special attention to what the program does when it runs.  What
  output does it give (if any)?  What do you think is happening?


### version 6

- Note what the program's output is when you run it.  When does it stop running
  (after which statement)?  Which of the return values is actually returned?


### version 7

- Which value is returned by this version?


### version 8

- And what value is returned now?  Keep in mind that the program is executed in
  about the same order in which we read it (from top to bottom, and from left
  to right).  Also note that for all intents and purposes, **only one statement
  is executed at a time**.  This is very important.


-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

