#pragma once

//Inclusion des biblioth�ques
#include <stdio.h>
#include <stdlib.h>

//D�claration des fonctions
int initTab(int* tab, int size);
int afficheTab(int* tab, int size, int nbElts);
int ajoutElementDansTableau(int* tab, int *size, int *nbElts, int element);

//D�claration des constantes
#define TAB2SIZE 100
#define TAILLEAJOUT 50