#include "pile.h"

void SLLNewStack(SLLStack** stack) {
	*stack = (SLLStack*)malloc(sizeof(SLLStack));
}

//Cette fonction renvoie 1 si la pile est pleine
int SLLisStackFull(SLLStack* stack) {
	//On compare le nombre d'element avec le nombre d'element max que la pile peut acceuilir
	if (stack->stackNbElemts < stack->stackMaxSize) {
		return 1;
	}
	//Sinon on renvoie 0
	return 0;
}

//Cette fonction renvoie 1 si la pile est vide
int SLLisStackEmpty(SLLStack* stack) {
	//On regarde si le nombre d'element de la pile est 0
	if (stack->stackNbElemts == 0) {
		return 1;
	}
	//Si ce n'est pas le cas on renvoie 0
	return 0;

}

//On ajoute une variable value en haut de la pile
int SLLpush(SLLStack* stack, int value) {
	//On verifie que la pile existe bien
	if (stack != NULL) {
		//Si la pile existe : on ajoute la value à la fin
		insertElemAtLinkedListTail(stack->list, value);
		//Si ça fonctionne on renvoie 1
		return 1;
	}
	//Sinon on renvoie 0
	return 0;
}


//On retire un element de la pile puis on restitue la valeur dans la variable value
int SLLpull(SLLStack* stack, int* value) {
	//On verifie que la pile existe
	if (stack != NULL) {
		//Si la pile existe alors on met la valeur de la queue dans value
		*value = stack->list->tail;
		//On libère la queue de la liste
		DeleteLinkedListElem(stack->list, stack->list->tail);
		//Si tout cela a reussi alors on retourne 1
		return 1;
	}
	//Sinon on retourne 0
	return 0;
}

//On va retourner la valeur du dessus de la pile
int SLLpeek(SLLStack* stack, int* value) {
	if (stack != NULL) {
		*value= stack->list->tail->data;
		return 1;
	}
	return 0;
}