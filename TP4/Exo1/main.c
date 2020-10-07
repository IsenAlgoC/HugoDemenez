#include<stdio.h>
#include<stdlib.h>
#include "tp4.h"

int main() {
	HEURE HeureDebut = {12,30};
	HEURE HeureFin ;
	HEURE Duree = {00,45} ;

	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
	if ((HeureDebut.minute + Duree.minute) > 60) {
		HeureFin.heure = (HeureDebut.minute + Duree.minute) / 60;
	}
	HeureFin.heure = HeureFin.heure + (HeureDebut.heure + Duree.heure) % 60;

	printf("L'heure de fin est %d:%d", HeureFin.heure, HeureFin.minute);
}
