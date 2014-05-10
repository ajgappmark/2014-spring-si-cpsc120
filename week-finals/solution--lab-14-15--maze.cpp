/**
 * Ben Blazak
 * week 14-15
 * solution to maze project (in-lab)
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;


const int rows = 21;
const int columns = 77;
char board[rows][columns+1] = {
"******************* === *****************************************************",
"*                 *     *                                                   *",
"*                 *     *                      ***************************  *",
"*       *  @@@@@  *     *  @@@@@  *            *                         *  *",
"*       *  @@@@@  *     *  @@@@@  *            *  *********************  *  *",
"*       *         *     *         *            *  *                   *  *  *",
"*       ***********     ***********            *  *  ******   ******  *  *  *",
"*                                              *  *  *             *  *  *  *",
"*                                              *  *  *  *********  *  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  *  *       *  *  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  *     ===  *  *     *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  *  *       *  *  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  *  *********  *  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  *             *  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *  ***************  *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *                   *  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *  *********************  *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~              *                         *  *",
"*    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~    *   *     ************   ************  *",
"*                                    *   *                                  *",
"************************************** i ************************************",
};


void print_board() {
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            cout << board[r][c];
        }
        cout << endl;
    }
}


int main() {
    int current_row;
    int current_column;

    // find starting location
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            if (board[r][c] == 'i') {
                current_row = r;
                current_column = c;
                break;
            }
        }
    }

    // loop
    for (;;) {
        print_board();
        cout << "\n\n";

        char command;
        cin.get(command);

        int new_row = current_row;
        int new_column = current_column;
        switch (command) {
            case 'w': new_row--; break;
            case 'a': new_column--; break;
            case 's': new_row++; break;
            case 'd': new_column++; break;
            default: continue;
        }

        if (    ( new_row    < 0 || new_row    > rows-1    )
             || ( new_column < 0 || new_column > columns-1 ) ) {

            cout << "\nYou fell off the edge of the board, and died :(\n";
            return 0;

        } else {
            char c = board[new_row][new_column];

            switch (c) {
                case ' ':
                case '@':
                case '~':
                case '=': board[current_row][current_column] = ' ';
                          board[new_row][new_column] = 'i';
                          current_row = new_row;
                          current_column = new_column;
            }

            switch (c) {
                case '@': print_board();
                          cout << "\nYou fell into the lava, and died, lol\n";
                          return 0;
                case '~': print_board();
                          cout << "\nYou fell into the water, and died :)\n";
                          return 0;
                case '=': print_board();
                          cout << "\nYou Won!!\n";
                          return 0;
            }
        }
    }
}

