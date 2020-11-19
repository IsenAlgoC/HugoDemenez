#include "demo.h"

int main(int argc, char* argv[]) {
	// ouverture de la console
	openConsole();
	// effacement de l'écran
	Chenille Chen;
	moveCursor(0, console);
	clearScreen();
	InitFeuille();
	InitChenille(&Chen);
	DessineChenille(Chen);
	while (Chen.Size != CHENILLETAILLEMAX) {
		Sleep(100);
		AvanceChenille(&Chen);
		DessineChenille(Chen);
	}
	
	// fermeture de la console
	moveCursor(FEUILLETAILLEX, FEUILLETAILLEY);
	closeConsole();
 }







