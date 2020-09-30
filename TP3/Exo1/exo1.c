#include <stdio.h>
#include <stdlib.h>

#define carre(x) (x)*(x)

int main() {
	int NB = 6;
	printf("%d", carre(NB));
	printf("\n%d", carre(NB + 1));
	// Il affiche NB + NB+1
	//Il suffit de mettre des parenthèses autour des x pour corriger le problème
}


