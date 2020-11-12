#include "demo.h"
#include "ConsoleTools.h"

char feuille[SIZEX][SIZEY] = { ' ' };

char selectDirection(Chenille chenille) {
	int valeur = rangedRand(0, 4);
	switch (valeur) {
	case 0 :
		chenille.Direction = "H";
		break;
	case 1:
		chenille.Direction = "B";
		break;
	case 2:
		chenille.Direction = "G";
		break;
	case 3:
		chenille.Direction = "D";
		break;
	}
	return EXIT_SUCCESS;
}

void InitFeuille() {
	int nbpomme = 0;
	for (int x = 0; x < FEUILLETAILLEX; x++) {
		for (int y = 0; y < FEUILLETAILLEY; y++) {
			moveCursor(x, y);
			if (rangedRand(0, 4)==2 &&nbpomme < 15) {
				plotChar("@");
				nbpomme++;
			}
			else { plotChar(" "); }
		}
	}
}


void InitChenille(Chenille* chenille) {
	chenille->Size = CHENILLETAILLEINIT ;
	chenille->Direction = "D";
	for (int i = 0; i < sizemax; i++) {
		chenille->tab[i].X = i;
		chenille->tab[i].Y = 0;
	}
}

int DessineChenille(Chenille chenille) {
	for (int i = 0; i < sizemax; i++) {
		int X=chenille.tab[i].X ;
		int Y=chenille.tab[i].Y ;
		moveCursor(X, Y);
		plotChar("*");
	}
}

int AvanceChenille(Chenille* chenille) {
	selectDirection(*chenille);

}