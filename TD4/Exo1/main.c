#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int somme(N) {
	int sum = 0;
	for (int i = 0; i <= N; i++) {
		sum = sum + i;
	}
	return sum;
}

int main() {
	int N = 10;

	printf("%d", somme(N));
}
