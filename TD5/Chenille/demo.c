#include "demo.h"

int main(int argc, char* argv[]) {
	// ouverture de la console
	openConsole();
	// effacement de l'�cran
	Chenille Chen;
	moveCursor(0, console);
	clearScreen();
	InitFeuille();
	InitChenille(&Chen);
	DessineChenille(Chen);
	
	while (Chen.Size != CHENILLETAILLEMAX) {
		//On r�duit la vitesse de la chenille
		Sleep(50);
		AvanceChenille(&Chen);
		DessineChenille(Chen);
	}
	
	// fermeture de la console
	moveCursor(0, FEUILLETAILLEY+1);
	printf_s("Votre chenille a atteint sa taille maximale ! Elle va pouvoir se transformer en beau papillon !\n");
	closeConsole();
 }







