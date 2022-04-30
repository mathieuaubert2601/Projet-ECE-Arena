#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

///D�claration des biblioth�ques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

///D�claration des structures

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



///D�claration des prototypes des sous programmes
void initialisationAllegro();
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page, t_joueur* joueur,int* violetCity,SAMPLE* musiqueFond);
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
void information_Pikachu(BITMAP* page, BITMAP* fond);
void information_Lucario(BITMAP* page, BITMAP* fond);
void information_Ronflex(BITMAP* page, BITMAP* fond);
void information_Alakazam(BITMAP* page, BITMAP* fond);
void information_Rondoudou(BITMAP* page, BITMAP* fond);

#endif // HEADER_H_INCLUDED
