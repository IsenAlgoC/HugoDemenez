#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int somme(int N) {
	int sum = 0;
	for (int i = 0; i <= N; i++) {
		sum = sum + i;
	}
	return sum;
}
