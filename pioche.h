#ifndef PIOCHE_H
#define PIOCHE_H


enum{CARTEJOUEUR=12, // Nombre de chevalets contenu par un joueurs au début de la partie
    CARTEPIOCHE=64, // Nombre de chevalets contenu par la pioche au début de la partie
    CARTETOTAL=88, // Nombre de chevalets dans le jeu au total
    NBJOUEURS=2}; // Nombre de joueurs qui jouent

/* *
* Représente une pioche (i.e les chevalets qui la compose ainsi que leur nombre).
*/
typedef struct{
    char chevalet[CARTETOTAL];
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
 * @brief Vérifie si la pioche est vide.
 *
 * @param[in] pioche Adresse de la Pioche à vérifier.
 * @return Retourne 1 si la pioche est vide, 0 sinon.
 */
int estVide(const Pioche* pioche);


/**
 * @brief Permet de piocher un chevalet de la pioche et décrémenté le taille de la pioche.
 * @param[in] pioche Adresse de la Pioche dont on va prendre le chevalet.
 * @return Retourne le chevalet pioché ou 0 si la pioche est vide.
 */
char piocher(Pioche* pioche);

/**
 * @brief Permet d'initialiser une pioche (i.e la remplis de chevalet et la mélange).
 * @param[in] p Adresse de la Pioche à initialiser.
 * @sa Fonction remplirChevalet et melangerPioche.
 */
void initPioche(Pioche* p);






#endif //PIOCHE_H
