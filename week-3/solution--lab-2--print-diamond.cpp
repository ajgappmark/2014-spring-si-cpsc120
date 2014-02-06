/**
 * Ben Blazak
 * CPSC 120
 * lab week 2
 *
 * Notes:
 * - Looking briefly at a few of the submissions for this lab, I saw a lot of
 *   good ones, most just as good as the one below.  In the future (but *only*
 *   with your permission), perhaps I'll be able to post some awesome solution
 *   by one of you guys for the general edification.  Until then, here's how I
 *   would do it.  Please keep in mind that there are many good ways.
 *
 * Design considerations:
 * - I have used `std::cout` instead of `using namespace std;` and `cout`
 *   because I prefer that.  If the professor has the slightest wish that I do
 *   it the more normal classroom way, I will promptly change my habits.
 * - I have purposely not printed out spaces after any of the `*`s.  It
 *   wouldn't make much difference in this example (and there are times when
 *   it's just a bunch easier to leave a few spaces at the end of a line), but
 *   in general it's preferred not to output characters you won't be able to
 *   see any evidence of on the screen.
 * - I have used only one `cout` statement.  I'm not sure if this has any
 *   runtime performance implications, but I find it nicer to only use one
 *   statement, since we're only printing out one logical thing (even if this
 *   shape does have multiple lines).
 * - I have used `\n`s instead of `<< endl`s.  This should make the program
 *   slightly faster (since `endl` forces a flush of the output buffer, while
 *   `\n` does not), but no one will notice, and really (on any system most of
 *   us will ever see) nobody cares.  The real reason I did it was because it
 *   saved me a few characters, and I felt it made the code ever so slightly
 *   more pretty.
 */

#include <iostream>

int main() {

    std::cout << "   *\n"
              << "  ***\n"
              << " *****\n"
              << "*******\n"
              << " *****\n"
              << "  ***\n"
              << "   *\n";

    return 0;
}

