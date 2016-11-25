#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "new_fonctions.h"

#define N 6
#define M 7
#define L 20

//Fonction qui permet d'afficher le resultat de la partie
void affich_result_avance(t_piece grille[N][M], int win, int tour){
	system("clear");

	if(win == 0){
		printf("\n ---------------------------------------");
		printf("\n|	         MATCH NUL		|");
	
		afficher_matrice_avance(grille);
	}
	
	else if(win == 1){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur1 A GAGNE 	|");
		
		afficher_matrice_avance(grille);
	}

	else if(win == 2){
		printf("\n ---------------------------------------");
		printf("\n|	        joueur2 A GAGNE 	|");
		
		afficher_matrice_avance(grille);
	}	
}

//Programme permettant la construction du jeu Puissance 4 classique
void puissance_avance(){
	t_piece grille[N][M];
	int colonne, ligne, pions, nb_tours, num_joueur, tour, nb_joueurs, type, win, nb_blok1, nb_blok2;
	char joueur1[L],joueur2[L],joueur3[L],joueur4[L];

/****************************** INITIALISATION ****************************************/

	//Initialisation de la matrice et effaçage de l'écran pour afficher la grille vierge
	init_matrice_avance(grille);
	system("clear");
	printf("\n ---------------------------------------");
	printf("\n|	       TOUR NUMERO 1		|");
	afficher_matrice_avance(grille);

	win = 0;
	pions = 1;
	tour = 1;
	nb_blok1 = 2;
	nb_blok2 = 2;
	
	while(!grille_pleine(grille)){

/****************************** JOUEUR 1 JOUE *****************************************/

		num_joueur = 1;

		//Demande où il veut jouer et avec quel type de piece
		do{			
			printf("joueur1: Colonne: ");
			scanf("%i", &colonne);

			do{
				printf("Type: - Creuse (1) ");
				printf("\n      - Pleine (2) ");
				printf("\n      - Bloquante (3) ");
				printf("\n\n>> Choix : ");
				scanf("%i", &type);
				
				//Verification du nombre de piece bloquante
				if(type == 3 && nb_blok1 == 0)
						printf("\nJoueur 1 n'a plus de piece bloquante.\n");
				
			}while(type < 1 || type > 3 || (type == 3 && nb_blok1 == 0));
			
			//Verification du nombre de piece bloquante et decrementation si on en a joue une
			if(type == 3 && nb_blok1 > 0){
				nb_blok1--;
				printf("\nJoueur 1: Reste %i piece bloquante a joue.",nb_blok1);
			}
			
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
			else{
				//Placement du pion sur la grille si et seulement si la colonne le permet
				ligne = choix_ligne_avance(grille, colonne);
				if(ligne < 0)
					printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				else
					placer_pions_avance(grille, colonne, ligne, num_joueur, type);
			}
		}while(colonne < 1 || colonne > 7 || ligne < 0);
		
		//Affichage du numéro du tour
		system("clear");
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO %i		|",pions);

		//Mise à jour de la grille
		afficher_matrice_avance(grille);

		//Test pour savoir si le joueur à gagné
		win = gagne_avance(grille);
		if(win == 1)break;

/****************************** JOUEUR 2 JOUE *****************************************/

		num_joueur = 2;

		//Demande où il veut jouer et avec quel type de piece
		do{			
		printf("joueur2: Colonne: ");
		scanf("%i", &colonne);

			do{
				printf("Type: - Creuse (1) ");
				printf("\n      - Pleine (2) ");
				printf("\n      - Bloquante (3) ");
				printf("\n\n>> Choix : ");
				scanf("%i", &type);
				
				//Verification du nombre de piece bloquante
				if(type == 3 && nb_blok2 == 0)
						printf("\nJoueur 2 n'a plus de piece bloquante.\n");
				
			}while(type < 1 || type > 3 || (type == 3 && nb_blok2 == 0));
			
			//Verification du nombre de piece bloquante et decrementation si on en a joue une
			if(type == 3 && nb_blok2 > 0){
				nb_blok2--;
				printf("\nJoueur 2: Reste %i piece bloquante a joue.",nb_blok2);
			}
			
			if(colonne < 1 || colonne > 7)
				printf("Erreur: entrez une colonne entre 1 et 7 compris: ");
			
			else{
				//Placement du pion sur la grille si et seulement si la colonne le permet
				ligne = choix_ligne_avance(grille, colonne);
				if(ligne < 0)
					printf("Erreur: colonne pleine veuillez en choisir une autre: ");
				else
					placer_pions_avance(grille, colonne, ligne, num_joueur, type);
			}
		}while(colonne < 1 || colonne > 7 || ligne < 0);
		
		//Affichage du numéro du tour
		system("clear");
		pions ++;
		printf("\n ---------------------------------------");
		printf("\n|	       TOUR NUMERO %i		|",pions);

		//Mise à jour de la grille
		afficher_matrice_avance(grille);

		//Test pour savoir si le joueur à gagné
		win = gagne_avance(grille);
		if(win == 2)break;

		tour++;
	}

/******************** Affichage du résultat de la partie ******************************/

	affich_result_avance(grille, win, tour);
}
