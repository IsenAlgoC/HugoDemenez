#include "listes.h"
#include "pile.h"


int main() {
	SYSTEMTIME st;			// récupération de la date système
	GetSystemTime(&st);
	int time_ms = st.wMilliseconds;  // recupération des milliseconde de l'heure courante, 
									// cette valeur est plus volatile que les secondes

	// initialisation du générateur de nombres aléatoires
	srand(time_ms);

	// premier appel à rand afin de ne pas utiliser la 1ere valeur qui n'est pas très aléatoire ..
	// est-ce un bug du SDK ?
	int u = rand();

	//On va créer une nouvelle pile
	SLLStack* stack;
	SLLNewStack(&stack);

	return EXIT_SUCCESS;
}