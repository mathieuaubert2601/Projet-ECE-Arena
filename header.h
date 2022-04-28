#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

///Déclaration des bibliothèques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

///Déclaration des structures

//Structure joueur
typedef struct joueur
{
    char* pseudo;
    int ligne, colonne, numero, equipe,classe,pv,pm,pa,tourPoison,tourDodo,tourParalysie,tourPeur,tourBouclier,score;
    BITMAP* bitmap
}t_joueur;

//Structure sort
typedef struct sorts
{
    int degats,numero,plusMoins,chance,type,pMin,pMax,rayon,nbrPa,typePortee,typeStatus,typeSoin;
}t_sorts;

//structure case
typedef struct cases
{
    int disponibleOuNon;
}t_cases;



///Déclaration des prototypes des sous programmes
void initialisationAllegro();
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page, t_joueur* joueur);
void AffichageBouton(BITMAP* page,int posx,int posy,int posx2,int posy2,int couleur);


#endif // HEADER_H_INCLUDED
