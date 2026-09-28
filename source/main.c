/**
 * @file main.c
 * @brief Simple ncurses menu with Play, Create and Quit options.
 *
 * This program creates a TUI using ncurses and panels.
 *
 * The user can navigate through the menu using the UP and DOWN
 * arrow keys and select an option using ENTER.
 *
 * @author Aggelos
 * @version 1.0
 */

#include <ncurses.h>
#include <panel.h>

/**
 * @brief Number of menu choices.
 */
#define MENU_ITEMS 3

/**
 * @brief Main entry point of the application.
 *
 * Initializes ncurses, creates a window and panel, displays the
 * main menu, and handles keyboard input.
 *
 * The available options are:
 * - Play
 * - Create
 * - Quit
 *
 * @return 0 when the program exits successfully.
 */
int main(void)
{
    /**
     * @brief Initialize ncurses.
     *
     * This switches the terminal into ncurses mode.
     */
    initscr();

    /**
     * @brief Enable special keys such as arrow keys.
     */
    keypad(stdscr, TRUE);

    /**
     * @brief Prevent typed characters from being automatically displayed.
     */
    noecho();

    /**
     * @brief Create the main application window.
     *
     * Arguments:
     * - Height: 10 rows
     * - Width: 30 columns
     * - Y position: 15
     * - X position: 20
     */
    WINDOW *win = newwin(20, 60, 15, 20);

    /**
     * @brief Create a panel associated with the window.
     *
     * Panels allow windows to be managed as layers.
     */
    PANEL *panel = new_panel(win);

    /**
     * @brief Menu entries.
     */
    const char *choices[MENU_ITEMS] = {
        "Play",
        "Create",
        "Quit"
    };

    /**
     * @brief Index of the currently selected menu item.
     *
     * 0 = Play
     * 1 = Create
     * 2 = Quit
     */
    int selected = 0;

    /**
     * @brief Stores keyboard input.
     */
    int ch;

    /*
     * Main menu loop.
     */
    while (1)
    {
        /* Clear the contents of the window. */
        werase(win);

        /* Draw a border around the window. */
        box(win, 0, 0);

        /* Display the application title. */
        mvwprintw(win, 1, 11, "MOrds Where Pinute");

        /**
         * Draw each menu item.
         *
         * The currently selected item is displayed using
         * reverse video.
         */
        for (int i = 0; i < MENU_ITEMS; i++)
        {
            if (i == selected)
            {
                /* Highlight selected item. */
                wattron(win, A_REVERSE);

                mvwprintw(
                    win,
                    3 + i,
                    10,
                    "> %s",
                    choices[i]
                );

                /* Stop highlighting. */
                wattroff(win, A_REVERSE);
            }
            else
            {
                /* Display an unselected item. */
                mvwprintw(
                    win,
                    3 + i,
                    10,
                    "  %s",
                    choices[i]
                );
            }
        }

        /*
         * Update the panel stack and refresh the terminal.
         */
        update_panels();
        doupdate();

        /*
         * Wait for keyboard input.
         */
        ch = getch();

        /*
         * Move selection upward.
         */
        if (ch == KEY_UP)
        {
            selected--;

            /* Wrap to the last item. */
            if (selected < 0)
            {
                selected = MENU_ITEMS - 1;
            }
        }

        /*
         * Move selection downward.
         */
        else if (ch == KEY_DOWN)
        {
            selected++;

            /* Wrap to the first item. */
            if (selected >= MENU_ITEMS)
            {
                selected = 0;
            }
        }

        /*
         * Handle ENTER.
         */
        else if (ch == '\n' || ch == KEY_ENTER)
        {
            /*
             * PLAY
             */
            if (selected == 0)
            {
                werase(win);
                box(win, 0, 0);

                mvwprintw(
                    win,
                    4,
                    10,
                    "Starting game!"
                );

                update_panels();
                doupdate();

                getch();
            }

            /*
             * CREATE
             */
            else if (selected == 1)
            {
                werase(win);
                box(win, 0, 0);

                mvwprintw(
                    win,
                    4,
                    10,
                    "Create mode!"
                );

                update_panels();
                doupdate();

                getch();
            }

            /*
             * QUIT
             */
            else if (selected == 2)
            {
                break;
            }
        }
    }

    /*
     * Clean up the panel.
     */
    del_panel(panel);

    /*
     * Clean up the window.
     */
    delwin(win);

    /*
     * Return the terminal to normal mode.
     */
    endwin();

    return 0;
}

