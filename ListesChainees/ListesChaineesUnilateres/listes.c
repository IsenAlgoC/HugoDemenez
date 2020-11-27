#include "listes.h"


// crée une nouvelle liste chainée unilataire vide et renvoie un pointeur sur cette liste
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
// crée un nouveau maillon qui contient la personne passée en paramètre
SingleLinkedListElem* NewLinkedListElement(int value) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = NULL;
	}
	return(tmp);
}
// renvoie un pointeur sur l'élément en ième position dans la liste
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

// Ajoute une nouvelle personne dans la liste chaînée en ième position
// Cette fonction fait appel à la fonction NewLinkedListElement(Enregistrement pers) pour créer un maillon
//


int InsertElementAt(LinkedList* Liste, int position, int value) {
	SingleLinkedListElem* CurrentElement, * NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'élément qui se trouve déjà en position i
	CurrentElement = GetElementAt(Liste, position);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on insère un nouvel élément
		NewElement = NewLinkedListElement(value);
		// son suivant est alors l'élément courant
		NewElement->next = CurrentElement;

		if (position == 0) {
			// si l'insertion est en tête
			// le nouvel élément devient la tête
			Liste->head = NewElement;
		}
		else {
			// sinon il faut rétablir le chainage depuis l'élément précédent
			CurrentElement = GetElementAt(Liste, position - 1);
			// le successeur du précédent devient le nouvel élément
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { // insertion en tête de l'unique élément
			NewElement = NewLinkedListElement(value);
			if (NewElement != NULL) {
				//La tête devient le nouvel element
				Liste->head = NewElement;
				//La tête devient la queue puisqu'il n'y a qu'un seul element
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
// Suppression d'un élément de la liste chaînée
//
// FONCTION A COMPLETER
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* elem) {
	if (list == NULL) return(0); // La liste n'existe pas
	if ((list->head == NULL) || (list->tail == NULL)) return(0); // liste vide ou anomalie
	if ((list->head == list->tail) && (list->size != 1)) return(0); // anomalie
	if ((list->size == 0) || (elem == NULL)) return(0); // pas d'élément dans la liste ou item invalide


	// initialisation d'un pointeur sur l'élément courant
	SingleLinkedListElem* tmp = list->head;
	// previous désigne l'élément qui précède l'élément courant
	SingleLinkedListElem* previous = NULL;
	// l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste
	if ((elem == list->head) && (elem == list->tail)) {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}
	// S'il est en tête, on supprime la tête
	if (elem == list->head) {
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// Recherche du maillon dans le reste de la liste chaînée
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
	// S'il est au milieu, on supprime l'élément
	if ((previous != NULL) && (tmp == elem) && (tmp->next != NULL)) {
		previous->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}



	return(0);  // pas trouvé
}

int insertElemAtLinkedListHead(LinkedList* Liste, SingleLinkedListElem* elem) {
	if (Liste->size == 0 && Liste->head==NULL) { // insertion en tête de l'unique élément
		if (elem != NULL) {
			//La tête devient le nouvel element
			Liste->head = elem;
			//La tête devient la queue puisqu'il n'y a qu'un seul element
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
			//la tête devient le next de l'element
			elem->next = Liste->head;
			//La tête devient le nouvel element
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
	if (Liste->size == 0 && Liste->head == NULL) { // insertion en tête de l'unique élément
		if (elem != NULL) {
			//La queue devient le nouvel element tete
			Liste->head = elem;
			//La tête devient la queue puisqu'il n'y a qu'un seul element
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

//Crée une liste chainée unilatère contenant un certain nombre de valeurs entières aléatoires
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
