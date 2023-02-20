#include <ncurses.h>
#include <stdio.h>
#include <ctype.h>

int game_cycle() {
	int x = 0, y = 0;
	int ch;
	do {
		clear();

		move(LINES / 2, (COLS / 2 - 40 / 2) + 20);
		printw("@");

		refresh();
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
	return 0;
}

