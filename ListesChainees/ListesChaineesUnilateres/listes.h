#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

typedef struct SingleLinkedListElem {
	int data;
	struct SingleLinkedListElem* next;
} SingleLinkedListElem;

typedef struct LinkedList {
	SingleLinkedListElem* head;
	int size;
	SingleLinkedListElem* tail;
} LinkedList;

// Crée une liste chaînée unilatère vide et renvoie un pointeur sur celle-ci
LinkedList* NewLinkedList();

// Crée un nouveau maillon qui contient une nouvelle personne et renvoie un pointeur sur ce maillon
SingleLinkedListElem* NewLinkedListElement(int value);

// Renvoie un pointeur sur le maillon qui se trouve en ième position à partir de 1
SingleLinkedListElem* GetElementAt(LinkedList* liste, int position);

//Insert un element à la position souhaité dans la liste
int InsertElementAt(LinkedList* liste, int position, int value);

// Suppression et destruction d'un élément de liste chainée
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* elem);

//Insertion d'un element au début de la liste
int insertElemAtLinkedListHead(LinkedList* Liste, SingleLinkedListElem* elem);

//Affiche les elements de la liste
int DisplayList(LinkedList* Liste);

//Crée une liste chainée unilatère contenant un certain nombre de valeurs entières aléatoires
int InitRandLinkedList(LinkedList* List, int ListSize);

//On insert un element à la fin de la liste
int insertElemAtLinkedListTail(LinkedList* Liste, SingleLinkedListElem* elem);