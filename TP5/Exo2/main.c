#include "Header.h"


int main() {
	TABLEAU MonTableau;
	MonTableau = newArray();
	displayElements(&MonTableau, 0, 5);

	setElement(&MonTableau, 5, 10);
	incrementArraySize(&MonTableau, 3);
	setElement(&MonTableau, 10, 7);
	displayElements(&MonTableau, 0, MonTableau.size);
	setElement(&MonTableau, 7, 3);
	deleteElements(&MonTableau, 2, 6);
	
	displayElements(&MonTableau, 0, MonTableau.size);
}