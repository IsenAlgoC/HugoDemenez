#include<stdio.h>
#include<stdlib.h>
#include "tp4.h"

int main() {

	//Declaration des variables et des constantes
	HEURE HeureDebut = {12,30};
	HEURE HeureFin ;
	HEURE Duree = {00,45} ;

	//Calcul du nombre de minute
	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;

	//Test si les minutes sont converties en heures 
	if ((HeureDebut.minute + Duree.minute) > 60) {

		//Calcul du nombre d'heure dans l'addition des minutes
		HeureFin.heure = (HeureDebut.minute + Duree.minute) / 60;
	}

	//Calcul du nombre d'heure 
	HeureFin.heure = HeureFin.heure + (HeureDebut.heure + Duree.heure) % 60;

	//Affichage de l'heure de fin 
	printf("L'heure de fin est %d:%d", HeureFin.heure, HeureFin.minute);
}

