#include "Header.h"


bool isMagic(int carre[sizeCarre][sizeCarre]) {
	bool magic=true;
	int somme1 = 0;
	int somme2 = 0;
	for (int i = 0; i < sizeCarre; i++) {
		somme1 = somme1 + carre[i][i];
	}

	for (int i = 0; i < sizeCarre; i++) {
		somme2 = somme2 + carre[0][i];
	}
	if (somme1 == somme2) {
		somme1 = 0;
		for (int i = 0; i < sizeCarre; i++) {
			somme1 = somme1 + carre[i][0];
		}
	}

	if (somme1 == somme2) {
		return magic;
	}
	else {
		magic = false;
		return magic;
	}

}