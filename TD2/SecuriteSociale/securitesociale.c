#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>

main() {
	int gender;
	SYSTEMTIME st;
	GetSystemTime(&st);

	//Debut de la boucle tant que 


	while (true) {



		long long numero;
		printf("Entrez le numero de securite sociale :");
		scanf_s("%d", &numero);
		printf("Votre cle est : %d\n", (int)numero % 97);

		if ((int)numero / (long long)10E12 == 1)
		{
			printf("Vous etes un homme");
		}
		else {
			printf("\nVous etes une femme");
		}

		gender = (int)(numero / (long long)1E12);

	}
}