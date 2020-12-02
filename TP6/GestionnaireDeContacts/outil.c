#include <stdio.h>   /* pour les entr�es-sorties */
#include <string.h>  /* pour les manipulations de cha�nes de caract�res */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"


#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compl�ter votre nom ici                                                */
/*   Nom :Demenez                         Pr�nom :Hugo                    */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le r�pertoire stock� en m�moire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compl�ter code ici pour tableau
	//On verifie si le repertoire n'est pas rempli au maximum
	if (rep->nb_elts < MAX_ENREG)
	{
		//Si il y a de la place alors on met le nouvel enregistrement � la suite des autres
		rep->tab[rep->nb_elts]=enr;
		//On augmente donc le nombre d'element compris dans le repertoire
		rep->nb_elts++;
	}
	else {
		//On retourne une erreur dans le cas o� le registre est plein
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST

	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}
		else {
			return(ERROR);
		}
	}
	else {
		//On doit regarder o� il faut ajouter l'element par ordre alphabetique
		//On cr�� un element CurrentElemListe qui pointe sur l'element actuel du repertoire
		SingleLinkedListElem *CurrentElemListe = rep->liste->head;
		//On se place sur la tete en premier lieu
		int position = 0;
		//On regarde si notre enregistrement est plus grand que la tete
		if (est_sup(enr,CurrentElemListe->pers)) {
			//Tant qu'on est plus grand, on change l'element actuel � comparer et on augmente la position
			while (est_sup(enr, CurrentElemListe->pers)) {
				if (CurrentElemListe->next != NULL) {
					CurrentElemListe = CurrentElemListe->next;
					position++;
				}
				else {
					//On est arriv� � la fin, il faut donc placer l'enregistrement en queue de repertoire
					InsertElementAt(rep->liste, rep->nb_elts, enr);
					rep->nb_elts += 1;
					modif = true;
					rep->est_trie = true;
					return(OK);
				}
			}
			//Si on est sorti de la boucle c'est que l'on est inf�rieur � l'element regard�, on peut donc prendre sa place
			if (InsertElementAt(rep->liste, position, enr) != 0) {
				rep->nb_elts += 1;
				modif = true;
				rep->est_trie = true;
				return(OK);
			}
			else {
				return(ERROR);
			}
		}
		//Enr doit �tre plac� en tete de repertoire
		else {
			if (InsertElementAt(rep->liste, 0, enr) != 0) {
				rep->nb_elts += 1;
				modif = true;
				rep->est_trie = true;
				return(OK);
			}
			else {
				return(ERROR);
			}
		}

	}


#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du r�pertoire l'enregistrement dont l'indice est donn� en */
  /*   param�tre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compl�ter code ici pour tableau
	if (rep->nb_elts >= 1 || indice < rep->nb_elts || 0<indice )		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */
		//On d�cale tous les �lements en �crasant les element � l'indice
		for (int i = indice ; i < rep->nb_elts; i++) {
			rep->tab[i] = rep->tab[i + 1];
		}
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du r�pertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif � vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne � l'�cran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code � compl�ter ici
	printf_s("%s,%s                 %s\n", enr.nom, enr.prenom, enr.tel);

} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex |Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code � compl�ter ici
	// comme fonction affichage_enreg, mais avec pr�sentation align�es des infos
	printf_s("\n|%-30s|%-30s|%-30s", enr.nom, enr.prenom, enr.tel);
	
} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code � compl�ter ici
	//On teste si enr1 est sup�rieur � enr2
	if (_stricmp(enr1.nom, enr2.nom) > 0) {
		return (true);
	}
	

	return(false);

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	//On effectue un trie � bulle
	for (int i = 0; i < rep->nb_elts -1; i++)
	{
		for (int j = 0; j < rep->nb_elts - i - 1; j++)
		{
			if (est_sup(rep->tab[j], rep->tab[j + 1]))
			{
				Enregistrement tempo = rep->tab[j];
				rep->tab[j] = rep->tab[j + 1];
				rep->tab[j + 1] = tempo;
			}
		}
	}

	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien � faire !
	// la liste est toujours tri�e
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le r�pertoire d'un enregistrement correspondant au  */
  /*   nom � partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au crit�re ou*/
  /*   un entier n�gatif si la recherche est n�gative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire* rep, char nom[], int ind)
{
	int i = ind;            /* position (indice) de d�but de recherche dans tableau/liste rep */
	
	int ind_fin = rep->nb_elts - 1;            /* position (indice) de fin de tableau/liste rep */



	char tmp_nom[MAX_NOM];    /* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];    /* on place la chaine recherchee et la chaine lue dans le */

	
	//Copie de nom dans tmp_nom
	strcpy_s(tmp_nom, _countof(tmp_nom), nom);
	//Mise en majuscule de tous les caract�res 
	_strupr_s(tmp_nom,sizeof(tmp_nom));


	bool trouve = false;




