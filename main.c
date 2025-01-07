#include "partie.h"

int main(){
    char mot1[MAX_MOT];
    char mot2[MAX_MOT];
    Partie p;
    initialiserPartie(&p);
    demanderMot(&p,mot1);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot1);
    joueurSuivant(&p);
    demanderMot(&p,mot2);
    supprimerLettre(&p.joueur[p.joueurActuelle],mot2);
    initRail(&p.rail,mot1,mot2);
    afficherRail(&p.rail);
    joueurSuivant(&p);
    afficherJoueur(&p.joueur[p.joueurActuelle]);
    joueurSuivant(&p);
    afficherJoueur(&p.joueur[p.joueurActuelle]);
    joueurSuivant(&p);

    return 0;
}