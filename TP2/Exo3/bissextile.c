#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
main()
{
	int year;
	while (true)
	{
		printf("Quelle annee tester ? :");
		scanf_s("%d", &year);

		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					printf("C'est une annee bissextile\n");
				}
				else {
					printf("Ce n'est pas une annee bissextile\n");
				}
			}
			else {
				printf("Ce n'est pas une annee bissextile\n");
			}
		}
		else {
			printf("Ce n'est pas une annee bissextile\n");
		}



		if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
			printf("Cette annee est une annee bissextile\n");
		}
		else {
			printf("Cette annee n'est pas une annee bissextile\n");
		}
	}
	return(EXIT_SUCCESS);
}