#ifdef IMPL_TAB
	
	while (trouve == false && i <= ind_fin)
	{
		//Copie du nom du repertoire dans tmp_nom2
		strcpy_s(tmp_nom2, _countof(tmp_nom2), rep->tab[i].nom);
		//Mise en majuscule de tous les caract�res de tmp_nom2
		_strupr_s(tmp_nom2,sizeof(tmp_nom2));
		

		//On compare le nom recherch� avec le nom trouv�
		if (strcmp(tmp_nom, tmp_nom2) == 0) {
			trouve = true;
		}
		else
		{
			i++;
		}
	}

#else
#ifdef IMPL_LIST
	//On initialise l'element sur la tete de la liste
	SingleLinkedListElem* CurrentElemListe = rep->liste->head;
	//On va chercher l'element o� l'on se trouve
	for (int count = 0; count < i; count++) {
		CurrentElemListe = CurrentElemListe->next;
	}
	
	while (trouve == false && i <= ind_fin)
	{
		//Copie du nom du repertoire dans tmp_nom2
		strcpy_s(tmp_nom2, _countof(tmp_nom2), CurrentElemListe->pers.nom);
		//Mise en majuscule de tous les caract�res de tmp_nom2
		_strupr_s(tmp_nom2, sizeof(tmp_nom2));


		//On compare le nom recherch� avec le nom trouv�
		if (strcmp(tmp_nom, tmp_nom2) == 0) {
			trouve = true;
		}
		else
		{	
			CurrentElemListe = CurrentElemListe->next;
			i++;
		}
	}

#endif
#endif



	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non num�riques de la chaines        */
  /*********************************************************************/
void compact(char* s)
{
	// compl�ter code ici
	for (int i = 0, j; s[i] != '\0'; ++i) {
		// Si on n'a pas un chiffre on rentre dans la boucle
		while (isdigit(s[i])==false) {
			for (j = i; s[j] != '\0'; ++j) {

				// Si le j�me element n'est pas un vide
				// On donne la valeur du j�me +1 au j�me element
				s[j] = s[j + 1];
			}
			//On retire le j�me element
			s[j] = '\0';
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le r�pertoire dans le fichier dont le nom est pass� en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionn� ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire * rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	
	//Ouverture du fichier d'ecriture, cr�ation de ce dernier s'il n'existe pas
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");

	//Cr�ation de la cha�ne de caract�re buffer
	char buffer[sizeof(Enregistrement) + 1] = { ' ' };
	if (fic_rep != NULL) {
		//On cr�� une boucle for pour parcourir tout le r�pertoire et ainsi enregistrer tous les enregistrements dans buffer
		for (int i = 0; i < rep->nb_elts; i++) {
			//On ajoute le nom dans buffer
			sprintf_s(buffer, _countof(buffer), "%s;%s;%s;\n", rep->tab[i].nom, rep->tab[i].prenom, rep->tab[i].tel);
			fputs(buffer, fic_rep);
		}
		//fermeture du fichier
		fclose(fic_rep);
	}

	else {
		return (ERROR);
	}
	

	
	


#else
#ifdef IMPL_LIST
	//Ouverture du fichier d'ecriture, cr�ation de ce dernier s'il n'existe pas
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");

	//Cr�ation de la cha�ne de caract�re buffer
	char buffer[sizeof(Enregistrement) + 1] = { ' ' };
	if (fic_rep != NULL) {
		//On initialise une variable sur le premier element
		SingleLinkedListElem* CurrentElement = rep->liste->head;
		//On cr�� une boucle for pour parcourir tout le r�pertoire et ainsi enregistrer tous les enregistrements dans buffer
	
		for (int i = 0; i < rep->nb_elts; i++) {
			//On ajoute le nom dans buffer
			sprintf_s(buffer, _countof(buffer), "%s;%s;%s;\n",CurrentElement->pers.nom, CurrentElement->pers.prenom, CurrentElement->pers.tel);
			fputs(buffer, fic_rep);
			CurrentElement = CurrentElement->next;
		}
		//fermeture du fichier
		fclose(fic_rep);
	}

	else {
		return (ERROR);
	}
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le r�pertoire le contenu du fichier dont le nom est  */
  /*   pass� en argument                                                */
  /*   retourne OK si le chargement a fonctionn� et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */

	
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element � priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
				Enregistrement temporaire;
				if (lire_champ_suivant(buffer, &idx, temporaire.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, temporaire.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, temporaire.tel, MAX_TEL, SEPARATEUR) == OK)
							ajouter_un_contact_dans_rep(rep, temporaire);	/* element � priori correct, on le comptabilise */
							num_rec++;	/* element � priori correct, on le comptabilise */
					}
				}
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */