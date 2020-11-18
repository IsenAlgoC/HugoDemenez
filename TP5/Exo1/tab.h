#pragma once

#include <stdio.h>
#include <stdlib.h>

int initTab(int* tab, int size);
int afficheTab(int* tab, int size, int nbElts);
int ajoutElementDansTableau(int* tab, int *size, int *nbElts, int element);

#define TAB2SIZE 100
#define TAILLEAJOUT 50