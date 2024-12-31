#ifndef PIOCHE_H
#define PIOCHE_H

#include "vecteur.h"

enum {
    LETTREJOUEUR=12, // Nombre de chevalets contenu par un joueurs au début de la partie
    LETTRETOTAL=88// Nombre de chevalets dans le jeu au total
    };

/* *
* Représente une pioche (i.e les chevalets qui la compose ainsi que leur nombre).
*/
typedef struct{
    Vecteur chevalet;
    int nbPioche;
}Pioche;

/**
 * @brief Remplie une pioche de chevalet
 * @param[in] p adresse de la Pioche qui doit etre remplie.
 */
void remplirChevalet(Pioche* p);

/**
 * @brief Melange une pioche remplie de chevalet.
 * @param[out] p adresse de la Pioche qui doit etre melangée.
 */
void melangerPioche(Pioche* p);

/**
 * @brief Permet de piocher une lettre de la pioche.
 *
 * Réduit la taille de la pioche de 1 après l'extraction. Si la pioche est vide,
 * retourne un caractère nul (`'\0'`).
 *
 * @param[in] pioche Adresse de la Pioche dont on va extraire une lettre.
 * @return Retourne la lettre piochée ou '\0' si la pioche est vide.
 */
char piocher(Pioche* pioche);

/**
 * @brief Permet d'initialiser une pioche (i.e la remplis de chevalet et la mélange).
 * @param[in] p Adresse de la Pioche à initialiser.
 * @sa Fonction remplirChevalet et melangerPioche.
 */
void initPioche(Pioche* p);






#endif //PIOCHE_H
