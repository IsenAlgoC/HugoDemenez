#include<stdio.h>
#include<stdlib.h>


main() {
	int val ;
	printf("Entrez la valeur :");
	scanf_s("%d", &val);

	switch (val) {
	case 4:
		printf("\nNiv max");
		break;
	case 3:
		printf("\nvalide niv 3");
		break;
	case 2:
		printf("\nvalide niv 2");
		break;
	case 1:
		printf("\nvalide niv 1");
		break;
	default: printf("non validé");
	}
}