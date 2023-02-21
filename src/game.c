#include <ncurses.h>
#include <stdio.h>
#include <ctype.h>

int game_cycle() {
	int x = 0, y = 0;
	int ch;

	WINDOW* info = newwin(LINES, 20, 0, 0);
	WINDOW* area = newwin(LINES - 5, COLS - 20, 0, 20);
	WINDOW* interactions = newwin(5, COLS - 20, LINES-5, 20);

	do {
		// clear();

		mvwprintw(info, 1, 1, "Level: 1");
		mvwprintw(info, 2, 1, "Exp: 3/8");
		mvwprintw(info, 3, 1, "Health: 12/24");
		wborder(info, 0, 0, 0, 0, 0, 0, 0, 0);
		mvwprintw(info, 0, 1, "Info");
		wrefresh(info);

		wclear(area);
		mvwprintw(area, ( LINES - 5 ) / 2 - y, (COLS - 20) / 2 - x, "x");
		mvwprintw(area, ( LINES - 5 ) / 2, (COLS - 20) / 2, "@");
		wborder(area, 0, 0, 0, 0, 0, 0, 0, 0);
		mvwprintw(area, 0, 1, "Area");	
		wrefresh(area);

		wclear(interactions);
		mvwprintw(interactions, 1, 1, "(O) open");
		mvwprintw(interactions, 2, 1, "(T) talk");
		wborder(interactions, 0, 0, 0, 0, 0, 0, 0, 0);
		mvwprintw(interactions, 0, 1, "Interactions");
		wrefresh(interactions);

		// move(LINES / 2 - y, COLS / 2 - x);
		// printw("x");

		// move(LINES / 2, COLS / 2);
		// printw("@");

		//refresh();
		ch = getchar();
		ch = tolower(ch);

		if (ch == 'w') {
			y--;
		} else if (ch == 's') {
			y++;
		} else if (ch == 'a') {
			x--;
		} else if (ch == 'd') {
			x++;
		}
		// move(y, x);
		// putchar('\1');
		// refresh();
	} while (ch != 'q' && !feof(stdin));

	delwin(interactions);
	delwin(info);
	delwin(area);

	return 0;
}

