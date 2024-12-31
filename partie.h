//
// Created by selyan on 26/12/2024.
//

#ifndef PARTIE_H
#define PARTIE_H

#include "Dictonnaire.h"
#include "pioche.h"
#include "joueur.h"
#include "rail.h"
#include <string.h>
#include <stdio.h>

enum {NBJOUEURS=2};// Nombre de joueurs qui jouent

typedef struct{
    Joueur joueur[NBJOUEURS];
    Rail rail;
    Pioche pioche;
    int joueurActuelle;
}Partie;

/**
 * @brief Initialise deux joueurs en completant leurs mains et en les affichant.
 * @param[in] p Adresse de la partie à laquelle joue les joueurs.
 * @param[in] v Adresse de la pioche affectée à la partie.
 */
void initJoueurs(Partie* p,Pioche* v);

/**
 * @brief Initialise une partie contenant 2 joueurs en distrubuant les 12 lettres a chacun,
 * mettant le reste des lettres dans la pioche et le plateau de jeu comme vide.
 * @param[in] p Adresse de la partie devant etre initialisee.
 */
void initialiserPartie(Partie* p);
void demanderMot(Partie* p,char mot[MAX_MOT]);
void joueurSuivant(Partie* p);





#endif //PARTIE_H
