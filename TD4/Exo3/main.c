#include "Header.h"

int main() {
	char tableau[1024];
	char entree =' ';
	printf("Entrez une cha�ne de caractere :");
	gets_s(tableau, 1024);

	printf("Le nombre de caractere est %d", compteCar(tableau,strlen(tableau)));
}