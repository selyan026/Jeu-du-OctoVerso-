#ifndef JOUEUR_H
#define JOUEUR_H

#include "pioche.h"
#include "vecteur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum{J1=0,J2=1};

/* *
* Représente un joueur (i.e son identifiant, sa main, le nombre de chevalet qu'il lui reste).
*/
typedef struct{
    int idJoueur;
    Vecteur main;
    int tailleMain;
}Joueur;

/**
 * @brief Rempli la main d'un joueur.
 * @param[in] joueur Adresse du joueur dont le deck va être remplis.
 * @param[in] p Adresse de la pioche qui va être retirée les cartes.
 * @param[in] id L'id du joueur auquel on va remplir sa main.
 * @sa Fonction char pioche
 */
void remplirJoueur(Joueur* joueur,Pioche* p,int id);

/**
 * @brief Permet d'afficher un joueur avec sa main et son id  .
 * @param[in] joueur Adresse du joueur dont les informations vont être affichés .
 * @sa Stucture Joueur
 */
void afficherJoueur(const Joueur* joueur);

/**
 * @brief Permet de trier dans l'ordre alphabetique la main d'un joueur .
 * @param[in] j Adresse du joueur dont la main doit etre trié .
 * @sa Stucture Joueur
 */
void trierMain(Joueur* j);

int verifierMotDansMain(Vecteur main, const char* mot);

void supprimerLettre (Joueur* joueur,const char *mot);




#endif //JOUEUR_H
