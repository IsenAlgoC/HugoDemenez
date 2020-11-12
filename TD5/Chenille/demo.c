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

	moveCursor(0, console);
	// fermeture de la console
	closeConsole();
 }





int plot(COORD coord) {

}







