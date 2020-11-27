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

// Cr�e une liste cha�n�e unilat�re vide et renvoie un pointeur sur celle-ci
LinkedList* NewLinkedList();

// Cr�e un nouveau maillon qui contient une nouvelle personne et renvoie un pointeur sur ce maillon
SingleLinkedListElem* NewLinkedListElement(int value);

// Renvoie un pointeur sur le maillon qui se trouve en i�me position � partir de 1
SingleLinkedListElem* GetElementAt(LinkedList* liste, int position);

//Insert un element � la position souhait� dans la liste
int InsertElementAt(LinkedList* liste, int position, int value);

// Suppression et destruction d'un �l�ment de liste chain�e
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* elem);

//Insertion d'un element au d�but de la liste
int insertElemAtLinkedListHead(LinkedList* Liste, SingleLinkedListElem* elem);

//Affiche les elements de la liste
int DisplayList(LinkedList* Liste);

//Cr�e une liste chain�e unilat�re contenant un certain nombre de valeurs enti�res al�atoires
int InitRandLinkedList(LinkedList* List, int ListSize);

//On insert un element � la fin de la liste
int insertElemAtLinkedListTail(LinkedList* Liste, SingleLinkedListElem* elem);