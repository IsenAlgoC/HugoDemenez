#include <Windows.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ConsoleTools.h"


int clipping;
int ellipse(COORD centre, double rayonX, double rayonY);
int cercle(COORD centre, double rayon);
int lissajous(COORD centre, double rayonX, double rayonY, double p, double q);


#define Pi 3.14159265358979
#define SIZEX 40
#define SIZEY 40
#define body '\xDB'
#define head 'O'
#define Apple '@'
#define vide ' '
#define sizemax 20
#define sizeinit 5
#define console 20
#define FEUILLETAILLEX 40 // taille de la feuille
#define FEUILLETAILLEY 30
#define CHENILLETAILLEMAX 20 // taille max de la chenille
#define CHENILLETAILLEINIT 5 // taille initiale de la chenille


typedef struct CHENILLE {
	int Size;
	char Direction;
	COORD tab[sizemax];
}Chenille;


int DessineChenille(Chenille chenille);
char selectDirection(Chenille chenille);
void InitFeuille();
int AvanceChenille(Chenille* chenille);