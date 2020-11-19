#include "demo.h"
#include "ConsoleTools.h"

char feuille[SIZEX][SIZEY] = { ' ' };

char selectDirection(Chenille *chenille) {
	int valeur = rangedRand(0, 4);
	switch (valeur) {
	case 0 :
		chenille->Direction = 'H';
		break;
	case 1:
		chenille->Direction = 'B';
		break;
	case 2:
		chenille->Direction = 'G';
		break;
	case 3:
		chenille->Direction = 'D';
		break;
	}
	return EXIT_SUCCESS;
}

void InitFeuille() {
	int nbpomme = 0;
	for (int x = 0; x < FEUILLETAILLEX; x++) {
		for (int y = 0; y < FEUILLETAILLEY; y++) {
			moveCursor(x, y);
			if (rangedRand(0, 100)==1 && nbpomme < 15) {
				plotChar('@');
				feuille[x][y] = '@';
				nbpomme++;
			}
			else { plotChar(' '); }
		}
	}
}


void InitChenille(Chenille* chenille) {
	//On donne une taille initiale à la chenille
	chenille->Size = CHENILLETAILLEINIT ;
	//La direction initiale de la chenille est la droite
	chenille->Direction = 'D';
	//On positionne la chenille en haut à gauche du tableau
	for (int i = 0; i < chenille->Size; i++) {
		chenille->tab[i].X = i;
		chenille->tab[i].Y = 0;
	}
}

int DessineChenille(Chenille chenille) {
	for (int i = 0; i < chenille.Size; i++) {
		int X=chenille.tab[i].X ;
		int Y=chenille.tab[i].Y ;
		moveCursor(X, Y);
		plotChar('*');
	}
}

int AvanceChenille(Chenille* chenille) {
	selectDirection(chenille);
	switch (chenille->Direction) {
	case 'H':
		if (chenille->tab[0].Y > 0) {
			chenille->tab[chenille->Size].Y= (chenille->tab[0].Y)-1;
			return 0;
		}
		else {
			return -1;
		}
			break;
	case 'B':
		if (chenille->tab[chenille->Size].Y < FEUILLETAILLEY) {
			chenille->tab[chenille->Size].Y = (chenille->tab[0].Y) + 1;
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 'G':
		if (chenille->tab[0].X >0) {
			chenille->tab[chenille->Size].X = (chenille->tab[0].X) - 1;
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 'D':
		if (chenille->tab[chenille->Size].X < FEUILLETAILLEY) {
			chenille->tab[chenille->Size].X = (chenille->tab[chenille->Size].X) + 1;
			return 0;
		}
		else {
			return -1;
		}
		break;
	}
	
}