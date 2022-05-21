#include "header.h"

void afficher_deplacement_plus_court(int tableau_case_dispo[18][36],int x,int y, int x_souris, int y_souris, int tableau_a_rendre[18][36])
{
    //déclaration des variables;
    int tableau_case_tmp[18][36];
    int x_tmp = x_souris, y_tmp = y_souris;



    //Copie des information du premier tableau dans le second
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            tableau_case_tmp[i][j] = tableau_case_dispo[i][j];
        }

    }

    //On vérifie si la case renvoyée par la souris est bien dans le tableau
    if(tableau_case_tmp[y_souris][x_souris] != 1 && tableau_case_tmp[y_souris][x_souris] != 0)
    {

        for(int i=tableau_case_tmp[y_tmp][x_tmp] ; i>2 ; i--)
        {
            if(tableau_case_tmp[y_tmp + 1][x_tmp] == i-1 && (y_tmp +1)<18)
            {
                y_tmp = y_tmp + 1;
                tableau_case_tmp[y_tmp - 1][x_tmp] = 30;
            }
            else if(tableau_case_tmp[y_tmp - 1][x_tmp] == i-1 && (y_tmp -1)>=0)
            {
                y_tmp = y_tmp - 1;
                tableau_case_tmp[y_tmp + 1][x_tmp] = 30;
            }
            else if(tableau_case_tmp[y_tmp][x_tmp +1] == i-1 && (x_tmp +1)<36)
            {
                x_tmp = x_tmp + 1;
                tableau_case_tmp[y_tmp][x_tmp-1] = 30;
            }
            else if(tableau_case_tmp[y_tmp][x_tmp -1] == i-1 && (x_tmp -1)>=0)
            {
                x_tmp = x_tmp - 1;
                tableau_case_tmp[y_tmp][x_tmp+1] = 30;
            }
        }

    }

    //On copie les information dans le tableau à rendre
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            tableau_a_rendre[i][j] = tableau_case_tmp[i][j];
        }
    }

}

void afficher_chemin(BITMAP* buffer, int tableau_a_afficher[18][36],t_joueur tableau_joueur[],int nombre_joueur, int indice_joueur)
{
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            if(tableau_a_afficher[i][j] == 30)
            {
                casebleu_foncee(buffer,j,i);
            }
        }
    }
    for(int k=0 ; k<nombre_joueur ; k++)
    {

            if(tableau_joueur[k].numeroClasse == 1)
            {
                afficher_personnage_pikachu(buffer,0,0,tableau_joueur[k].colonne,tableau_joueur[k].ligne);
            }
            if(tableau_joueur[k].numeroClasse == 2)
            {
                afficher_personnage_ronflex(buffer,0,0,tableau_joueur[k].colonne,tableau_joueur[k].ligne);
            }
            if(tableau_joueur[k].numeroClasse == 3)
            {
                afficher_personnage_lucario(buffer,0,0,tableau_joueur[k].colonne,tableau_joueur[k].ligne);
            }
            if(tableau_joueur[k].numeroClasse == 4)
            {
                afficher_personnage_alakazam(buffer,0,0,tableau_joueur[k].colonne,tableau_joueur[k].ligne);
            }
            if(tableau_joueur[k].numeroClasse == 5)
            {
                afficher_personnage_rondoudou(buffer,0,0,tableau_joueur[k].colonne,tableau_joueur[k].ligne);
            }

    }
}

void changement_case_souris(BITMAP* buffer,int x_souris,int y_souris, int* case_x, int* case_y,int tableau_case_dispo[18][36],int tableau_chemin_court[18][36],int x,int y)
{
    //déclaration des variables
    int case_x_tmp = (x_souris/30), case_y_tmp = (y_souris/32);

    //test si la souris est dans la carte
    if(case_x_tmp < 36 && case_y_tmp < 18)
    {
        if(case_x_tmp != *case_x || case_y_tmp!= *case_y)
        {
            afficher_deplacement_plus_court(tableau_case_dispo,x,y,case_x_tmp,case_y_tmp,tableau_chemin_court);
            *case_x = case_x_tmp;
            *case_y = case_y_tmp;

        }
    }

}
