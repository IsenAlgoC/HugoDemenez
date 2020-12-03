#pragma once
#include "listes.h"

// Pile implémentée à l'aide d'une Single Linked List
typedef struct SLLStack {
	LinkedList* list;
	int stackMaxSize; // doit-on garder cette propriété ?
	int stackNbElemts; // nb elements actuellement stockés
} SLLStack;

// implémentation avec des listes unilatères (SLL)
void SLLNewStack(SLLStack** stack);
int SLLisStackFull(SLLStack* stack);
int SLLisStackEmpty(SLLStack* stack);
int SLLpush(SLLStack* stack, int value);
int SLLpull(SLLStack* stack, int* value);
int SLLpeek(SLLStack* stack, int* value);
