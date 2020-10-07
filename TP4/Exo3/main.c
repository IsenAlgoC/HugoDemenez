#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<stdbool.h>
#include<math.h>

#define TAILLEMOT 20

int main() {
	char nom[TAILLEMOT];
	char prenom[TAILLEMOT];
	char sexe;
	printf("\nBonjour, quel est votre nom ? :");
	scanf_s("%s", &nom,_countof(nom));

	printf("\nQuel est votre prenom ? :");
	scanf_s("%s", prenom,_countof(prenom));

	printf("\nEtes vous un (H)omme ou une (F)emme ? : ");
	do { sexe = _getch(); } while (sexe != 'H' && sexe != 'F');
	switch (sexe) {
	case 'F':
		printf("\nMadame %s %s", prenom, nom);
		break;
	case 'H':
		printf("\nMonsieur %s %s", prenom, nom);
		break;
	}

}