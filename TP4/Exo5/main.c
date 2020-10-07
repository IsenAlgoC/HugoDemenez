#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>

int main() {
	char phrase[1024] ;
	
	int nbmot = 1;
	float caracteres = 0.00;

	printf("Entrez une phrase : ");
	gets_s(phrase, 1024);

	for (int i = 1; i < strlen(phrase); i++) {
		if (phrase[i] == ' ') {
			nbmot++;
		}
		else {
			caracteres++;
		}
	}

	printf("\nIl y a %d mots dans votre phrase", nbmot);
	printf("\nIl y a en moyenne %.4f caracteres dans vos mots ", caracteres / nbmot);
}