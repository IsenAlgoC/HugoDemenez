#include "Header.h"

Heure* cloneLog(Heure* Log, int nbLog) {
	Heure* newLog = NULL;
	if (Log == NULL) return NULL;

	newLog = (Heure*)malloc(sizeof(Heure) * nbLog);

	//On verifie que l'allocation n'est pas null
	if (newLog != NULL) {
		for (int i = 0; i < nbLog; i++) {
			*(newLog + i) = *(Log + i); //Recopie le contenu de Log dans newLog
		}
	}

	return (newLog);
}

void incrementMinute(Heure* now){
	now->heure = (now->minute + 1) / 60 + now->heure;
	now->minute = (now->minute + 1) % 60;
}
void affichageLog(Heure* Log, int nbLog) {
	if (Log != NULL) {
		for (int i = 0; i < nbLog; i++) {
			printf_s("\n%02d;%02d", (Log + i)->heure, (Log + i)->minute);
		}
	}
}


