#include "header.h"

void afficher_commande (BITMAP* buffer)
{
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    BITMAP* fondbas = load_bitmap("fondbas.bmp",NULL);
    BITMAP* fondcote = load_bitmap("fondcote.bmp",NULL);
    BITMAP* petitRon = load_bitmap("rondoudou/rondoudou1.bmp",NULL);
    BITMAP* PA = load_bitmap("PA.bmp",NULL);
    BITMAP* PM = load_bitmap("PM.bmp",NULL);
    BITMAP* PV = load_bitmap("PV.bmp",NULL);

    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);

    int casex, casey, casex2, casey2;
    casex = -30;
    casey = -32;
    casex2 = 30;
    casey2 = 32;

    blit(fondbas,buffer,0,casey*18,0,0,buffer->w,buffer->h);
    blit(fondcote,buffer,casex*36,0,0,0,buffer->w,buffer->h);

    commande_pokemon(buffer);

    //AffichageBouton(cageE,cageEInv,buffer,0,0,casex2*9,casey2*19,75,54);

    masked_blit(PA,buffer,casex*5,-600,0,0,buffer->w,buffer->h);
    masked_blit(PM,buffer,casex*5,-660,0,0,buffer->w,buffer->h);
    masked_blit(PV,buffer,casex*2,-620,0,0,buffer->w,buffer->h);

}

void commande_pokemon (BITMAP* buffer)
{
    BITMAP* pikachu = load_bitmap("pikachu1.bmp",NULL);
    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);
    BITMAP* fatF = load_bitmap("pikachu/FatalFoudre.bmp",NULL);
    BITMAP* fatFInv = load_bitmap("pikachu/FatalFoudreInv.bmp",NULL);
    BITMAP* boulE = load_bitmap("pikachu/BouleElek.bmp",NULL);
    BITMAP* boulEInv = load_bitmap("pikachu/BoulEInv.bmp",NULL);
    BITMAP* coupJ = load_bitmap("pikachu/CoupJus.bmp",NULL);
    BITMAP* coupJInv = load_bitmap("pikachu/CoupJusInv.bmp",NULL);
    BITMAP* vitEx = load_bitmap("pikachu/VitesseExtreme.bmp",NULL);
    BITMAP* vitExInv = load_bitmap("pikachu/VitesseExtremeInv.bmp",NULL);

    int casex, casey;
    casex = 30;
    casey = 32;

    /*AffichageBouton(joueur->pokemon->sort1->bouton,joueur->pokemon->sort1->boutonInv,buffer,casex*6,casey*30,0,0,75,54);
    AffichageBouton(joueur->pokemon->sort2->bouton,joueur->pokemon->sort2->boutonInv,buffer,casex*8,casey*30,0,0,75,54);
    AffichageBouton(joueur->pokemon->sort3->bouton,joueur->pokemon->sort3->boutonInv,buffer,casex*10,casey*30,0,0,75,54);,t_joueur* joueur, t_classe* pokemon, t_sorts* sort
    AffichageBouton(joueur->pokemon->sort4->bouton,joueur->pokemon->sort4->boutonInv,buffer,casex*12,casey*30,0,0,75,54);
    AffichageBouton(joueur->pokemon->sort5->bouton,joueur->pokemon->sort5->boutonInv,buffer,casex*14,casey*30,0,0,75,54);*/

    AffichageBouton(cageE,cageEInv,buffer,0,0,casex*10,casey*19,75,54);
    AffichageBouton(fatF,fatFInv,buffer,0,0,casex*14,casey*19,75,54);
    AffichageBouton(boulE,boulEInv,buffer,0,0,casex*18,casey*19,75,54);
    AffichageBouton(coupJ,coupJInv,buffer,0,0,casex*22,casey*19,75,54);
    AffichageBouton(vitEx,vitExInv,buffer,0,0,casex*26,casey*19,75,54);
}

