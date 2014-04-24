# Week 14

## Contents

- Project (week 1 of 3)
    - Introduction
    - Github
    - Maze: Basics
    - Maze: Preview



## Project (week 1 of 3)

### Introduction

This project (an interactive maze) will be done in lab over the next 3 weeks.
It will cover a few things that we might not be very familiar with yet:
- pushing code to github
- functions
- constants
- infinite loops (sort of) (on purpose!)
- multi-dimensional arrays

It is possible that we will also explore:
- The [curses](http://en.wikipedia.org/wiki/Curses_(programming_library))
  library
- Header files
- Artificial intelligence
- Other things that I haven't thought of yet :)

This will be a running project: that is, I don't expect anything to be due
until the end of our last lab or so.  But you should be keeping your code up to
date on GitHub (more on that below).  And *please* don't let that be an excuse
for procrastinating...  lol.


### GitHub

To begin this project, everyone will be making their own GitHub account!  Go to
[github.com](https://github.com/) and follow the instructions :)

After that, you'll need to create a repo ("repository").  Locate the "Help"
link on the top-center of your GitHub homepage, and from there find the "Create
A Repo" link (which will look like an icon, near the top of the page; if you're
super lost, just [click here](https://help.github.com/articles/create-a-repo)).
I suggest using a name like "cpsc120-maze".

Before starting on your project, it would really be a good idea to practice a
bit with git.  I recommend going through [this interactive
tutorial](http://try.github.io/levels/1/challenges/1).  After that, unless
you're feeling super comfortable (it is your code, after all), you might like
to check out [this tutorial](http://rogerdudler.github.io/git-guide/), trying
out the various commands on your own repository.  Or maybe go through the first
tutorial again, only this time not on the website.  Don't be afraid to mess
something up: you're repo is still empty, and until you actually get some
valuable code in there, there's no harm in deleting it and starting over :)
(which is easy to do through the github website).  You really want to have a
feel for how things work though, before you do go putting valuable code in
there.

Once you're done with all that, if there are people nearby that look like they
could use some help, please help them :) .


### Maze: Basics

The requirements for the maze will be updated next week.  For now, see how far
you can get towards making a maze program with (at least) the following
components:

- Constants declared for the size of the board
    - The standard terminal size is 24 rows by 80 columns, so you probably want
      to stay close to that.  I used 21 rows and 77 columns, to allow some for
      the user's input and for messages.
- A multidimensional array containing the board.
    - There are many ways to declare this.  Since the best way is probably not
      obvious at this point, here's a small example:

      ```C++
      const int rows = 4;
      const int columns = 9;
      char board[rows][columns+1] = {
      "** === **",
      "*       *",
      "*       *",
      "*** i ***",
      };
      ```

    - I recommend using `'i'` for the user's character, `'='` for the finish,
      and `'*'` for the walls.
    - If you're feeling adventurous, you might consider adding other characters
      for other things (lava, water, monsters...).  Then again, you can always
      add these in later, if you'd rather try to get the game logic down first.
- A function to print the board
    - Take a look around online, or read [the end of
      lab-06](../week-06#preview-user-defined-functions) for an overview of
      user defined functions.
    - Don't feel bad if you need help on this part, since we didn't actually go
      over this in class.  We'll work through it though :)

And of course, you'll need a `main()`.  For now, I recommend that the main()
function contain code to do the following:
- Find the user's starting location (i.e. the location of the `'i'`)
    - You can do this by looping through the multidimensional array until you
      find the character 'i', and then saving the location (the row and column
      number) of the 'i' into two appropriatly names variables.
- Loop forever, doing the following:
    - Print the board (using your handy board printing function)
    - Get a character from the input stream
    - If the character is:
        - 'w': move the 'i' up, if possible
        - 'a': move the 'i' left, if possible
        - 's': move the 'i' down, if possible
        - 'd': move the 'i' right, if possible
    - In general, it is possible for 'i' to move as long as the square that 'i'
      is trying to move to contains a ' '.
    - If the square that 'i' is trying to move to does not contain a space:
        - If the character is an '=', then the user won!  Say so, and exit the
          program (using `return 0;`).
        - If the character is a '*', then you probably want to do nothing.
        - If you were being adventerous, and you included characters for lava
          and other such dangers, you should handle them accordingly.
    - A couple things to think about:
        - What are all the things that have to happen to the array containing
          the board when 'i' moves?
        - Which places in the code need if/if...else blocks?  Would switch
          statements simplify any of them?

### Maze: Preview

Just to keep track of things, and give you guys an idea of where I'd like to go
with this, here's a few topics I'm considering elaborating on next week :) .
Of course, which of these *have* to be done, and which are challenges, depends
largely on how everyone is doing with what we have so far.

- Multiple boards: Going off the edge of one board might transition the user to
  a new board.  Or perhaps there would just be multiple possible boards, and
  the user could pick between then at the beginning of the program.  Or perhaps
  there could be levels... :)

- Gravity: The user could fall one square every three turns or so.  (This one
  might be hard to do with the turn based model we have right now...  It'd be
  better if it was time based.)

- Monsters: There could be monsters on the board.  Perhaps they could take one
  step towards the user (or even just in any random direction) once every 1-3
  turns.

- AI: For the more technical people.  Instead of gravity or monsters, try to
  make a program that will navigate through an arbitrary maze all by itself.

- [curses](http://en.wikipedia.org/wiki/Curses_(programming_library)): I'd
  really like to use one of the curses libraries instead of just printing to
  the terminal like we are right now.  It would make things *so* much prettier.
  But I'm not sure how hard it would be for everyone (I still need to try it
  out first), and it might introduce small (or maybe large) differences between
  the programs for the Mac people (Thursday's lab) and the Windows people
  (Tuesday's lab), which wouldn't be my favorite.

- And of course, there may be other things that come to mind :) .  If you have
  any ideas, by all means bring them up (or just implement them, and say "Hey,
  look!").  The goal is to get some fun programming in, and practice with
  everything we've learned before the final (and, for those of you who are
  continuing, before CPSC 121).



-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

