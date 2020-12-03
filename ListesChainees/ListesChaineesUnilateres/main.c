#include "listes.h"



int main() {
	SYSTEMTIME st;			// r�cup�ration de la date syst�me
	GetSystemTime(&st);
	int time_ms = st.wMilliseconds;  // recup�ration des milliseconde de l'heure courante, 
									// cette valeur est plus volatile que les secondes

	// initialisation du g�n�rateur de nombres al�atoires
	srand(time_ms);

	// premier appel � rand afin de ne pas utiliser la 1ere valeur qui n'est pas tr�s al�atoire ..
	// est-ce un bug du SDK ?
	int u = rand();

	//On cr�e une nouvelle liste vide appel�e MaListe
	LinkedList *MaListe = NewLinkedList();
	//On cr�e un nouvel element appel� MonPremierElement avec la valeur 5
	SingleLinkedListElem* MonPremierElement = NewLinkedListElement(5);
	//On ajoute MonPremierElement � MaListe
	insertElemAtLinkedListHead(MaListe, MonPremierElement);
	
	//On ajoute 15 elements avec des valeurs al�atoires comprise entre 0 et 1000
	InitRandLinkedList(MaListe, 15);
	//On affiche les elements de la liste
	DisplayList(MaListe);

	return EXIT_SUCCESS;
}