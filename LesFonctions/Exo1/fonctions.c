#include "Header.h"

void Initialise(GrandEntier N) {
	for (int i = 0; i < NbChiffresMax; i++) {
		N[i] = 0;
	}
}

void Affiche(GrandEntier N){
	int compteur = 0;
	for (int i = 0; i < NbChiffresMax; i++) {
		if (compteur % 3 == 0) {
			printf(" ");
		}
		printf("%d", N[i]);
		compteur++;
		
	}
}

int AjouteADroite(GrandEntier N, int c) {
	if (N[0] != 0) {
		return -1;
	}
	int tmp = 0;
	for (int i = 0 ; i< NbChiffresMax-1; i++) {
		N[i ] = N[i+1];
	}
	N[NbChiffresMax-1] = c;
}

int Addition(GrandEntier A, GrandEntier B, GrandEntier Result) {
	int retenue = 0;
	int somme;
	for (int i = NbChiffresMax - 1; i >= 0; i--) {
		somme = A[i] + B[i] + retenue;
		Result[i] = (somme) % 10;
		if (somme > 9) retenue = 1;
		else { retenue = 0; }
	}
	if (retenue == 1) return -1;
	return (EXIT_SUCCESS);
}

/* FONCTION COMPLETE : NE DOIT PAS ETRE MODIFIEE */
int EntreeClavier(GrandEntier Nombre)
{
	int NbChiffresLus = 0;
	wchar_t car; // touche frappée en entrée
	wchar_t chiffre[2]; // variable type chaine de caractère Wide pour conversion
	// de car en entier avec _wtoi
	bool EstUnChiffre = false;
	Initialise(Nombre); // Nombre prend la valeur zero
	do
	{
		while ((car = _getwch()) == 0) {
			car = _getwch(); // touche de fonction ou direction enfoncée
		}; // lire la touche frappee au clavier
		if (EstUnChiffre = (bool)isdigit(car)) // s'il s'agit bien d'un chiffre
		{
			wprintf(L"%c", car); // echo ecran du chiffre valide
			chiffre[0] = car; // conversion du caractere en chaine null terminated pour _wtoi()
			chiffre[1] = 0;
			AjouteADroite(Nombre, _wtoi(chiffre)); // conversion du caractere en valeur numerique et
			NbChiffresLus++; // affectation dans le tableau qui contient le grand entier
		}
		else { // s'il s'agit d'un caractère de controle CLEAR (touche 'C' )
			if ((car == 'C') || (car == 'c')) {
				Initialise(Nombre); // effacement des caractères saisies
				printf("\nClear\n");
				EstUnChiffre = true; // pour continuer la saisie de ce nombre
			}
		}
	} while (EstUnChiffre && (NbChiffresLus < NbChiffresMax));
	printf("\n");

	if ((car == 'X') || (car == 'x')) return -1;
	return 0;
}
