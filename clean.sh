#! /usr/bin/env bash

##
# Author : Ben Blazak
# Date   : 2014-01-26
#
# This is a shell script that removes (hence "rm", the name of the program we
# call below) the files we no longer want -- in this case the files generated
# by typing "./generate-files.sh" into the terminal.
#
# For more information on shell scripting (bash shell scripting, in this case)
# see http://tldp.org/LDP/abs/html/.  It's a rather advanced
# tutorial/reference but don't let that scare you away.  It's the best one I've
# found, and it WILL make sense in time, if you decide that it's worth your
# effort to try (which it may not be right now, incidentally, depending on how
# much you're interested and how much free time you have).
#

rm *.preprocessed.cpp *.s *.o *.exe

