#include "demo.h"
#include "ConsoleTools.h"

char feuille[FEUILLETAILLEX][FEUILLETAILLEY] = { ' ' };

void selectDirection(Chenille *chenille) {
	int valeur = rangedRand(0, 4);
	switch (valeur) {
	case 0 :
		//On verifie qu'elle ne retourne pas sur elle meme sinon elle garde la meme direction
		if (chenille->Direction != 'B') {
			chenille->Direction = 'H';
		}
		break;
	case 1:
		//On verifie qu'elle ne retourne pas sur elle meme sinon elle garde la meme direction
		if (chenille->Direction != 'H') {
			chenille->Direction = 'B';
		}
		break;
	case 2:
		//On verifie qu'elle ne retourne pas sur elle meme sinon elle garde la meme direction
		if (chenille->Direction != 'D') {
			chenille->Direction = 'G';
		}
		break;
	case 3:
		//On verifie qu'elle ne retourne pas sur elle meme sinon elle garde la meme direction
		if (chenille->Direction != 'G') {
			chenille->Direction = 'D';
		}
		break;
	}
}

void InitFeuille() {
	int nbpomme = 0;
	for (int x = 0; x < FEUILLETAILLEX; x++) {
		for (int y = 0; y < FEUILLETAILLEY; y++) {
			moveCursor(x, y);
			//On met 30 pommes dans la feuille
			if (rangedRand(0, 25)==1 && nbpomme < 30) {
				plotChar(POMME);
				feuille[x][y] = POMME;
				nbpomme++;
			}
			else { plotChar(VIDE); }
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

void DessineChenille(Chenille chenille) {
	
	//On dessine le corps
	for (int i = 1; i < chenille.Size; i++) {
		int X=chenille.tab[i].X ;
		int Y=chenille.tab[i].Y ;
		moveCursor(X, Y);
		plotChar(CORPS);
	}
	//On dessine la tête 
	int X = chenille.tab[0].X;
	int Y = chenille.tab[0].Y;
	moveCursor(X, Y);
	plotChar(TETE);
}

void TailleAugmente(Chenille* chenille) {
	if (chenille->Size != CHENILLETAILLEMAX) {
		chenille->Size = chenille->Size + 1;
	}
}

int START = 1;

int AvanceChenille(Chenille* chenille) {
	hideCursor();
	//On gere la position de la chenille au demarrage pour eviter qu'elle se retourne sur elle même
	if (START == 0) {
		selectDirection(chenille);
	}
	else {
		chenille->Direction = 'B';
		START = 0;
	}
	COORD poshead = chenille->tab[0];
	switch (chenille->Direction) {
	case 'H':
		poshead.Y--;
		break;
	case 'B':
		poshead.Y++;
		break;
	case 'G':
		poshead.X--;
		break;
	case 'D':
		poshead.X++;
		break;
	}
	//Futur position hors feuille
	if (poshead.X < 0 || poshead.X >= FEUILLETAILLEX || poshead.Y < 0 || poshead.Y >= FEUILLETAILLEY) {
		return -1;
	}
	//Si on ne mange pas de pomme
	if (feuille[poshead.X][poshead.Y] != POMME) {
		moveCursor(chenille->tab[chenille->Size - 1].X, chenille->tab[chenille->Size - 1].Y);
		//On met le terme qui est dans la feuille à la place de la queue
		plotChar(VIDE);
	}
	//Sinon il y a une pomme
	else {
		chenille->Size++;
		//On retire la pomme de la feuille
		feuille[poshead.X][poshead.Y] = VIDE;
	}
	//On décale les elements du corps de la chenille
	for (int i = chenille->Size - 1; i > 0; i--) {
		chenille->tab[i] = chenille->tab[i - 1];
	}
	//On change la position de la tete
	chenille->tab[0] = poshead;

	return EXIT_SUCCESS;
}