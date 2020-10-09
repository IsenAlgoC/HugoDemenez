#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int compteCar(char chaine[], int tailleMax) {
	if (tailleMax < 1) {
		return -1;
	}
	int compteur = 0;
	int i = 0;
	while (chaine[i] != '\0') {
		compteur++;
		i++;
	}
	return compteur;
}
