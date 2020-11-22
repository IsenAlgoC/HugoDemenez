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
		Sleep(50);
		AvanceChenille(&Chen);
		DessineChenille(Chen);
	}
	
	// fermeture de la console
	moveCursor(0, FEUILLETAILLEY+1);
	printf_s("Votre chenille a atteint sa taille maximale ! Fin du programme, bonne journee !");
	closeConsole();
 }







