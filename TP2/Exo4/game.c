#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
main() {
	int guess;
	time_t t;
	srand((unsigned)time(&t));
	int random = rand()%1000;
	int compteur = 0;
	while (true) {
		printf("%d",random);
		printf("Devine : ");
		scanf_s("%d", &guess);
			if (guess == random) {
				compteur++;
				printf("Bien joue vous avez reussi en %d coups", compteur);
				return(EXIT_SUCCESS);
		}
			else {
				if (guess > random) {
					printf("C'est moins");
					compteur++;
				}
				else {
					printf("C'est plus");
					compteur++;
				}
			}

	}
}