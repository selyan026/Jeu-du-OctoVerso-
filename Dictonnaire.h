#ifndef DICTONNAIRE_H
#define DICTONNAIRE_H

/**
 * @brief Permet d'ouvrir le dictionnaire et de vérifier si un mot est contenu dans le dictionnaire
 *
 * @param mot [in] Le mot à rechercher dans le fichier (chaîne de caractères).
 *            Ce paramètre est une entrée et ne sera pas modifié.
 *
 * @return 1 si le mot est trouvé dans le fichier.
 *         0 si le mot n'est pas trouvé ou si une erreur survient lors de l'ouverture du fichier.
 */
int estDansDictionnaire(const char *mot);














#endif
