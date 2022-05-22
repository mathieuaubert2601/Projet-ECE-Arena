#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

///Declaration des biblioth�ques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


///Declaration des structures
//Structure sort
typedef struct sorts
{
    int degats,numero,plusMoins,chance,type,pMin,pMax,rayon,nbrPa,typePortee,typeStatus,typeSoin;
    BITMAP* bouton;
    BITMAP* boutonInv;
    BITMAP* infos;
}t_sorts;

typedef struct classe
{
    char nom[15];
    int classe,pv,pm;
    t_sorts sort1,sort2,sort3,sort4,sort5,corps;
    BITMAP* profil;
    BITMAP* profilvert;
    BITMAP* profilrouge;
    SAMPLE* sonClasse;
}t_classe;

//Structure joueur
typedef struct joueur
{
    char pseudo[15];
    int ligne, colonne, numero, equipe, pa, tourPoison, tourDodo, tourParalysie, tourPeur, tourBouclier, tourHate, score, pv, pm, numeroClasse,mort,kills,degats;
    t_classe classe;
}t_joueur;



//structure case
typedef struct cases
{
    int disponibleOuNon;
}t_cases;



///Declaration des prototypes des sous programmes
//Init_allegro
void initialisationAllegro();
//boutons_menu
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
void AffichageSorts(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur, int hauteurinfos, int longueurinfos);
void AffichageSorts2(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur,int hauteur,int longueurinfos,int hauteurinfos);
void phrases(BITMAP* page,int p);
void afficher_attaque_ronflex(BITMAP* buffer);
void afficher_attaque_rondoudou(BITMAP* buffer);
void afficher_attaque_alakazam(BITMAP* buffer);
void afficher_attaque_lucario(BITMAP* buffer);
void afficher_attaque_pikachu(BITMAP* buffer);
//choix_classes
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* page, t_joueur joueur[], int* violetCity, SAMPLE* musiqueFond, int nbJoueur, int tabCases[18][36], int t, int equipe);
//informations_classe
void information_Pikachu(BITMAP* page, BITMAP* fond);
void information_Lucario(BITMAP* page, BITMAP* fond);
void information_Ronflex(BITMAP* page, BITMAP* fond);
void information_Alakazam(BITMAP* page, BITMAP* fond);
void information_Rondoudou(BITMAP* page, BITMAP* fond);
void attaque_Pikachu(BITMAP* page);
//carte
void afficher_map(BITMAP* buffer);
void afficher_arbre(BITMAP* buffer, int x, int y);
void afficher_tout_arbre(BITMAP* buffer, int matrice_arbre[18][36]);
void afficher_coordonnees(BITMAP* buffer);
void casebleu(BITMAP* buffer, int posy, int posx);
void afficher_cases_non_obstacles(int tab_cases[18][36],BITMAP* buffer);
void afficher_cases_dispo_joueur(BITMAP* buffer,int x,int y, int pm,int tableau_cases[18][36], int tableau_a_rendre[18][36],t_joueur tabJoueur[],int nbJoueur,int indice);
void casebleu_foncee(BITMAP* buffer, int posy, int posx);
void copier_tableau_case(int tableau_source[18][36], int tableau_destination[18][36]);
void remettre_case_obstacle(int matrice_A_Modifier[18][36]);
void afficher_lac(BITMAP* buffer);
void caserouge(BITMAP* buffer, int posx, int posy);
void demande_placement (BITMAP* buffer, t_joueur* joueur,int tableau[18][36], int tab_arbres[18][36], t_joueur tabJoueur[], int indice);
//affichage_Personnages
void afficher_personnage_pikachu(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur);
void afficher_personnage_lucario(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur);
void afficher_personnage_ronflex(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur);
void afficher_personnage_rondoudou(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur);
void afficher_personnage_alakazam(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur);
//menuNbJoueur
void menuNbJoueur(BITMAP* page, BITMAP* fond,BITMAP* logo,int* violetCity);
//menuJeu
void menuJeu(BITMAP* page, BITMAP* fond,BITMAP* logo);
void Saisir_nom(char nom_joueur[15], BITMAP* page);
//barre_commande
void afficher_commande(BITMAP* buffer,t_joueur tab[],int nbJ, int j);
void affichage_profil(BITMAP* buffer,t_joueur tab[],int nbJ, int j);
void commande_pokemon (BITMAP* buffer,t_joueur joueur[],int j);
void menu_pause(BITMAP* buffer);
//deplacement_joueur

void deplacement_joueur(BITMAP* buffer, int indice_ligne_ini, int indice_colonne_ini, int personnage,int tableau_chemin_court[18][36],int tableau_affichage_arbre[18][32],t_joueur tableau_joueur[],int nombre_joueur, int indice_joueur);
void afficher_deplacement_plus_court(int tableau_case_dispo[18][36],int x,int y, int x_souris, int y_souris, int tableau_a_rendre[18][36]);
void changement_case_souris(BITMAP* buffer,int x_souris,int y_souris, int* case_x, int* case_y,int tableau_case_dispo[18][36],int tableau_chemin_court[18][36],int x,int y);
void afficher_chemin(BITMAP* buffer, int tableau_a_afficher[18][36],t_joueur tableau_joueur[],int nombre_joueur, int indice_joueur);
//gestionSorts
void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur tabJoueurs[], int nombreJoueur, int tourJoueur, BITMAP* page, int tab[18][36]);
void sortAttaque2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page);
void sortAttaque3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page);
void sortAttaque4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page);
void sortMouvement(t_sorts sort1, t_joueur* joueurA, BITMAP* page, int tab[18][36], int nbJoueurs,t_joueur* tabJoueur[]);
void sortStatut2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page);
void sortStatut3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page);
void sortStatut4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page);
void sortVie(t_sorts sort1, t_joueur* joueurA,BITMAP* page);
void sortSoin2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page);
void sortSoin3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page);
void sortSoin4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page);
int test_clique_Suppr(int destx, int desty, int longueur, int hauteur,int compteur,char pseudo[15]);
int test_clique_Entree(int destx, int desty, int longueur, int hauteur,int boule,char pseudo[15]);
int test_clique(int destx, int desty, int longueur, int hauteur,char lettre,int compteur,char pseudo[15]);
void ordreJoueurs(t_joueur ordreJoueur[],t_joueur tabJoueur[], int nbrJoueur);
//Classement
void classement2J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1);
void classement3J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2);
void classement4J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2, t_joueur joueurP3);
void classementEquipe(BITMAP* buffer,t_joueur joueurG1, t_joueur joueurG2,t_joueur joueurP1,t_joueur joueurP2);
#endif // HEADER_H_INCLUDED
