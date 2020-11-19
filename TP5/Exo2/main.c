#include "Header.h"


int main() {
	TABLEAU MonTableau;
	MonTableau = newArray();
	displayElements(&MonTableau, 0, 5);

	setElement(&MonTableau, 5, 10);
	incrementArraySize(&MonTableau, 2);
	displayElements(&MonTableau, 0, TAILLEINITIALE);
	
}