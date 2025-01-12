#include "Dictonnaire.h"
#include <stdio.h>
#include <string.h>

int estDansDictionnaire(const char *mot) {
    FILE *fichier = fopen("ods4.txt", "r");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 0;
    }

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = '\0';

        if (strcmp(ligne, mot) == 0) {
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);
    return 0;
}