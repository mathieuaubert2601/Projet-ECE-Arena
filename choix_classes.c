#include "header.h"
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page, t_joueur* joueur)
{
    ///Déclaration des BITMAP
    BITMAP* bouton1 = load_bitmap("boutons/boutonPik.bmp",NULL);
    BITMAP* boutonInv1 = load_bitmap("boutons/boutonInvPik.bmp",NULL);

    BITMAP* bouton2 = load_bitmap("boutons/boutonRonf.bmp",NULL);
    BITMAP* boutonInv2 = load_bitmap("boutons/boutonInvRonf.bmp",NULL);

    BITMAP* bouton3 = load_bitmap("boutons/boutonLu.bmp",NULL);
    BITMAP* boutonInv3 = load_bitmap("boutons/boutonInvLu.bmp",NULL);

    BITMAP* bouton4 = load_bitmap("boutons/boutonAl.bmp",NULL);
    BITMAP* boutonInv4 = load_bitmap("boutons/boutonInvAl.bmp",NULL);

    BITMAP* bouton5 = load_bitmap("boutons/boutonRon.bmp",NULL);
    BITMAP* boutonInv5 = load_bitmap("boutons/boutonInvRon.bmp",NULL);

    BITMAP* boutonI = load_bitmap("boutons/boutonInfos.bmp",NULL);
    BITMAP* boutonInvI = load_bitmap("boutons/boutonInvInfos.bmp",NULL);

    BITMAP* logo = load_bitmap("logo.bmp",NULL);

    ///Affichage des pok�mons
    stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
    masked_stretch_blit(classe1,page,0,0,115,103,15,400,255,203);
    masked_stretch_blit(classe2,page,0,0,127,114,240,420,217,186);
    masked_stretch_blit(classe3,page,0,0,86,121,480,400,216,200);
    masked_stretch_blit(classe4,page,0,0,135,120,700,400,225,200);
    masked_stretch_blit(classe5,page,0,0,128,118,950,400,220,200);
    //masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);

    ///Affichage nom des pok�mons
    AffichageBouton(bouton1,boutonInv1,page,0,0,15,650,212,67,1);
    AffichageBouton(bouton2,boutonInv2,page,0,0,245,650,211,67,2);
    AffichageBouton(bouton3,boutonInv3,page,0,0,485,650,212,67,3);
    AffichageBouton(bouton4,boutonInv4,page,0,0,705,650,211,67,4);
    AffichageBouton(bouton5,boutonInv5,page,0,0,955,650,211,67,5);

    ///Affichage bouton infos
    AffichageBouton(boutonI,boutonInvI,page,0,0,68,725,100,50,0);
    AffichageBouton(boutonI,boutonInvI,page,0,0,300,725,100,50,0);
    AffichageBouton(boutonI,boutonInvI,page,0,0,550,725,100,50,0);
    AffichageBouton(boutonI,boutonInvI,page,0,0,765,725,100,50,0);
    AffichageBouton(boutonI,boutonInvI,page,0,0,1020,725,100,50,0);

    masked_blit(logo,page,0,0,200,5,755,374);

    /*AffichageBouton(page,75,350,175,400,makecol(220,220,220));
    AffichageBouton(page,300,350,400,400,makecol(220,220,220));
    AffichageBouton(page,525,350,625,400,makecol(220,220,220));
    AffichageBouton(page,750,350,850,400,makecol(220,220,220));
    AffichageBouton(page,1000,350,1100,400,makecol(220,220,220));*/


    //Choix de Pikachu
    if((mouse_x>=(200) && mouse_x>=(50)) && (mouse_y)<=(700) && mouse_y>=(650))
    {
        if(mouse_b && 1)
        {
            joueur->classe=1;
            joueur->pv=75;
            joueur->pm=6;
        }
    }

    //Choix de Ronflex
    if((mouse_x<=(425) && mouse_x>=(275)) && (mouse_y)<=(700) && mouse_y>=(650))
    {
        if(mouse_b && 1)
        {
            joueur->classe=2;
            joueur->pv=125;
            joueur->pm=2;
        }
    }

    //Choix de Lucario
    if((mouse_x<=(650) && mouse_x>=(500)) && (mouse_y)<=(700) && mouse_y>=(650))
    {
        if(mouse_b && 1)
        {
            joueur->classe=3;
            joueur->pv=100;
            joueur->pm=4;
        }
    }

    //Choix d'Alakazam
    if((mouse_x<=(875) && mouse_x>=(725)) && (mouse_y)<=(700) && mouse_y>=(650))
    {
        if(mouse_b && 1)
        {
            joueur->classe=4;
            joueur->pv=100;
            joueur->pm=4;
        }
    }

    //Choix de Rondoudou
    if((mouse_x<=(1125) && mouse_x>=(975)) && (mouse_y)<=(700) && mouse_y>=(650))
    {
        if(mouse_b && 1)
        {
            joueur->classe=5;
            joueur->pv=75;
            joueur->pm=6;
        }
    }
 }
