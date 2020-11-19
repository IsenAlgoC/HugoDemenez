#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ConsoleTools.h"
#include <locale.h>

#define Sleep(n) Sleep(n)

#define SIZEX 40
#define SIZEY 40
#define console 20
#define FEUILLETAILLEX 40 // taille de la feuille
#define FEUILLETAILLEY 30
#define CHENILLETAILLEMAX 20 // taille max de la chenille
#define CHENILLETAILLEINIT 5 // taille initiale de la chenille

typedef struct CHENILLE {
	int Size;
	char Direction;
	COORD tab[CHENILLETAILLEMAX];
}Chenille;

int DessineChenille(Chenille chenille);
char selectDirection(Chenille *chenille);
void InitFeuille();
int AvanceChenille(Chenille* chenille);
void InitChenille(Chenille* chenille);