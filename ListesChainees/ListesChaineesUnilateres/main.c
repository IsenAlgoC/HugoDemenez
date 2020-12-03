#include "listes.h"



int main() {
	SYSTEMTIME st;			// récupération de la date système
	GetSystemTime(&st);
	int time_ms = st.wMilliseconds;  // recupération des milliseconde de l'heure courante, 
									// cette valeur est plus volatile que les secondes

	// initialisation du générateur de nombres aléatoires
	srand(time_ms);

	// premier appel à rand afin de ne pas utiliser la 1ere valeur qui n'est pas très aléatoire ..
	// est-ce un bug du SDK ?
	int u = rand();

	//On crée une nouvelle liste vide appelée MaListe
	LinkedList *MaListe = NewLinkedList();
	//On crée un nouvel element appelé MonPremierElement avec la valeur 5
	SingleLinkedListElem* MonPremierElement = NewLinkedListElement(5);
	//On ajoute MonPremierElement à MaListe
	insertElemAtLinkedListHead(MaListe, MonPremierElement);
	
	//On ajoute 15 elements avec des valeurs aléatoires comprise entre 0 et 1000
	InitRandLinkedList(MaListe, 15);
	//On affiche les elements de la liste
	DisplayList(MaListe);

	return EXIT_SUCCESS;
}