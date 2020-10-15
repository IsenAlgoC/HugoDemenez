#include "Header.h"


int swap(int* A, int* B) {
	if (*A == NULL || *B == NULL) {
		return -1;
	}
	else {
		int tmp = A;
		A = B;
		B = tmp;
	}
}


int  ordonne(int* A, int* B) {
	if (*A >  *B) {
		swap(A, B);
	}
}