#include<stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <string.h>


int main() {
	char mot[20];
	char mot2[20];

	printf("\nEntrez votre mot : ");
	scanf_s("%s", &mot, _countof(mot));


	int min = 0;
	int max = strlen(mot) - 1;
    while (max > min)
    {
        if (mot[min++] != mot[max--])
        {
            printf("%s n'est pas un Palindrome", mot);
            return (EXIT_SUCCESS);
        }
    }
    printf("%s est palindrome", mot);

}