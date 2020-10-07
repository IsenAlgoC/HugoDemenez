#include<stdio.h>
#include<stdlib.h>
#include "Header.h"

#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {

	//Initialisation du tableur
	int MyTab1[TAILLETAB1];

	//Remplissage du tableur
	for (int i = 0; i < TAILLETAB1; i++) {
		MyTab1[i] = i+1;
	}

	//Affichage du tableur
	for (int i = 0; i < TAILLETAB1; i++) {
		printf("%d%c", MyTab1[i], SEPARATEUR);
	}

	//Initialisation du pointeur sur la derniere valeur du tableur
	MyPtr1 = &MyTab1[19];

	//Passage à la ligne
	printf("\n");

	//Lecture du pointeur
	for (int i = 0; i < TAILLETAB1; i++) {
		printf("%d%c", *MyPtr1,SEPARATEUR);
		MyPtr1--;
	}
}