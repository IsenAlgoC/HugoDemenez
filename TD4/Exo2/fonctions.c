#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int remplirTab(float tab[], int tabSize, int nbVal, float min, float max) {
	float tab = tab[tabSize];
	if (nbVal > tabSize || nbVal == 0 || tabSize == 0) { return -1; }
	for (int i = 0; i < nbVal; i++) {
		tab[i] = rangeRand(min, max);
	}

	return nbVal;
}

int afficherTab(float tab[], int tabSize, int nbVal) {
	if (nbVal > tabSize) {
		return -1;
	}
	for (int i = 0; i < nbVal; i++) {
		printf("%d", tab[i]);
	}
	return nbVal;
}

float rangeRand(float range_min, float range_max) {
	float u = (float)((double)rand() / ((double)RAND_MAX + 1) * ((double)range_max - (double)range_min)) + range_min;
	return (u);
}

int maxTab(float tab[], int tabSize, int nbVal) {
	if (nbVal > tabSize || nbVal == 0 || tabSize == 0) { 
		return -1; 
	}
	 
	float max=tab[0];
	int positionmax = 0;
	for (int i = 0; i < nbVal; i++) {
		if (tab[i] > max) {
			max = tab[i];
			positionmax = i;
		}
	}
}