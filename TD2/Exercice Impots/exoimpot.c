#include <stdio.h>
#include <stdlib.h>

main() {
	// Calcul de l'impot en fonction du revenu net imposable
	// déclaration de variables
	int TrancheBasse = 10065;
	double TauxTrancheBasse = 0.11;
	int TrancheMoyenneBasse = 25660;
	double TauxTrancheMoyenneBasse = 0.30;
	int TrancheMoyenneHaute = 73370;
	double TauxTrancheMoyenneHaute = 0.41;
	int TrancheElevee = 157807;
	double TauxTrancheElevee = 0.45;
	int RevenuNetImposable = 0; 
	double impot = 0; // montant de l'impôt
	int revenuTmp;

	// saisie du revenu net imposable
	printf("\n Entrez votre revenu net imposable : ");
	scanf_s("%d", &RevenuNetImposable);

	revenuTmp = RevenuNetImposable;
	
	// montant dans la tranche Elevee

	if (revenuTmp>TrancheElevee) {
		impot = (revenuTmp - TrancheElevee) * TauxTrancheElevee;
		revenuTmp = TrancheElevee;
	}
	// montant dans la tranche D

	if (revenuTmp>TrancheMoyenneHaute) {
		impot = impot + (revenuTmp-TrancheMoyenneHaute)*TauxTrancheMoyenneHaute;
		revenuTmp = TrancheMoyenneHaute;
	}
	// montant dans la tranche moyenne basse

	if (revenuTmp>TrancheMoyenneBasse) {
		impot = impot + (revenuTmp-TrancheMoyenneBasse)*TauxTrancheMoyenneBasse;
		revenuTmp = TrancheMoyenneBasse;
	}
	// montant dans la tranche Basse

	if (revenuTmp > TrancheBasse) {
		impot = impot + (revenuTmp-TrancheBasse)*TauxTrancheBasse;
		revenuTmp = TrancheBasse;
	}
	// Affichage du montant de l'impôt

	printf("\nle montant de votre impot pour un revenu net imposable de %d s'eleve a %d euros.\n", RNI, (int)impot);	return (EXIT_SUCCESS);}