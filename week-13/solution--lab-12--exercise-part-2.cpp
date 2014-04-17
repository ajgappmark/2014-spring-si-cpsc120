/**
 * ben blazak
 * week 12
 * array exercise part 2
 *
 * Notes:
 * - Notice how this solution may return from inside the body of the for
 *   loop.  In some (most, actually) situations, it's a bad idea to return
 *   from anywhere except the end of the function.  In fact, there are extreme
 *   situations (e.g. if you're writing code for drones that fly in US
 *   airspace; true story from my cousin :) ) where I think it's illegal to
 *   return from anywhere but the end of a function.  But if the function is
 *   small, and it really does make things easier to understand, I think it's
 *   perfectly fine.  The goal, as always, is making things clear for yourself
 *   and your readers.
 * - I think it's important to mention that I did see at least a couple other
 *   good solutions to this problem.  This is definitely not the only (or even
 *   necessarily the best) way to do things :)
 * - In the for loop, we only take `i` from 0 to length/2.  If length is even,
 *   this causes the loop to check all the pairs exactly once.  If length is
 *   odd, it will skip comparing the middle character to itself, but will still
 *   check all pairs.  If we let `i` go from 0 to length, we would be checking
 *   all possible pairs twice.
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int main() {
    string word;

    cout << "please enter a word: ";
    cin >> word;

    for (int i=0; i<word.length()/2; i++) {
        if (word[i] != word[word.length()-1-i]) {
            cout << "this word is not a palindrome...\n";
            return 0;
        }
    }

    cout << "this word is a palindrome!\n";
    return 0;
}

