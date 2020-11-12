#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct heure {
	int heure;
	int minute;
} Heure;
void incrementMinute(Heure* now);
Heure* cloneLog(Heure* Log, int nbLog);
void affichageLog(Heure* Log, int nbLog);