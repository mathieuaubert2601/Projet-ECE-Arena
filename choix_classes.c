#include "header.h"
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page, t_joueur* joueur, int* violetCity, SAMPLE* musiqueFond)
{
    SAMPLE* pikachuSon = load_sample("sons_pokemons/pikachu.wav");
    SAMPLE* ronflexSon = load_sample("sons_pokemons/ronflex.wav");
    SAMPLE* lucarioSon = load_sample("sons_pokemons/lucario.wav");
    SAMPLE* alakazamSon = load_sample("sons_pokemons/alakazam.wav");
    SAMPLE* rondoudouSon = load_sample("sons_pokemons/rondoudou.wav");


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
    stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
    masked_stretch_blit(classe1,page,0,0,115,103,15,330,255,203);
    masked_stretch_blit(classe2,page,0,0,127,114,240,350,217,186);
    masked_stretch_blit(classe3,page,0,0,86,121,480,330,216,200);
    masked_stretch_blit(classe4,page,0,0,135,120,700,330,225,200);
    masked_stretch_blit(classe5,page,0,0,128,118,950,330,220,200);
    //masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);

    ///Affichage nom des pok�mons
    AffichageBouton(bouton1,boutonInv1,page,0,0,15,550,212,67);
    AffichageBouton(bouton2,boutonInv2,page,0,0,245,550,211,67);
    AffichageBouton(bouton3,boutonInv3,page,0,0,485,550,212,67);
    AffichageBouton(bouton4,boutonInv4,page,0,0,705,550,211,67);
    AffichageBouton(bouton5,boutonInv5,page,0,0,955,550,211,67);

    ///Affichage bouton infos
    AffichageBouton(boutonI,boutonInvI,page,0,0,68,625,100,50);
    AffichageBouton(boutonI,boutonInvI,page,0,0,300,625,100,50);
    AffichageBouton(boutonI,boutonInvI,page,0,0,550,625,100,50);
    AffichageBouton(boutonI,boutonInvI,page,0,0,765,625,100,50);
    AffichageBouton(boutonI,boutonInvI,page,0,0,1020,625,100,50);

    masked_stretch_blit(logo,page,0,0,755,374,300,5,600,300);

    if(((mouse_x>=(68)&& mouse_x<=(68+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&& (mouse_b && 1))
    {
        information_Pikachu(page,fond);
    }
    if(((mouse_x>=(300)&& mouse_x<=(300+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
    {
        information_Ronflex(page,fond);
    }
    if(((mouse_x>=(550)&& mouse_x<=(550+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
    {
       information_Lucario(page,fond);
    }
    if(((mouse_x>=(765)&& mouse_x<=(765+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
    {
        information_Alakazam(page,fond);
    }
    if(((mouse_x>=(1020)&& mouse_x<=(1020+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
    {
        information_Rondoudou(page,fond);
    }


    //Choix de Pikachu
    if((mouse_x>=(15) && mouse_x<=(227)) && (mouse_y)<=(617) && mouse_y>=(550))
    {
        if(mouse_b && 1)
        {
            joueur->classe=1;
            joueur->pv=75;
            joueur->pm=6;
            play_sample(pikachuSon,600,0,1000,0);
        }
    }

    //Choix de Ronflex
    if((mouse_x<=(456) && mouse_x>=(245)) && (mouse_y)<=(617) && mouse_y>=(550))
    {
        if(mouse_b && 1)
        {
            joueur->classe=2;
            joueur->pv=125;
            joueur->pm=2;
            play_sample(ronflexSon,600,0,1000,0);
        }
    }

    //Choix de Lucario
    if((mouse_x<=(697) && mouse_x>=(485)) && (mouse_y)<=(617) && mouse_y>=(550))
    {
        if(mouse_b && 1)
        {
            joueur->classe=3;
            joueur->pv=100;
            joueur->pm=4;
            play_sample(lucarioSon,600,0,1000,0);
        }
    }

    //Choix d'Alakazam
    if((mouse_x<=(916) && mouse_x>=(705)) && (mouse_y)<=(617) && mouse_y>=(550))
    {
        if(mouse_b && 1)
        {
            joueur->classe=4;
            joueur->pv=100;
            joueur->pm=4;
            play_sample(alakazamSon,600,0,1000,0);
        }
    }

    //Choix de Rondoudou
    if((mouse_x<=(1166) && mouse_x>=(955)) && (mouse_y)<=(617) && mouse_y>=(550))
    {
        if(mouse_b && 1)
        {
            joueur->classe=5;
            joueur->pv=75;
            joueur->pm=6;
            play_sample(rondoudouSon,600,0,1000,0);
        }
    }
 }
