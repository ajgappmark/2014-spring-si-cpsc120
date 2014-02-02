# Week 3

The purpose of our last exercise was in large part to expose ourselves to a
bunch of things that may not have been very familiar.  This exercise slows down
a bit with regard to the terminal, and leaves Make and makefiles for those who
have time and feel themselves equal to the challenge.


## Contents
- [Exercise] (#Exercise): For everybody :)
- [Challenges] (#Challenges): To those of you who had extra time during
  week-2's lab, I hereby challenge you to at least one of the items on in this
  list.


## Exercise

### Setup

- Start up the handy Terminal and run the following commands:
    - If you're not already familiar with the terminal, please type them in
      yourself instead of copying and pasting.  At least for this session :)
    - In the terminal, everything following a `#` is a comment.  You don't need
      to include comments when you type in your command (so, for example, when
      you type in the first line you only need to enter `cd ~/Desktop`, without
      the backticks).
    - Also, in the terminal, if you type the beginning of something and then
      press the tab key, it will often auto-complete, saving you a lot of
      typing.
    ```bash
    cd ~/Desktop      # navigate to the desktop
    mkdir lab-week-3  # create a new directory
    cd lab-week-3     # navigate to this new directory
    pwd               # "print working directory": to make sure we're in the
                      #   right place
    touch file-1.cpp  # also create a file called "file-1.cpp"
    ls                # "list" the contents of the directory: to make sure the
                      #   files actually got created
    ```

- Open "file-1.cpp" for editing by typing the following into the terminal:
    ```bash
    open file-1.cpp  # OS X specific: open "file-1.cpp" in the default program
    ```
    then edit it to contain the following "hello world" program (we'll make
    things more interesting once we're sure we have everything set up
    correctly):
    ```C++
    #include <iostream>
    using namespace std;

    int main() {
        cout << "hello world" << endl;
        return 0;
    }
    ```
    - Don't forget to save the file (by typing Command+s, or though the
      drop-down menus) before moving on :)

- Compile the "hello world" program by typing the following into the terminal:
    ```bash
    clang++ file-1.cpp -o file-1
    ```
    and then run it (still in the terminal) by typing the following:
    ```bash
    ./file-1
    ```

    The text
    ```
    hello world
    ```
    should be printed to the terminal.

- Note that:
    - You can remove your compiled file (a.k.a. "executable" or "binary" file)
      by typing
      ```bash
      rm file-1
      ```
      into the terminal.
    - You can regenerate or update your compiled file at any time with the
      command
      ```bash
      clang++ file-1.cpp -o file-1
      ```
        - This must be done every time you make a change to "file-1.cpp",
          before running the program again, otherwise you'll be running the old
          version of the executable.
        - Also, before recompiling later, be sure to save your edited file :) ,
          otherwise you'll be compiling the old version of the source.


### Variables

<!-- TODO -->


### Operators

<!-- TODO -->


### Lots of Fun

<!-- TODO -->


## Challenges

- Use your own laptop (if it's not already set up, this may have to wait till
  next lab for the sake of time)
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
  previous exercise may be helpful (or it may not).  The `clang++`
  documentation can be accessed by typing `man clang++` in the terminal, as you
  may recall, and the GNU Make documentation is [here]
  (http://www.gnu.org/software/make/manual/make.html).

<!-- TODO: is git installed on the lab computers? -->

<!-- TODO: coding exercise -->


-------------------------------------------------------------------------------

Copyright &copy; 2014 Ben Blazak <ic07@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/benblazak/2014-spring-si-cpsc120>

