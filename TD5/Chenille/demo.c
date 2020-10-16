#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ConsoleTools.h"
#include <locale.h>
#include "demo.h"







int main(int argc, char* argv[]) {
	COORD consoleSize;
	COORD centre = { console / 2,console / 2 };
	COORD pos = { 0,0 };
	char allKey[] = "()wW0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMmNoOqQrRsStTuUwWyxXYzZ+-*/=<.\n\r";
	char key;

	// ouverture de la console
	openConsole();

	// limite de la zone d'écriture
	consoleSize.X = console;
	consoleSize.Y = console;
	// effacement de l'écran
	clearScreen();
	fenetre();
	chenilleaff();
	moveCursor(0, console);
	// fermeture de la console
	closeConsole();
 }





int plot(COORD coord) {
	int wasclipped = 0;
	if (!clipping) {
		moveCursor(coord.X, coord.Y);
		plotChar('*');
		wasclipped = 0;
	}
	else {
		if ((coord.X >= 0) && (coord.X < consoleSize.X) && (coord.Y >= 0) && (coord.Y < consoleSize.Y)) {
			moveCursor(coord.X, coord.Y);
			plotChar('*');
			wasclipped = 0;
		}
		else {
			wasclipped = 1;
		}
	}
	return(wasclipped);
}



void fenetre() {
	for (int i = 1; i < console; i++) {
		moveCursor(0, i);
		plotChar('|');
		moveCursor(console-1, i);
		plotChar('|');
		moveCursor(i, 0);
		plotChar('-');
		moveCursor(i, console-1);
		plotChar('-');
	}

	return(EXIT_SUCCESS);

}

void chenilleaff(Chenille) {

}




