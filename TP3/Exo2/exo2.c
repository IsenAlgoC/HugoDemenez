#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main() {
    //Declaration des variables
    unsigned long long valeur = 2868838400;
    unsigned bit = 0;
    unsigned masque = 1;

    //Affichage de la taille du codage
    printf("Ce nombre pèse %d octets : ", sizeof(valeur));

    for (int i = 0; i < 32; ++i)
    {
        bit = (valeur & masque)>>i;
        if (bit == 1) {
            printf("\nbit %d : ON", i+1);
        }
        else {
            printf("\nbit %d : OFF", i+1);
        }
        masque<<=1;


    }

    printf("\nBye !");
    return (EXIT_SUCCESS);
}