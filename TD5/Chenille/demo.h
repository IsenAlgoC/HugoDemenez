#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ConsoleTools.h"
#include <locale.h>

#define Sleep(n) Sleep(n)

#define console 20
#define FEUILLETAILLEX 20 // taille de la feuille
#define FEUILLETAILLEY 20
#define CHENILLETAILLEMAX 20 // taille max de la chenille
#define CHENILLETAILLEINIT 6 // taille initiale de la chenille

typedef struct CHENILLE {
	int Size;
	char Direction;
	COORD tab[CHENILLETAILLEMAX];
}Chenille;

void DessineChenille(Chenille chenille);
void selectDirection(Chenille *chenille);
void InitFeuille();
int AvanceChenille(Chenille* chenille);
void InitChenille(Chenille* chenille);
void TailleAugmente(Chenille* chenille);