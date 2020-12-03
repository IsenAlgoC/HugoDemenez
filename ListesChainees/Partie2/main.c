#include "listes.h"
#include "pile.h"


int main() {
	SYSTEMTIME st;			// r�cup�ration de la date syst�me
	GetSystemTime(&st);
	int time_ms = st.wMilliseconds;  // recup�ration des milliseconde de l'heure courante, 
									// cette valeur est plus volatile que les secondes

	// initialisation du g�n�rateur de nombres al�atoires
	srand(time_ms);

	// premier appel � rand afin de ne pas utiliser la 1ere valeur qui n'est pas tr�s al�atoire ..
	// est-ce un bug du SDK ?
	int u = rand();

	//On va cr�er une nouvelle pile
	SLLStack* stack;
	SLLNewStack(&stack);

	return EXIT_SUCCESS;
}