#include <stdlib.h>
#include<stdio.h>


main() {

	long long numerodecq;
	printf("Entrez le numero de securite sociale :");
	scanf_s("%d", &numerodecq);




	printf("Votre cle est : %d\n", (long long)numerodecq%97);

	if ((int)numerodecq / 100000000000 == 1)
	{
		printf("Vous etes un homme");
	}
	else {
		printf("Vous etes une femme");
	}
}