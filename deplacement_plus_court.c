#include "header.h"

void afficher_deplacement_plus_court(BITMAP* buffer, int tableau_case_dispo[18][36],int x,int y, int x_souris, int y_souris,int pm)
{
    //déclaration des variables
    int tableau_chemin_plus_court_x_plus[18][36];
    int tableau_chemin_plus_court_x_moins[18][36];
    int tableau_chemin_plus_court_y_plus[18][36];
    int tableau_chemin_plus_court_y_moins[18][36];
    int deplacement_y_plus = 0,deplacement_y_moins = 0,deplacement_x_moins = 0,deplacement_x_plus = 1;
    int compteur_x_plus = 0, compteur_x_moins = 0, compteur_y_plus = 0, compteur_y_moins = 0;
    int x_tmp = x , y_tmp = y;

    //copie du tableau de case dispo dans le tableau du chemin le plus court
    for(int i=0 ; i<36 ; i++)
    {
        for(int j=0 ; j<18 ; j++)
        {
            tableau_chemin_plus_court_x_plus[j][i] = tableau_case_dispo[j][i];
            tableau_chemin_plus_court_x_moins[j][i] = tableau_case_dispo[j][i];
            tableau_chemin_plus_court_y_plus[j][i] = tableau_case_dispo[j][i];
            tableau_chemin_plus_court_y_moins[j][i] = tableau_case_dispo[j][i];
        }
    }

    //On priorise le déplacement sur l'axe x +
    while(deplacement_x_plus == 1 && (compteur_x_plus <= pm))
    {
        if(x_tmp < x_souris && tableau_chemin_plus_court_x_plus[x+1][y_tmp] == 2)
        {
            x_tmp ++;
            compteur_x_plus++;
            tableau_chemin_plus_court_x_plus[x_tmp][y_tmp] = 3;
        }
        else
        {

        }
    }



}
