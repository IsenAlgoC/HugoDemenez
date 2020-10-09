#include "Header.h"



int factorielle(int n) {
	if (n >= N) {
		for (int i = N+1; i <= n; i++) {
			produit = produit * i;
		}
	}
	else {
		produit = 1;
		for (int i = 1; i <= n; i++) {
			produit = produit * i;
		}
	}
	N = n;
	return produit;
}