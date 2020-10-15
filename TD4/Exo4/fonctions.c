#include "Header.h"

int occur(char mot[], int tailleMax, char car) {
    int compteur = 0;
    for (int i = 0; i < tailleMax; i++) {
        if (mot[i] == car) {
            compteur++;
        }
    }
    return(compteur);
}
