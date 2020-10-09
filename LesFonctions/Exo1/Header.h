#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

#define NbChiffresMax 30
typedef int GrandEntier[NbChiffresMax];


void Affiche(GrandEntier N);
void Initialise(GrandEntier N);
int AjouteADroite(GrandEntier N, int c);
int Addition(GrandEntier A, GrandEntier B, GrandEntier result);
int EntreeClavier(GrandEntier Nombre);