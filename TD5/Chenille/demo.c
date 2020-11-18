#include "demo.h"

int main(int argc, char* argv[]) {
	// ouverture de la console
	openConsole();
	// effacement de l'écran

	moveCursor(0, console);
	clearScreen();
	InitFeuille();
	// fermeture de la console
	closeConsole();
 }







