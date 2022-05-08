#include "header.h"

void afficher_map(BITMAP* buffer)
{
    //d�claration des variables
    BITMAP* carte = load_bitmap("map/map.bmp",NULL);
    BITMAP* arbre = load_bitmap("map/arbre1.bmp",NULL);

    //affichage de la carte sur le buffer
    blit(carte,buffer,0,0,0,0,buffer->w,buffer->h);
}

void afficher_cases_non_obstacles(int tab_cases[18][36],BITMAP* buffer)
{
    for(int i=0; i<18; i++)
    {
        for(int j=0; j<36; j++)
        {
            if(tab_cases[i][j] == 0)
            {
                casebleu_foncee(buffer,j,i);
            }
        }
    }
}

void copier_tableau_case(int tableau_source[18][36], int tableau_destination[18][36])
{
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j=0 ; j<36 ; j++)
        {
            tableau_destination[i][j] = tableau_destination[i][j];
        }
    }
}

void afficher_cases_dispo_joueur(BITMAP* buffer,int x,int y, int pm,int tableau_cases[18][36])
{
    //déclaration du tableau de case intermédiaire
    //int tableau_case_tmp[18][36];
    int tableau_case_tmp[18][36] ;

    //Déclaration des variables de test
    int soustraction_ligne, soustraction_colonne, addition_globale,obstacle = 0;

    //déclaration compteur;
    int compteur,changement_ou_non;

    //déclaration des points de mouvement temporaires


    //Copie des information du premier tableau dans le second
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            tableau_case_tmp[i][j] = tableau_cases[i][j];

        }

    }




    //On affiche toute les cases dans le bon rayon
    for(int i=0 ; i < 18 ; i++)
    {
        for(int j=0 ; j<36 ; j++)
        {
            soustraction_ligne = abs(x - j);
            soustraction_colonne = abs(y - i);
            addition_globale = soustraction_colonne + soustraction_ligne;

            if(addition_globale <= pm && tableau_case_tmp[i][j]==0)
            {
                tableau_case_tmp[i][j] = 2;
            }
        }
    }

    ///On regarde s'il y a un obstacle boucle x y
    //x+ y+
    compteur = 1;  //On met le compteur à 1 car on prend pas en compte la dernière case si obstacle
    for(int i=x ; i<=(x+pm) ; i++)
    {
        if(i < 35 && i>0)
        {
            for(int j=y ; j<= ((y+pm)-compteur) ; j++)
            {
                if(j<17 && j>0)
                {
                    if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[j][i-1] == 1 || tableau_case_tmp[j+1][i-1] == 1) && (tableau_case_tmp[j][i+1] == 1 || tableau_case_tmp[j+1][i+1] == 1))
                        {
                            for(int k = ((y+pm)-compteur+1) ; k >= (((y-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&& k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 4;
                                    }
                                }
                            }
                            for(int k = ((y-2+pm)-compteur+1) ; k >= (((y-3)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&& k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k = ((y+pm)-compteur+1) ; k >= (((y-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&&k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }
    //x+ y-
    compteur = 1;
    obstacle = 0;
    for(int i=x ; i <= (x+pm) ; i++)
    {
        if(i < 35 && i>0)
        {
            for(int j=y ; j>= (y-pm)+compteur ; j--)
            {

                if(j<17 && j>0)
                {
                    if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[j][i-1] == 1 || tableau_case_tmp[j-1][i-1] == 1) && (tableau_case_tmp[j][i+1] == 1 || tableau_case_tmp[j-1][i+1] == 1))
                        {
                            for(int k = ((y-pm)+compteur+1) ; k <= (((y+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&&k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 4;
                                    }
                                }
                            }
                            for(int k = ((y+2-pm)+compteur+1) ; k <= (((y+3)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&&k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k = ((y-pm)+compteur+1) ; k <= (((y+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&&k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }
    //x- y+
    compteur = 1;
    obstacle = 0;
    for(int i=x ; i>= x-pm ; i--)
    {
        if(i < 35 && i>0)
        {
            for(int j=y ; j<= ((y+pm) - compteur); j++)
            {
                if(y<17 && j>0)
                {
                    if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[j][i-1] == 1 || tableau_case_tmp[j+1][i-1] == 1) && (tableau_case_tmp[j][i+1] == 1 || tableau_case_tmp[j+1][i+1] == 1))
                        {
                            for(int k = ((y+pm)-compteur+1) ; k >= (((y-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&&k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 4;
                                    }
                                }
                            }
                            for(int k = (((y-2)+pm)-compteur+1) ; k >= (((y-3)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&&k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k = ((y+pm)-compteur+1) ; k >= (((y-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<18)&&k>j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }
    //x- j-
    compteur = 1;
    obstacle = 0;
    for(int i=x ; i>= (x-pm) ; i--)
    {
        if(i < 35 && i>0)
        {
            for(int j=y ; j>= (y-pm)+compteur ; j--)
            {
                if(y<17 && y>0)
                {

                    if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[j][i-1] == 1 || tableau_case_tmp[j-1][i-1] == 1) && (tableau_case_tmp[j][i+1] == 1 || tableau_case_tmp[j-1][i+1] == 1))
                        {
                            for(int k = ((y-pm)+compteur+1) ; k <= (((y+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&& k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 4;
                                    }
                                }
                            }
                            for(int k = (((y+2)-pm)+compteur+1) ; k <= (((y+3)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&& k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k = ((y-pm)+compteur+1) ; k <= (((y+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<18)&& k<j)
                                {
                                    if(tableau_case_tmp[k][i] != 1)
                                    {
                                        tableau_case_tmp[k][i] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }

    ///On regarde s'il y a un obstacle boucle y x
    //y+ x+
    compteur = 1;
    obstacle = 0;
    for(int i=y ; i<= y+pm ; i++)
    {
        if(i<17 && i>0)
        {
            for(int j=x ; j <= ((x+pm)-compteur) ; j++)
            {
                if(j<35 && j>0)
                {
                    if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[i+1][j] == 1 || tableau_case_tmp[i+1][i+1] == 1) && (tableau_case_tmp[i-1][j] == 1 || tableau_case_tmp[i-1][j+1] == 1))
                        {
                            for(int k= ((x+pm)-compteur+1) ; k>= (((x-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&&k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 4;
                                    }
                                }
                            }
                            for(int k= (((x-2)+pm)-compteur+1) ; k>= (((x-3)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&&k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k= ((x+pm)-compteur+1) ; k>= (((x-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&&k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;

    }
    //y+ x-
    compteur = 1;
    obstacle = 0;
    for(int i=y ; i<= y+pm ; i++)
    {
        if(i<17 && i>0)
        {
            for(int j=x ; j >= ((x-pm)+compteur) ; j--)
            {
                if(j<35 && j>0)
                {
                    if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[i+1][j] == 1 || tableau_case_tmp[i+1][i+1] == 1) && (tableau_case_tmp[i-1][j] == 1 || tableau_case_tmp[i-1][j+1] == 1))
                        {
                            for(int k= ((x-pm)+compteur+1) ; k<= (((x+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 4;
                                    }
                                }
                            }
                            for(int k= (((x+2)-pm)+compteur+1) ; k<= (((x+3)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k= ((x-pm)+compteur+1) ; k<= (((x+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }
    //y- x+
    compteur = 1;
    obstacle = 0;
    for(int i=y ; i>=y-pm ; i--)
    {
        if(i<17 && i>0)
        {
            for(int j=x ; j<= ((x+pm)-compteur) ; j++)
            {
                if(j<35 && j>0)
                {
                    if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[i+1][j] == 1 || tableau_case_tmp[i+1][i+1] == 1) && (tableau_case_tmp[i-1][j] == 1 || tableau_case_tmp[i-1][j+1] == 1))
                        {
                            for(int k= ((x+pm)-compteur+1) ; k>= (((x-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&& k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 4;
                                    }
                                }
                            }
                            for(int k= (((x-2)+pm)-compteur+1) ; k>= (((x-3)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&& k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k= ((x+pm)-compteur+1) ; k>= (((x-1)+pm)-compteur) ; k--)
                            {
                                if((k>0 && k<36)&& k>j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        compteur ++;
        obstacle = 0;
    }

    //y- x-
    compteur = 1;
    obstacle = 0;
    for(int i=y ; i>=(y-pm); i--)
    {
        if(i<17 && i>0)
        {
            for(int j=x ; j>=(((x)-pm)+compteur) ; j--)
            {
                if(j<35 && j>0)
                {
                    if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
                    {
                        obstacle = 1;
                        if((tableau_case_tmp[i+1][j] == 1 || tableau_case_tmp[i+1][i+1] == 1) && (tableau_case_tmp[i-1][j] == 1 || tableau_case_tmp[i-1][j+1] == 1))
                        {
                            for(int k= ((x-pm)+compteur+1) ; k<= (((x+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 4;
                                    }
                                }
                            }
                            for(int k= (((x+2)-pm)+compteur+1) ; k<= (((x+3)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for(int k= ((x-pm)+compteur+1) ; k<= (((x+1)-pm)+compteur) ; k++)
                            {
                                if((k>0 && k<36)&&k<j)
                                {
                                    if(tableau_case_tmp[i][k] != 1)
                                    {
                                        tableau_case_tmp[i][k] = 3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        compteur ++;
        obstacle = 0;
    }
    ///Si obstacle sur la ligne de la position :
    for(int i=x ; i<=(x+pm-2);i++)
    {
        if(i < 36)
        {
            if(tableau_case_tmp[y][i] == 1)
            {
                if(y<17 && y > 0)
                {
                    if(((tableau_case_tmp[y+1][i] == 1 || tableau_case_tmp[y+1][i] == 3) || (tableau_case_tmp[y+1][i+1] == 1 || tableau_case_tmp[y+1][i+1] == 3)) && ((tableau_case_tmp[y+1][i] == 1 || tableau_case_tmp[y+1][i] == 3) || (tableau_case_tmp[y+1][i+1] == 1 || tableau_case_tmp[y+1][i+1] == 3)))
                    {
                        for(int k = x+pm ; k>= x+pm-1 ; k--)
                        {
                            if(k>0 && k>i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                        for(int k = x+pm-2; k>= x+pm-3 ; k--)
                        {
                            if(k>0 && k>i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                    }
                    else
                    {
                        for(int k = x+pm ; k>= x+pm-1 ; k--)
                        {
                            if(k>0 && k>i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=x ; i>=(x-pm+2);i--)
    {
        if(i >-1)
        {
            if(tableau_case_tmp[y][i] == 1)
            {
                if(y<17 && y > 0)
                {
                    if(((tableau_case_tmp[y+1][i] == 1 || tableau_case_tmp[y+1][i] == 3) || (tableau_case_tmp[y+1][i-1] == 1 || tableau_case_tmp[y+1][i-1] == 3)) && ((tableau_case_tmp[y+1][i] == 1 || tableau_case_tmp[y+1][i] == 3) || (tableau_case_tmp[y+1][i-1] == 1 || tableau_case_tmp[y+1][i-1] == 3)))
                    {
                        for(int k = x-pm ; k<= x-pm+1 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                        for(int k = x-pm+2 ; k<= x-pm+3 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                    }
                    else
                    {
                        for(int k = x-pm ; k<= x-pm+1 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[y][k] = 4;
                            }
                        }
                    }
                }

            }
        }
    }
    for(int i=y ; i<=y+pm-2 ; i++)
    {
        if(i < 17)
        {
            if(tableau_case_tmp[i][x] == 1)
            {
                if(x<35 && x>0)
                {
                    if(((tableau_case_tmp[i][x+1] == 1 || tableau_case_tmp[i][x+1] == 3) || (tableau_case_tmp[i+1][x+1] == 1 || tableau_case_tmp[i+1][x+1] == 3)) && ((tableau_case_tmp[i][x-1] == 1 || tableau_case_tmp[i][x-1] == 3) || (tableau_case_tmp[i+1][x-1] == 1 || tableau_case_tmp[i+1][x-1] == 3)))
                    {
                        for(int k = y+pm ; k>= y+pm-1 ; k--)
                        {
                            if(k<18 && k>i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                        for(int k = y+pm-2 ; k>= y+pm-3 ; k--)
                        {
                            if(k<18 && k>i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                    }
                    else
                    {
                        for(int k = y+pm ; k>= y+pm-1 ; k--)
                        {
                            if(k<18 && k>i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=y ; i>=y-pm+2 ; i--)
    {
        if(i > -1)
        {
            if(tableau_case_tmp[i][x] == 1)
            {
                if(x<35 && x>0)
                {
                    if(((tableau_case_tmp[i][x+1] == 1 || tableau_case_tmp[i][x+1] == 3) || (tableau_case_tmp[i-1][x+1] == 1 || tableau_case_tmp[i-1][x+1] == 3)) && ((tableau_case_tmp[i][x-1] == 1 || tableau_case_tmp[i][x-1] == 3) || (tableau_case_tmp[i-1][x-1] == 1 || tableau_case_tmp[i-1][x-1] == 3)))
                    {
                        for(int k = y-pm ; k<= y-pm+1 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                        for(int k = y-pm+2 ; k<= y-pm+3 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                    }
                    else
                    {
                        for(int k = y-pm ; k<= y-pm+1 ; k++)
                        {
                            if(k>0 && k<i)
                            {
                                tableau_case_tmp[k][x] = 4;
                            }
                        }
                    }
                }
            }
        }
    }

    ///On teste les cases cotes à cote
    //ligne x :
    for(int i=x ; i<=x+pm-1;i++)
    {
        if(i>0 && x <35)
        {
            if(y<35 && y>0)
            {
                if(tableau_case_tmp[y+1][i] == 2 && (tableau_case_tmp[y][i] == 0 || tableau_case_tmp[y][i] == 3))
                {
                    tableau_cases[y][i] == 2;
                }
                if(tableau_case_tmp[y-1][i] == 2 && (tableau_case_tmp[y][i] == 0 || tableau_case_tmp[y][i] == 3))
                {
                    tableau_cases[y][i] == 2;
                }
            }
        }
    }
    for(int i=x ; i>=x-pm+1;i--)
    {
        if(i>0 && x <35)
        {
            if(y<17 && y>0)
            {
                if(tableau_case_tmp[y+1][i] == 2 && (tableau_case_tmp[y][i] == 0 || tableau_case_tmp[y][i] == 3))
                {
                    tableau_case_tmp[y][i] =2;
                }
                else if(tableau_case_tmp[y-1][i] == 2 && (tableau_case_tmp[y][i] == 0 || tableau_case_tmp[y][i] == 3))
                {
                    tableau_case_tmp[y][i] = 2;
                }
            }

        }
    }

    //ligne y
    for(int i=y ; i<=y+pm-1 ; i++)
    {
        if(i>0 && i<18)
        {
            if(x>0 && x<35)
            {
                if(tableau_case_tmp[i][x+1] == 2 && (tableau_case_tmp[i][x] == 0 || tableau_case_tmp[i][x] == 3))
            {
                tableau_case_tmp[i][x] = 2;
            }
            else if(tableau_case_tmp[i][x-1] == 2 && (tableau_case_tmp[i][x] == 0 || tableau_case_tmp[i][x] == 3))
            {
                tableau_case_tmp[i][x] = 2;
            }
            }
        }
    }
    for(int i=y ; i>=y-pm+1 ; i--)
    {
        if(i>0 && i<18)
        {
            if(x>0 && x<35)
            {
                if(tableau_case_tmp[i][x+1] == 2 && (tableau_case_tmp[i][x] == 0 || tableau_case_tmp[i][x] == 3))
            {
                tableau_case_tmp[i][x] = 2;
            }
            else if(tableau_case_tmp[i][x-1] == 2 && (tableau_case_tmp[i][x] == 0 || tableau_case_tmp[i][x] == 3))
            {
                tableau_case_tmp[i][x] = 2;
            }
            }
        }
    }

    //y++ x++
    compteur = 1;
    for(int i=y ; i<=y+pm ; i++)
    {
        if(i<17 && i>=0)
        {
            for(int j=x ; j<=(x+pm)-compteur ; j++)
            {
                if(j<36 && j>=0)
                {
                    if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i+1][j] == 0 || tableau_case_tmp[i+1][j] == 3))
                    {
                        tableau_case_tmp[i+1][j] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //y++ x--
    compteur = 1;
    for(int i=y ; i<=y+pm ; i++)
    {
        if(i<17 && i>=0)
        {
            for(int j=x ; j>=(x-pm)+compteur ; j--)
            {
                if(j<36 && j>=0)
                {
                    if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i+1][j] == 0 || tableau_case_tmp[i+1][j] == 3))
                    {
                        tableau_case_tmp[i+1][j] = 2;

                    }
                }
            }
        }
        compteur ++;
    }
    //y-- x++
    compteur = 1;
    for(int i=y ; i>=y-pm ; i--)
    {
        if(i<18& i>0)
        {
            for(int j=x ; j<=(x+pm)-compteur ; j++)
            {
                if(j<36 && j>=0)
                {
                    if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i-1][j] == 0 || tableau_case_tmp[i-1][j] == 3))
                    {
                        tableau_case_tmp[i-1][j] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //y-- x--
    compteur = 1;
    for(int i=y ; i>=y-pm ; i--)
    {
        if(i<17 && i>0)
        {
            for(int j=x ; j>=(x-pm)+compteur ; j--)
            {
                if(j<36&&j>=0)
                {
                    if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i-1][j] == 0 || tableau_case_tmp[i-1][j] == 3))
                    {
                        tableau_case_tmp[i+1][j] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //x++ y++
    compteur = 1;
    for(int i=x ; i<= x+pm ; i++)
    {
        if(i<35 && i>=0)
        {
            for(int j=y ; j<= ((y+pm)-compteur) ; j++)
            {
                if(j<18 && j>=0)
                {
                    if(tableau_case_tmp[j][i] == 2 && (tableau_case_tmp[j][i+1] == 0 || tableau_case_tmp[j][i+1] == 3))
                    {
                        tableau_case_tmp[j][i+1] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //x++ y--
    compteur = 1;
    for(int i=x ; i<= x+pm ; i++)
    {
        if(i<35 && i>=0)
        {
            for(int j=y ; j>= ((y-pm)+compteur) ; j--)
            {
                if(j<18 && j>=0)
                {
                    if(tableau_case_tmp[j][i] == 2 && (tableau_case_tmp[j][i+1] == 0 || tableau_case_tmp[j][i+1] == 3))
                    {
                        tableau_case_tmp[j][i+1] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //x-- y++
    compteur = 1;
    for(int i=x ; i>= x-pm ; i--)
    {
        if(i<=35 && i>0)
        {
            for(int j=y ; j<= ((y+pm)-compteur) ; j++)
            {
                if(j<18 && j>=0)
                {
                    if(tableau_case_tmp[j][i] == 2 && (tableau_case_tmp[j][i-1] == 0 || tableau_case_tmp[j][i-1] == 3))
                    {
                        tableau_case_tmp[j][i-1] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    //x-- y--
    compteur = 1;
    for(int i=x ; i>= x-pm ; i--)
    {
        if(i<=35 && i>0)
        {
            for(int j=y ; j>= ((y-pm)+compteur) ; j--)
            {
                if(j<18 && j>=0)
                {
                    if(tableau_case_tmp[j][i] == 2 && (tableau_case_tmp[j][i-1] == 0 || tableau_case_tmp[j][i-1] == 3))
                    {
                        tableau_case_tmp[j][i-1] = 2;

                    }
                }
            }
        }
        compteur ++;
    }

    ///On met les cases disponibles en bleu

    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {

            if(tableau_case_tmp[i][j] == 2)
            {
                casebleu(buffer,j,i);
            }
        }
    }
}

void afficher_arbre(BITMAP* buffer, int x, int y)
{
    //Déclaration des variables
    BITMAP* arbre = load_bitmap("map/arbre1.bmp",NULL);
    int caseX = 30,caseY = 32,initX = 20;

    //affichage des arbres sur le buffer
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,(caseX*(x-1))+initX,(caseY*(y-1)),arbre->w/5,arbre->h/5);

}

void afficher_tout_arbre(BITMAP* buffer, int matrice_arbre[18][36])
{
    for(int i=0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            if(matrice_arbre[i][j] == 6)
            {
                afficher_arbre(buffer,j,i);
            }
        }
    }
}


void casebleu(BITMAP* buffer, int posx, int posy)
{
    //déclaration des variables
    BITMAP* casefiltre = load_bitmap("map/casefiltre.bmp",NULL);
    int casex = -30, casey = -32;

    //On affiche la bitmap sur le buffer
    blit(casefiltre,buffer,posx * casex,posy * casey,0,0,buffer->w,buffer->h);
    //blit(buffer,screen,0,0,0,0,1200,711);
}

void casebleu_foncee(BITMAP* buffer, int posx, int posy)
{
    //déclaration des variables
    BITMAP* casefiltre_foncee= load_bitmap("map/casefiltrefonce.bmp",NULL);
    int casex = -30, casey = -32;

    //On affiche la bitmap sur le buffer
    blit(casefiltre_foncee,buffer,posx * casex,posy * casey,0,0,buffer->w,buffer->h);
}

void afficher_coordonnees(BITMAP* buffer)
{
    textprintf(buffer,font,150,150,makecol(255,255,255),"x : %d, y : %d",mouse_x/30,mouse_y/32);
}

void afficher_lac(BITMAP* buffer)
{
    BITMAP* lac1=load_bitmap("map/lac1.bmp",NULL);
    BITMAP* lac2=load_bitmap("map/lac2.bmp",NULL);
    BITMAP* lac3=load_bitmap("map/lac3.bmp",NULL);
    BITMAP* lac4=load_bitmap("map/lac4.bmp",NULL);
    BITMAP* lac5=load_bitmap("map/lac5.bmp",NULL);

    int casex = 30;
    int casey = 32;

    blit(lac1,buffer,0,0,casex*0,casey*0,91,97);
    blit(lac2,buffer,0,0,casex*11,casey*6,151,65);
    blit(lac3,buffer,0,0,casex*24,casey*5,91,97);
    blit(lac4,buffer,0,0,casex*0,casey*13,61,129);
    blit(lac5,buffer,0,0,casex*17,casey*13,121,97);

}
