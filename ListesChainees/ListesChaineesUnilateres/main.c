#include "listes.h"



int main() {
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