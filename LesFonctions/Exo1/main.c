#include "Header.h"


int main()
{
	GrandEntier Nb1, Nb2, Nb3;
	int i;
	bool Fin = false;
	int Code; // valeur de retour de la fonction EntreeClavier
	while (!Fin)
	{
		if ((Code = EntreeClavier(Nb1)) < 0) Fin = true;
		if (!Fin && (Code = EntreeClavier(Nb2) < 0)) Fin = true;
		if (!Fin)
		{
			printf("\n ");
			Affiche(Nb1);
			printf("\n+");
			Affiche(Nb2);
			printf("\n ");
			for (i = 0; i < NbChiffresMax; i++)
			{
				if ((NbChiffresMax - i) % 3 == 0) printf("-");
				printf("-");
			}
			printf("\n=");
			Addition(Nb1, Nb2, Nb3);
			Affiche(Nb3);
			printf("\n");
		}
		else
		{
			printf("\n Bye !\n");
		}
	}
	return (EXIT_SUCCESS);
}