#include "Header.h"



int main() {
    char mot[1024] ;
    char car ;

    printf("Entrez une phrase :");
    gets_s(mot, 1024);

    printf("Quel caractere cherchez vous ? :");
    scanf_s("%c", &car);

    int nombreoccur = occur(mot, strlen(mot), car);
    printf("\nIl y a %d occurence(s)", nombreoccur);
}