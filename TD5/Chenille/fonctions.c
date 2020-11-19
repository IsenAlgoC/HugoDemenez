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
			if (rangedRand(0, 50)==1 && nbpomme < 15) {
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

void DessineChenille(Chenille chenille) {
	for (int i = 0; i < chenille.Size; i++) {
		int X=chenille.tab[i].X ;
		int Y=chenille.tab[i].Y ;
		moveCursor(X, Y);
		plotChar('*');
	}
}

void TailleAugmente(Chenille* chenille) {
	if (chenille->Size != CHENILLETAILLEMAX) {
		chenille->Size = chenille->Size + 1;
	}
}

int AvanceChenille(Chenille* chenille) {
	selectDirection(chenille);
	switch (chenille->Direction) {
	case 'H':
		if (chenille->tab[0].Y > 0) {
			//On verifie si on va manger une pomme
			int posheadX = chenille->tab[chenille->Size - 1].X;
			int posheadY = (chenille->tab[chenille->Size - 1].Y) - 1;
			//Si on mange une pomme alors on augmente la taille de la chenille 
			if (feuille[posheadX][posheadY] == '@') {
				TailleAugmente(chenille);
				chenille->tab[chenille->Size - 1].Y = posheadY;
				chenille->tab[chenille->Size - 1].X = posheadX ;
				return 0;
			}
			//On va supprimer dans la console le caractère de gauche de la chenille
			int X = chenille->tab[0].X;
			int Y = chenille->tab[0].Y;
			moveCursor(X, Y);
			plotChar(' ');
			//On décale tous les caractères de la chenille à la position de celui d'après jusqu'à l'avant dernier selon les X
			for (int i = 0; i < chenille->Size-1; i++) {
				chenille->tab[i].X = (chenille->tab[i+1].X);
				chenille->tab[i].Y = (chenille->tab[i + 1].Y);
			}
			//Le dernier caractère de la chenille monte selon Y
			chenille->tab[chenille->Size-1].Y=(chenille->tab[chenille->Size - 1].Y)-1;

			
			return 0;
		}
		else {
			return -1;
		}
			break;
	case 'B':
		if (chenille->tab[chenille->Size-1].Y < FEUILLETAILLEY) {
			//On verifie si on va manger une pomme
			int posheadX = chenille->tab[chenille->Size - 1].X;
			int posheadY = (chenille->tab[chenille->Size - 1].Y) + 1;
			//Si on mange une pomme alors on augmente la taille de la chenille 
			if (feuille[posheadX][posheadY] == '@') {
				TailleAugmente(chenille);
				chenille->tab[chenille->Size - 1].Y = posheadY;
				chenille->tab[chenille->Size - 1].X = posheadX;
				return 0; 
			}
			//On efface le premier caractère à gauche de la chenille dans la console
			int X = chenille->tab[0].X;
			int Y = chenille->tab[0].Y;
			moveCursor(X, Y);
			plotChar(' ');
			//On décale tous les caractères de la chenille à la position du suivant jusqu'à l'avant dernier 
			for (int i = 0; i < chenille->Size - 1; i++) {
				chenille->tab[i].X = (chenille->tab[i + 1].X);
				chenille->tab[i].Y = (chenille->tab[i + 1].Y);
			}
			//On descend le dernier caractère de la chenille selon Y
			chenille->tab[chenille->Size-1].Y = (chenille->tab[chenille->Size-1].Y) + 1;
			
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 'G':
		if (chenille->tab[0].X >0) {
			//On verifie si on va mange rune pomme
			int posheadX = (chenille->tab[0].X) - 1;
			int posheadY = (chenille->tab[0].Y);
			//Si on mange une pomme alors on augmente la taille de la chenille 
			if (feuille[posheadX][posheadY] == '@') {
				TailleAugmente(chenille);
				chenille->tab[chenille->Size - 1].Y=posheadY;
				chenille->tab[chenille->Size - 1].X = posheadX;
				return 0;
			}
			//On supprime le dernier caractère de la chenille dans la console
			int X = chenille->tab[chenille->Size-1].X;
			int Y = chenille->tab[chenille->Size-1].Y;
			moveCursor(X, Y);
			plotChar(' ');
			//On décale tous les caractères vers la position du précédent à partir de la fin 
			for (int i = chenille->Size - 1; i > 0; i--) {
				chenille->tab[i].X = (chenille->tab[i - 1].X);
				chenille->tab[i].Y = (chenille->tab[i - 1].Y);
			}
			//On décale le premier element vers la gauche selon les X
			chenille->tab[0].X = (chenille->tab[0].X) - 1;
			
			return 0;
		}
		else {
			return -1;
		}
		break;
	case 'D':
		if (chenille->tab[chenille->Size-1].X < FEUILLETAILLEY) {
			//On verifie si on va manger une pomme
			int posheadX = (chenille->tab[chenille->Size - 1].X) + 1;
			int posheadY = chenille->tab[chenille->Size - 1].Y;
			//Si on mange une pomme alors on augmente la taille de la chenille 
			if (feuille[posheadX][posheadY] == '@') {
				TailleAugmente(chenille);
				chenille->tab[chenille->Size - 1].X = posheadX;
				chenille->tab[chenille->Size - 1].Y = posheadY;
				return 0;
			}
			//On suprime le premier caractère à gauche de la chenille dans la console
			int X = chenille->tab[0].X;
			int Y = chenille->tab[0].Y;
			moveCursor(X, Y);
			plotChar(' ');
			//On décale tous les elements de la chenille à la place de l'element suivant jusqu'à l'avant dernier vers la droite
			for (int i = 0 ; i < chenille->Size-1; i++) {
				chenille->tab[i].X = (chenille->tab[i + 1].X);
				chenille->tab[i].Y = (chenille->tab[i + 1].Y);
			}
			//On décale le dernier element de la chenille vers la droite
			chenille->tab[chenille->Size-1].X = (chenille->tab[chenille->Size-1].X) + 1;
			
			return 0;
		}
		else {
			return -1;
		}
		break;
	}
	
}