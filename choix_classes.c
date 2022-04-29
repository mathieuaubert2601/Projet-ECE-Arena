#include "header.h"
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page)
{
    ///Déclaration des BITMAP
    BITMAP* bouton1 = load_bitmap("boutonPik.bmp",NULL);
    BITMAP* boutonInv1 = load_bitmap("boutonInvPik.bmp",NULL);

    BITMAP* bouton2 = load_bitmap("boutonRonf.bmp",NULL);
    BITMAP* boutonInv2 = load_bitmap("boutonInvRonf.bmp",NULL);

    BITMAP* bouton3 = load_bitmap("boutonLu.bmp",NULL);
    BITMAP* boutonInv3 = load_bitmap("boutonInvLu.bmp",NULL);

    BITMAP* bouton4 = load_bitmap("boutonAl.bmp",NULL);
    BITMAP* boutonInv4 = load_bitmap("boutonInvAl.bmp",NULL);

    BITMAP* bouton5 = load_bitmap("boutonRon.bmp",NULL);
    BITMAP* boutonInv5 = load_bitmap("boutonInvRon.bmp",NULL);

    BITMAP* boutonI = load_bitmap("boutonInfos.bmp",NULL);
    BITMAP* boutonInvI = load_bitmap("boutonInvInfos.bmp",NULL);

    ///Affichage des pokémons
    stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
    masked_stretch_blit(classe1,page,0,0,115,103,15,400,255,203);
    masked_stretch_blit(classe2,page,0,0,127,114,240,420,217,186);
    masked_stretch_blit(classe3,page,0,0,86,121,480,400,216,200);
    masked_stretch_blit(classe4,page,0,0,135,120,700,400,225,200);
    masked_stretch_blit(classe5,page,0,0,128,118,950,400,220,200);

    ///Affichage nom des pokémons
    AffichageBouton(bouton1,boutonInv1,page,0,0,15,650,212,67);
    AffichageBouton(bouton2,boutonInv2,page,0,0,245,650,211,67);
    AffichageBouton(bouton3,boutonInv3,page,0,0,485,650,212,67);
    AffichageBouton(bouton4,boutonInv4,page,0,0,705,650,211,67);
    AffichageBouton(bouton5,boutonInv5,page,0,0,955,650,211,67);

    ///Affichage bouton infos
    /*AffichageBouton(boutonI,boutonInvI,page,0,0,15,650,212,67);
    AffichageBouton(boutonI,boutonInvI,page,0,0,245,650,211,67);
    AffichageBouton(boutonI,boutonInvI,page,0,0,485,650,212,67);
    AffichageBouton(boutonI,boutonInvI,page,0,0,705,650,211,67);
    AffichageBouton(boutonI,boutonInvI,page,0,0,955,650,211,67);*/

    /*AffichageBouton(page,75,350,175,400,makecol(220,220,220));
    AffichageBouton(page,300,350,400,400,makecol(220,220,220));
    AffichageBouton(page,525,350,625,400,makecol(220,220,220));
    AffichageBouton(page,750,350,850,400,makecol(220,220,220));
    AffichageBouton(page,1000,350,1100,400,makecol(220,220,220));*/


    }
