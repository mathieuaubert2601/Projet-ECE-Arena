#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

///Declaration des biblioth�ques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>


///Declaration des structures
//Structure sort
typedef struct sorts
{
    int degats,numero,plusMoins,chance,type,pMin,pMax,rayon,nbrPa,typePortee,typeStatus,typeSoin;
    BITMAP* bouton;
    BITMAP* boutonInv;
}t_sorts;

typedef struct classe
{
    char nom[15];
    int classe,pv,pm;
    t_sorts sort1,sort2,sort3,sort4,sort5;
    BITMAP* profil;
    BITMAP* profilvert;
    SAMPLE* sonClasse;
}t_classe;

//Structure joueur
typedef struct joueur
{
    char pseudo[15];
    int ligne, colonne, numero, equipe,pa,tourPoison,tourDodo,tourParalysie,tourPeur,tourBouclier,score;
    t_classe classe;
}t_joueur;



//structure case
typedef struct cases
{
    int disponibleOuNon;
}t_cases;



///Declaration des prototypes des sous programmes
void initialisationAllegro();
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* page, t_joueur* joueur,int* violetCity,SAMPLE* musiqueFond);
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
void information_Pikachu(BITMAP* page, BITMAP* fond);
void information_Lucario(BITMAP* page, BITMAP* fond);
void information_Ronflex(BITMAP* page, BITMAP* fond);
void information_Alakazam(BITMAP* page, BITMAP* fond);
void information_Rondoudou(BITMAP* page, BITMAP* fond);
void afficher_map(BITMAP* buffer);
void afficher_arbre(BITMAP* buffer);
void afficher_coordonnees(BITMAP* buffer);
void afficher_personnage_pikachu(BITMAP* buffer,int compteur,int cote,int x,int y);
void afficher_personnage_lucario(BITMAP* buffer,int compteur,int cote,int x,int y);
void afficher_personnage_ronflex(BITMAP* buffer,int compteur,int cote,int x,int y);
void afficher_personnage_rondoudou(BITMAP* buffer,int compteur,int cote,int x,int y);
void afficher_personnage_alakazam(BITMAP* buffer,int compteur,int cote,int x,int y);
void menuNbJoueur(BITMAP* page, BITMAP* fond,BITMAP* logo,int* violetCity);
void menuJeu(BITMAP* page, BITMAP* fond,BITMAP* logo);
void afficher_caractere(BITMAP* buffer);
void casebleu(BITMAP* buffer, int posx, int posy);
void afficher_cases_non_obstacles(int tab_cases[18][36],BITMAP* buffer);
void afficher_cases_dispo_joueur(BITMAP* buffer,int x,int y , int pm,int tableau_cases[18][36]);
void afficher_commande(BITMAP* buffer,t_joueur* joueur);
#endif // HEADER_H_INCLUDED
