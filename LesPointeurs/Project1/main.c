#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <locale.h>

char* cloneStr(char*);

char* cloneStr(char* mot) {
	//Si le pointeur mot entr� est NULL alors on renvoit un pointeur NULL
	if (mot == NULL) {
		return NULL;
	}

	// 
	char* mot2 = NULL;
	int len = strlen(mot);
	char* mot2;


	//Le pointeur mot2 re�oit une taille d'allocation n�cessaire pour �crire le mot
	mot2 = (int*)malloc(len + 1);

	//Si l'allocation est NULL alors on renvoit un pointeur NULL
	if (mot2 == NULL) {
		return NULL;
	}



	//On copie mot dans mot2
	*mot2 = *mot;

	//La fonction renvoie le nouveau mot
	return (mot2);
}

int main() {
	char mot[] = "BONJOUR";
	char* nouveaumot;
	nouveaumot = cloneStr(mot);
}


