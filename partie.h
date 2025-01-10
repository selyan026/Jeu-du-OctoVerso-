

#ifndef PARTIE_H
#define PARTIE_H

#include "Dictonnaire.h"
#include "pioche.h"
#include "joueur.h"
#include "rail.h"
#include "stockage.h"
#include <string.h>
#include <stdio.h>

enum {NBJOUEURS=2,MAX_MOT=5};// Nombre de joueurs qui jouent
/* *
* Représente une partie (i.e ses joueurs, son recto, sa pioche, le joueurActuelle).
*/
typedef struct{
    Joueur joueur[NBJOUEURS];
    Rail rail;
    Pioche pioche;
    int joueurActuelle;
    Stockage stockage;
}Partie;

/**
 * @brief Initialise deux joueurs en completant leurs mains et en les affichant.
 * @param[in] p Adresse de la partie à laquelle joue les joueurs.
 * @param[in] v Adresse de la pioche affectée à la partie.
 */
void initJoueurs(Partie* p,Pioche* v);

/**
 * @brief Initialise une partie contenant 2 joueurs en distrubuant les 12 lettres à chacun,
 * mettant le reste des lettres dans la pioche et le plateau de jeu comme vide.
 * @param[in] p Adresse de la partie devant etre initialisee.
 */
void initialiserPartie(Partie* p);

/**
 * @brief Demande à un joueur de saisir un mot valide et le stocke dans un tableau.
 * @param p [in] Pointeur vers la structure de la partie en cours.
 * @param mot [out] Tableau de caractères où le mot saisi sera stocké.
 */
void demanderMot(Partie* p, char mot[MAX_MOT]);


/**
* @brief Permet de passer au joueur suivant.
* @param p [in, out] Pointeur vers la structure de la partie en cours
*/
void joueurSuivant(Partie* p);

/**
* @brief Détermine quel joueur commence à jouer en fonction de l'ordre alphabétique des mots proposés.
*
* Compare les deux mots proposés par les joueurs pour déterminer qui commence. Le joueur ayant proposé
* le mot qui apparaît en premier dans l'ordre alphabétique jouera en premier.
*
* @param[in,out] p Pointeur vers la structure Partie actuelle.
* @param[in] mot1 Mot proposé par le joueur 1.
* @param[in] mot2 Mot proposé par le joueur 2.
*
* @pre Les chaînes de caractères `mot1` et `mot2` doivent être valides et null-terminées.
*/
void savoirQuiJoue(Partie* p,const char* mot1,const char* mot2);

/**
 * @brief Gère un tour de jeu pour le joueur actuel, permettant l'insertion d'un mot sur le rail.
 *
 * @param[in, out] p Pointeur vers la structure de la partie en cours.
 *
 * @pre 'p' doit être une structure Partie initialisée avec des joueurs, une pioche et un rail.
 * @post Le rail est mis à jour, les mains des joueurs sont modifiées et triées.
 */
void tourDeJeu(Partie* p);

/**
 * @brief Supprime toutes les parenthèses dans une chaîne de caractères.
 *
 * @param[in] mot Chaîne d'entrée contenant éventuellement des parenthèses.
 * @param[out] motVide Chaîne de sortie où les parenthèses sont retirées.
 *
 * @pre 'mot' doit être une chaîne de caractères valide et null-terminée.
 * @post 'motVide' contient une version de `mot` sans parenthèses.
 */
void enleverParentheses(char* mot, char* motVide);

/**
 * @brief Extrait le contenu entre les parenthèses d'une chaîne de caractères.
 *
 * @param[in] mot Chaîne d'entrée contenant des parenthèses.
 * @param[out] motParanthese Chaîne de sortie contenant uniquement le texte
 * situé entre les parenthèses.
 *
 * @pre `mot` doit être une chaîne de caractères valide et null-terminée.
 */
void extraireEntreParentheses(const char* mot, char* motParanthese);

/**
 * @brief Supprime le contenu situé entre les parenthèses d'une chaîne de caractères.
 *
 * @param[in] mot Chaîne d'entrée contenant des parenthèses.
 * @param[out] motParanthese Chaîne de sortie où le contenu entre parenthèses est retiré.
 *
 * @pre `mot` doit être une chaîne de caractères valide et null-terminée.
 */
void enleverEntreParentheses(char* mot, char* motParanthese);
void testPartie();
#endif //PARTIE_H
