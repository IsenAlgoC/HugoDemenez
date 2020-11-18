#include "Header.h"


int main() {
	TABLEAU MonTableau;
	MonTableau = newArray();
	displayElements(&MonTableau, 0, 5);
	incrementArraySize(&MonTableau, 5);
	displayElements(&MonTableau, 0, TAILLEINITIALE+5);
}