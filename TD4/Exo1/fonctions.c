
#include "Header.h"

int somme(int N) {
	int sum = 0;
	if (N < 0) {
		return -1;
	}
	else {
		for (int i = 0; i <= N; i++) {
			sum = sum + i;
		}
		return sum;
	}
}
