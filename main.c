#include "partie.h"

int main(){
    char mot1[MAX_MOT];
    char mot2[MAX_MOT];
    Partie p;
    initialiserStockage(&p.stockage,1);
    initialiserPartie(&p);
    testPartie();
    demanderMot(&p,mot1);
    ajouterMotStockage(&p.stockage,mot1);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot1);
    joueurSuivant(&p);
    demanderMot(&p,mot2);
    printf("\n");
    ajouterMotStockage(&p.stockage,mot2);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot2);
    initRail(&p.rail,mot1,mot2);
    afficherJoueur(&p.joueur[J1]);
    afficherJoueur(&p.joueur[J2]);
    afficherRail(&p.rail);
    printf("\n");
    savoirQuiJoue(&p,mot1,mot2);
    do {
        tourDeJeu(&p);
    }while (p.joueur[J1].tailleMain!=0 && p.joueur[J2].tailleMain!=0);
    return 0;
}