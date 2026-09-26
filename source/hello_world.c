#include <ncurses.h>

/**
 * @brief Entry point of the program.
 *
 * Initializes ncurses, displays a message and after any
 * type it closes an restores the terminal
 *
 * return 0 if the program exits ok
 *
*/

int main(void) {

    initscr();

    printw("hello world this is the begining\n");

    refresh();

    getch();

    endwin();

    return 0;
}
