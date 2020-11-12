#include"Header.h"

char* cloneStr(char* word) {
	char* tmp = NULL;
	int len = 0;
	if (word != NULL) {
		len = strlen(word);
		tmp = (char*)malloc(len + 1);

		if (tmp != NULL) {
			strcpy(tmp, word);
		}
	}
	return tmp;
}

int main() {
	char mot[] = "BONJOUR";
	char* nouveaumot;
	nouveaumot = cloneStr(mot);
}


