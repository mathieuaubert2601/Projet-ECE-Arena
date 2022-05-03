#include "header.h"

void afficher_commande (BITMAP* buffer, t_joueur* joueur)
{
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    BITMAP* fondbas = load_bitmap("fondbas.bmp",NULL);
    BITMAP* fondcote = load_bitmap("fondcote.bmp",NULL);

    BITMAP* PA = load_bitmap("PA.bmp",NULL);
    BITMAP* PM = load_bitmap("PM.bmp",NULL);
    BITMAP* PV = load_bitmap("PV.bmp",NULL);

    BITMAP* JoueurS = load_bitmap("JoueurSuivant.bmp",NULL);
    BITMAP* JoueurSInv = load_bitmap("JoueurSuivantInv.bmp",NULL);

    int casex, casey, casex2, casey2;
    casex = -30;
    casey = -32;
    casex2 = 30;
    casey2 = 32;

    blit(fondbas,buffer,0,casey*18,0,0,buffer->w,buffer->h);
    blit(fondcote,buffer,casex*36,0,0,0,buffer->w,buffer->h);

    commande_pokemon(buffer,joueur);

    //AffichageBouton(cageE,cageEInv,buffer,0,0,casex2*9,casey2*19,75,54);

    masked_blit(PA,buffer,casex*5,-600,0,0,buffer->w,buffer->h);
    masked_blit(PM,buffer,casex*5,-660,0,0,buffer->w,buffer->h);
    masked_blit(PV,buffer,casex*2,-620,0,0,buffer->w,buffer->h);

    AffichageBouton(JoueurS,JoueurSInv,buffer,0,0,casex2*31,620,130,115);
}

void commande_pokemon (BITMAP* buffer,t_joueur* joueur)
{
    BITMAP* pikachu = load_bitmap("pikachu1.bmp",NULL);
    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);
    BITMAP* fatF = load_bitmap("pikachu/FatalFoudre.bmp",NULL);
    BITMAP* fatFInv = load_bitmap("pikachu/FatalFoudreInv.bmp",NULL);
    BITMAP* boulE = load_bitmap("pikachu/BouleElek.bmp",NULL);
    BITMAP* boulEInv = load_bitmap("pikachu/BouleElekInv.bmp",NULL);
    BITMAP* coupJ = load_bitmap("pikachu/CoupJus.bmp",NULL);
    BITMAP* coupJInv = load_bitmap("pikachu/CoupJusInv.bmp",NULL);
    BITMAP* vitEx = load_bitmap("pikachu/VitesseExtreme.bmp",NULL);
    BITMAP* vitExInv = load_bitmap("pikachu/VitesseExtremeInv.bmp",NULL);

    int casex, casey;
    casex = 30;
    casey = 32;

    AffichageBouton(joueur->classe.sort1.bouton,joueur->classe.sort1.boutonInv,buffer,0,0,casex*10,casey*19,75,54);
    AffichageBouton(joueur->classe.sort2.bouton,joueur->classe.sort2.boutonInv,buffer,0,0,casex*14,casey*19,75,54);
    AffichageBouton(joueur->classe.sort3.bouton,joueur->classe.sort3.boutonInv,buffer,0,0,casex*18,casey*19,75,54);
    AffichageBouton(joueur->classe.sort4.bouton,joueur->classe.sort4.boutonInv,buffer,0,0,casex*22,casey*19,75,54);
    AffichageBouton(joueur->classe.sort5.bouton,joueur->classe.sort5.boutonInv,buffer,0,0,casex*26,casey*19,75,54);

    AffichageBouton(joueur->classe.profil,joueur->classe.profilvert,buffer,0,0,casex*32,casey*joueur->numero,50,50);
}

