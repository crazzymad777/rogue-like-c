#include <ncurses.h>
#include <stdio.h>
#include "game.h"

int enter_curses();

int main(int argc, char* argv[]) {
	return enter_curses();
}

int enter_curses() {
	initscr();
	curs_set(0);
	// move(30, 30);
	// printf("Good speed");
	// refresh();
	// getchar();
	game_cycle();
	endwin();
	return 0;
}

