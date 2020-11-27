#include "listes.h"


// cr�e une nouvelle liste chain�e unilataire vide et renvoie un pointeur sur cette liste
LinkedList* NewLinkedList() {
	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
	return tmp;
}
// cr�e un nouveau maillon qui contient la personne pass�e en param�tre
SingleLinkedListElem* NewLinkedListElement(int value) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = NULL;
	}
	return(tmp);
}
// renvoie un pointeur sur l'�l�ment en i�me position dans la liste
SingleLinkedListElem* GetElementAt(LinkedList* Liste, int position) {
	int CurrentIndex = 0;
	SingleLinkedListElem* Element;
	if ((Liste == NULL) || (position < 0) || (position >= Liste->size)) return(NULL);
	if (position == 0) return(Liste->head);
	if (position == Liste->size - 1) return(Liste->tail);
	Element = Liste->head;
	while (CurrentIndex != position && Element != NULL) {
		Element = Element->next;
		CurrentIndex++;
	}
	return(Element);
}

// Ajoute une nouvelle personne dans la liste cha�n�e en i�me position
// Cette fonction fait appel � la fonction NewLinkedListElement(Enregistrement pers) pour cr�er un maillon
//


int InsertElementAt(LinkedList* Liste, int position, int value) {
	SingleLinkedListElem* CurrentElement, * NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'�l�ment qui se trouve d�j� en position i
	CurrentElement = GetElementAt(Liste, position);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on ins�re un nouvel �l�ment
		NewElement = NewLinkedListElement(value);
		// son suivant est alors l'�l�ment courant
		NewElement->next = CurrentElement;

		if (position == 0) {
			// si l'insertion est en t�te
			// le nouvel �l�ment devient la t�te
			Liste->head = NewElement;
		}
		else {
			// sinon il faut r�tablir le chainage depuis l'�l�ment pr�c�dent
			CurrentElement = GetElementAt(Liste, position - 1);
			// le successeur du pr�c�dent devient le nouvel �l�ment
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { // insertion en t�te de l'unique �l�ment
			NewElement = NewLinkedListElement(value);
			if (NewElement != NULL) {
				//La t�te devient le nouvel element
				Liste->head = NewElement;
				//La t�te devient la queue puisqu'il n'y a qu'un seul element
				NewElement->next = NULL;
			}
			else {
				return(0);
			}
		}
		if (Liste->size <= position) { // insertion en queue
			NewElement = NewLinkedListElement(value);
			if (NewElement != NULL) {
				Liste->tail->next = NewElement;
				Liste->tail = NewElement;
				NewElement->next = NULL;
			}
			else {
				return(0);
			}
		}
		Liste->size++;
	}
	return(0);
}
//
// Suppression d'un �l�ment de la liste cha�n�e
//
// FONCTION A COMPLETER
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* elem) {
	if (list == NULL) return(0); // La liste n'existe pas
	if ((list->head == NULL) || (list->tail == NULL)) return(0); // liste vide ou anomalie
	if ((list->head == list->tail) && (list->size != 1)) return(0); // anomalie
	if ((list->size == 0) || (elem == NULL)) return(0); // pas d'�l�ment dans la liste ou item invalide


	// initialisation d'un pointeur sur l'�l�ment courant
	SingleLinkedListElem* tmp = list->head;
	// previous d�signe l'�l�ment qui pr�c�de l'�l�ment courant
	SingleLinkedListElem* previous = NULL;
	// l'�l�ment est en t�te et en queue, il y a donc 1 seul �l�ment dans la liste
	if ((elem == list->head) && (elem == list->tail)) {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}
	// S'il est en t�te, on supprime la t�te
	if (elem == list->head) {
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// Recherche du maillon dans le reste de la liste cha�n�e
	while ((tmp != NULL) && (tmp != elem)) {
		previous = tmp;
		tmp = tmp->next;
	}
	// s'il est en queue, on supprime la queue
	if ((previous != NULL) && (tmp == elem) && (tmp->next == NULL)) {
		list->tail = previous;
		previous->next = NULL;
		list->size--;
		free(elem);
		return(1);
	}
	// S'il est au milieu, on supprime l'�l�ment
	if ((previous != NULL) && (tmp == elem) && (tmp->next != NULL)) {
		previous->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}



	return(0);  // pas trouv�
}

int insertElemAtLinkedListHead(LinkedList* Liste, SingleLinkedListElem* elem) {
	if (Liste->size == 0 && Liste->head==NULL) { // insertion en t�te de l'unique �l�ment
		if (elem != NULL) {
			//La t�te devient le nouvel element
			Liste->head = elem;
			//La t�te devient la queue puisqu'il n'y a qu'un seul element
			Liste->tail = elem;
			//La queue pointe vers NULL
			elem->next = NULL;
			//On augmente la taille de la liste
			Liste->size++;
		}
		else {
			return(0);
		}
	}
	else {
		if (elem != NULL) {
			//la t�te devient le next de l'element
			elem->next = Liste->head;
			//La t�te devient le nouvel element
			Liste->head = elem;
			//On augmente la taille de la liste
			Liste->size++;
		}
		else {
			return (0);
		}
	}
}
int insertElemAtLinkedListTail(LinkedList* Liste, SingleLinkedListElem* elem) {
	if (Liste->size == 0 && Liste->head == NULL) { // insertion en t�te de l'unique �l�ment
		if (elem != NULL) {
			//La queue devient le nouvel element tete
			Liste->head = elem;
			//La t�te devient la queue puisqu'il n'y a qu'un seul element
			elem->next = NULL;
			//On augmente la taille de la liste
			Liste->size++;
		}
		else {
			return(0);
		}
	}
	else {
		if (elem != NULL) {
			//La queue pointe sur le nouvel element
			Liste->tail->next = elem;
			//La queue devient le nouvel element
			Liste->tail = elem;
			//Le nouvel element pointe vers NULL
			elem->next = NULL;
			//La taille de la liste augmente
			Liste->size++;
		}
		else {
			return (0);
		}
	}
}


//Affiche les elements de la liste
int DisplayList(LinkedList* Liste){
	if (Liste->head == NULL || Liste->size==0) {
		return(0);
	}
	else {
		SingleLinkedListElem *elem = Liste->head;
		if (elem->next == NULL) {
			printf("%d", elem->data);
		}
		else {
			while (elem->next != NULL) {
				printf("%d", elem->data);
				elem = elem->next;
			}
		}
		return 0;
	}
}

int randint(int valuemax) {
	time_t t;
	srand((unsigned)time(&t));
	int r = rand() % valuemax; 
	return r;
}

//Cr�e une liste chain�e unilat�re contenant un certain nombre de valeurs enti�res al�atoires
int InitRandLinkedList(LinkedList* List, int ListSize) {
	if (List == NULL) {
		return 0;
	}
	else {
		for (int i = 0; i < ListSize; i++) {
		SingleLinkedListElem *randomelement =	NewLinkedListElement(randint(1000));
		insertElemAtLinkedListTail(List, randomelement);
		}
		return 1;
	}
	
}
