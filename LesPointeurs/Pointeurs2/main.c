#include "Header.h"

#define LOGSIZE 100

main() {

	Heure Log[LOGSIZE];
	for (int i = 0; i < LOGSIZE; i++) {
		Log[i].heure = 0;
		Log[i].minute = 0;
	}

	Log[0].heure = 11;
	Log[0].minute = 30;
	Log[1].heure = 13;
	Log[1].minute = 12;
	Log[2].heure = 15;
	Log[2].minute = 38;

	Heure* Log2 = NULL;
	Log2 = cloneLog(Log, 10); //Reproduit les 10 premières valeurs de Log dans Log2 

	affichageLog(Log2, 4);

	for (int i = 0; i < 4; i++) {
		incrementMinute(Log2 + i);
	}

	affichageLog(Log2, 4);

	return(EXIT_SUCCESS);



}