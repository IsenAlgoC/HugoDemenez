#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
main() {
	int guess;
	time_t t;
	srand((unsigned)time(&t));
	int random = rand()%1000;

	while (true) {

		printf("Devine : ");
		scanf_s("%d", &guess);
			if (guess == random) {
				return(EXIT_SUCCESS);
		}
			else {
				if (guess > random) {
					printf("C'est moins");
				}
				else {
					printf("C'est plus");
				}
			}

	}
}