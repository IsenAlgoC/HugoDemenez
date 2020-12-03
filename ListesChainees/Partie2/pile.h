#pragma once
#include "listes.h"

// Pile impl�ment�e � l'aide d'une Single Linked List
typedef struct SLLStack {
	LinkedList* list;
	int stackMaxSize; // doit-on garder cette propri�t� ?
	int stackNbElemts; // nb elements actuellement stock�s
} SLLStack;

// impl�mentation avec des listes unilat�res (SLL)
void SLLNewStack(SLLStack** stack);
int SLLisStackFull(SLLStack* stack);
int SLLisStackEmpty(SLLStack* stack);
int SLLpush(SLLStack* stack, int value);
int SLLpull(SLLStack* stack, int* value);
int SLLpeek(SLLStack* stack, int* value);
