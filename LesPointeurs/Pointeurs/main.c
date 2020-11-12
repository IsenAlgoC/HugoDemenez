#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define Debug

char* cloneStr(char* word) {
	char* tmp = NULL;
	int len = 0;
	if (word != NULL) {
		len = strlen(word);
		tmp = (char*)malloc(len + 1);

		if (tmp != NULL) {
			strcpy_s(tmp,len+1, word);
		}
	}

#ifdef Debug
	if (tmp != NULL)
		printf_s("\n Debug: La taille de la mémoire allouée est égale à %d octets \n", _msize(cloneStr));
#endif
	return tmp;
}

int main() {
	char mot[] = "BONJOUR";
	char* nouveaumot;
	nouveaumot = cloneStr(mot);

	printf("%s et %s", mot, nouveaumot);
}


