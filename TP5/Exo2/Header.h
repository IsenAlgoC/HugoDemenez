#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Tableau {
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;

#define TAILLEINITIALE 10

TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);
int deleteElements(TABLEAU* tab, int startPos, int endPos);
