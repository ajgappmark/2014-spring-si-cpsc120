#! /usr/bin/env bash

##
# Author : Ben Blazak
# Date   : 2014-01-26
#
# This is a shell script that calls the program "clang++" to generate various
# files from test.cpp.
#
# Type "man clang++" to see the clang++ manual.  It will likely be a bit dry,
# starting out, but these manuals (called "man files") will be invaluable as
# you go on.  If you search through it a little (try typing "/-E<enter>n",
# where "<enter>" is a literal enter (or return)), you should be about to find
# an explanation of how "-E", "-S", "-c", and "-o" affect the behavior of
# clang++.
#

clang++ -E test.cpp -o test.preprocessed.cpp
clang++ -S test.cpp -o test.s
clang++ -c test.cpp -o test.o
clang++    test.cpp -o test.exe

