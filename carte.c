#include "header.h"

void afficher_map(BITMAP* buffer)
{
    //d�claration des variables
    BITMAP* carte = load_bitmap("map.bmp",NULL);
    BITMAP* arbre = load_bitmap("arbre1.bmp",NULL);

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
    int compteur = 1;

    //déclaration des points de mouvement temporaires
    int pm_tmp = pm;

    //Copie des information du premier tableau dans le second
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            tableau_case_tmp[i][j] = 1;
            tableau_case_tmp[i][j] = tableau_cases[i][j];
        }
    }



    //Premier test :
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

    pm_tmp = pm;
    compteur = 0;
    //Test intermédiaire obstacle
    for(int i=x ; i <= x+pm ; i++)
    {
        for(int j=y+1 ; j < (y+pm_tmp) - compteur ; j++)
        {
            if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] == 1 && tableau_case_tmp[((y)+pm)- compteur][i] != 1)
                {
                    tableau_case_tmp[((y)+pm)- compteur][i] = 3;
                }
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] != 1 && tableau_case_tmp[((y)+pm)- compteur][i] == 1)
                {
                    tableau_case_tmp[((y-1)+pm)- compteur][i] = 3;
                }
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] != 1 && tableau_case_tmp[((y)+pm)- compteur][i] != 1)
                {
                    tableau_case_tmp[((y-1)+pm)- compteur][i] = 3;
                    tableau_case_tmp[((y)+pm)- compteur][i] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }

    pm_tmp = pm;
    compteur = 0;
    for(int i=x ; i >= x-pm ; i--)
    {
        for(int j=y+1 ; j <(y+pm_tmp) - compteur ; j++)
        {
            if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] == 1 && tableau_case_tmp[((y)+pm)- compteur][i] != 1)
                {
                    tableau_case_tmp[((y)+pm)- compteur][i] = 3;
                }
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] != 1 && tableau_case_tmp[((y)+pm)- compteur][i] == 1)
                {
                    tableau_case_tmp[((y-1)+pm)- compteur][i] = 3;
                }
                if(tableau_case_tmp[((y-1)+pm)- compteur][i] != 1 && tableau_case_tmp[((y)+pm)- compteur][i] != 1)
                {
                    tableau_case_tmp[((y-1)+pm)- compteur][i] = 3;
                    tableau_case_tmp[((y)+pm)- compteur][i] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }

    pm_tmp = pm;
    compteur = 0;
    for(int i=x ; i >= x-pm ; i--)
    {
        for(int j=y-1 ; j > (y-pm_tmp) + compteur ; j--)
        {
            if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] == 1 && tableau_case_tmp[((y)-pm)+ compteur][i] != 1)
                {
                    tableau_case_tmp[((y)-pm)+ compteur][i] = 3;
                }
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] != 1 && tableau_case_tmp[((y)-pm)+ compteur][i] == 1)
                {
                    tableau_case_tmp[((y+1)-pm)+ compteur][i] = 3;
                }
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] != 1 && tableau_case_tmp[((y)-pm)+ compteur][i] != 1)
                {
                    tableau_case_tmp[((y+1)-pm)+ compteur][i] = 3;
                    tableau_case_tmp[((y)-pm)+ compteur][i] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }

    pm_tmp = pm;
    compteur = 0;
    for(int i=x ; i <= x+pm ; i++)
    {
        for(int j=y-1 ; j > (y-pm_tmp) + compteur ; j--)
        {
            if(tableau_case_tmp[j][i] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] == 1 && tableau_case_tmp[((y)-pm)+ compteur][i] != 1)
                {
                    tableau_case_tmp[((y)-pm)+ compteur][i] = 3;
                }
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] != 1 && tableau_case_tmp[((y)-pm)+ compteur][i] == 1)
                {
                    tableau_case_tmp[((y+1)-pm)+ compteur][i] = 3;
                }
                if(tableau_case_tmp[((y+1)-pm)+ compteur][i] != 1 && tableau_case_tmp[((y)-pm)+ compteur][i] != 1)
                {
                    tableau_case_tmp[((y+1)-pm)+ compteur][i] = 3;
                    tableau_case_tmp[((y)-pm)+ compteur][i] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }

    pm_tmp = pm;
    compteur = 0;
    for(int i = y ; i <= y+pm ; i++)
    {
        for(int j = x ; j <= (x+pm_tmp) - compteur; j++)
        {
            if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
            {

                obstacle = 1;
                if(tableau_case_tmp[i][((x)+pm) - compteur] == 1 && tableau_case_tmp[i][((x-1)+pm) - compteur] != 1)
                {
                    tableau_case_tmp[i][((x)+pm) - compteur] = 3;
                }
                if(tableau_case_tmp[i][((x-1)+pm) - compteur] != 1 && tableau_case_tmp[i][((x)+pm) - compteur] == 1)
                {
                    tableau_case_tmp[i][((x-1)+pm) - compteur] = 3;
                }
                if(tableau_case_tmp[i][((x-1)+pm) - compteur] != 1 && tableau_case_tmp[i][((x)+pm) - compteur] != 1)
                {
                    tableau_case_tmp[i][((x-1)+pm) - compteur] = 3;
                    tableau_case_tmp[i][((x)+pm) - compteur] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }
    pm_tmp = pm;
    compteur = 0;
    for(int i = y ; i <= y+pm ; i++)
    {
        for(int j = x ; j >= (x-pm_tmp) + compteur; j--)
        {
            if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[i][((x)-pm) + compteur] == 1 && tableau_case_tmp[i][((x+1)-pm) + compteur] != 1)
                {
                    tableau_case_tmp[i][((x)-pm) + compteur] = 3;
                }
                if(tableau_case_tmp[i][((x+1)-pm)+ compteur] != 1 && tableau_case_tmp[i][((x)-pm) + compteur] == 1)
                {
                    tableau_case_tmp[i][((x+1)-pm) + compteur] = 3;
                }
                if(tableau_case_tmp[i][((x+1)-pm) + compteur] != 1 && tableau_case_tmp[i][((x)-pm) + compteur] != 1)
                {
                    tableau_case_tmp[i][((x+1)-pm) + compteur] = 3;
                    tableau_case_tmp[i][((x)-pm) + compteur] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }
    pm_tmp = pm;
    compteur = 0;
    for(int i = y ; i >= y-pm ; i--)
    {
        for(int j = x ; j <= (x+pm_tmp) - compteur; j++)
        {
            if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[i][((x)+pm) - compteur] == 1 && tableau_case_tmp[i][((x-1)+pm) - compteur] != 1)
                {
                    tableau_case_tmp[i][((x)+pm) - compteur] = 3;
                }
                if(tableau_case_tmp[i][((x-1)+pm) - compteur] != 1 && tableau_case_tmp[i][((x)+pm) - compteur] == 1)
                {
                    tableau_case_tmp[i][((x-1)+pm) - compteur] = 3;
                }
                if(tableau_case_tmp[i][((x-1)+pm) - compteur] != 1 && tableau_case_tmp[i][((x)+pm) - compteur] != 1)
                {
                    tableau_case_tmp[i][((x-1)+pm) - compteur] = 3;
                    tableau_case_tmp[i][((x)+pm) - compteur] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }
    pm_tmp = pm;
    compteur = 0;
    for(int i = y ; i >= y-pm ; i--)
    {
        for(int j = x ; j >= (x-pm_tmp) + compteur; j--)
        {
            if(tableau_case_tmp[i][j] == 1 && obstacle == 0)
            {
                obstacle = 1;
                if(tableau_case_tmp[i][((x)-pm) + compteur] == 1 && tableau_case_tmp[i][((x+1)-pm) + compteur] != 1)
                {
                    tableau_case_tmp[i][((x)-pm) + compteur] = 3;
                }
                if(tableau_case_tmp[i][((x+1)-pm)+ compteur] != 1 && tableau_case_tmp[i][((x)-pm) + compteur] == 1)
                {
                    tableau_case_tmp[i][((x+1)-pm) + compteur] = 3;
                }
                if(tableau_case_tmp[i][((x+1)-pm) + compteur] != 1 && tableau_case_tmp[i][((x)-pm) + compteur] != 1)
                {
                    tableau_case_tmp[i][((x+1)-pm) + compteur] = 3;
                    tableau_case_tmp[i][((x)-pm) + compteur] = 3;
                }
            }
        }
        compteur = compteur + 1;
        obstacle = 0;
        pm_tmp = pm;
    }
    //test case à coté
    compteur = 1;
    for(int i = y ; i <= y+pm ; i++)
    {
        for(int j=x ; j<= (x+pm)-compteur; j++)
        {
            if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i+1][j] == 0 || tableau_case_tmp[i+1][j] == 3))
            {
                tableau_case_tmp[i+1][j] = 2;
            }
        }
        compteur ++;
    }
    compteur = 1;
    for(int i = y ; i <= y+pm ; i++)
    {
        for(int j=x ; j>= (x-pm)+compteur; j--)
        {
            if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i+1][j] == 0 || tableau_case_tmp[i+1][j] == 3))
            {
                tableau_case_tmp[i+1][j] = 2;
            }
        }
        compteur ++;
    }
    compteur = 1;
    for(int i = y ; i >= y-pm ; i--)
    {
        for(int j=x ; j>= (x-pm)+compteur; j--)
        {
            if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i-1][j] == 0 || tableau_case_tmp[i-1][j] == 3))
            {
                tableau_case_tmp[i-1][j] = 2;
            }
        }
        compteur ++;
    }
    compteur = 1;
    for(int i = y ; i >= y-pm ; i--)
    {
        for(int j=x ; j<= (x+pm)-compteur; j++)
        {
            if(tableau_case_tmp[i][j] == 2 && (tableau_case_tmp[i-1][j] == 0 || tableau_case_tmp[i-1][j] == 3))
            {
                tableau_case_tmp[i-1][j] = 2;
            }
        }
        compteur ++;
    }

    //test case cote 2
    compteur = 1;
    for(int colonne = x ; colonne <= x+pm ; colonne ++)
    {
        for(int ligne= y ; ligne<= (y+pm) - compteur ; ligne ++)
        {
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne + 1] == 0)
            {
                tableau_case_tmp[ligne][colonne + 1] = 2;
                casebleu(buffer,colonne +1, ligne);
            }
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne + 1] == 3)
            {
                tableau_case_tmp[ligne][colonne + 1] = 2;
                casebleu(buffer,colonne +1, ligne);
            }
        }
        compteur ++;
    }
    compteur = 1;
    for(int colonne = x ; colonne <= x+pm ; colonne ++)
    {
        for(int ligne = y ; ligne>= (y-pm) + compteur ; ligne --)
        {
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne + 1] == 0)
            {
                tableau_case_tmp[ligne][colonne + 1] = 2;
                casebleu(buffer,colonne +1, ligne);
            }
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne + 1] == 3)
            {
                tableau_case_tmp[ligne][colonne + 1] = 2;
                casebleu(buffer,colonne +1, ligne);
            }
        }
        compteur ++;
    }

    compteur = 1;
    for(int colonne = x ; colonne >= x-pm ; colonne --)
    {
        for(int ligne = y ; ligne>= (y-pm) + compteur ; ligne --)
        {
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne - 1] == 0)
            {
                tableau_case_tmp[ligne][colonne - 1] = 2;
                casebleu(buffer,colonne -1, ligne);
            }
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne - 1] == 3)
            {
                tableau_case_tmp[ligne][colonne - 1] = 2;
                casebleu(buffer,colonne -1, ligne);
            }
        }
        compteur ++;
    }

    compteur = 1;
    for(int colonne = x ; colonne >= x-pm ; colonne --)
    {
        for(int ligne = y ; ligne<= (y+pm) - compteur ; ligne ++)
        {
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne - 1] == 0)
            {
                tableau_case_tmp[ligne][colonne - 1] = 2;
                casebleu(buffer,colonne -1, ligne);
            }
            if(tableau_case_tmp[ligne][colonne] == 2 && tableau_case_tmp[ligne][colonne - 1] == 3)
            {
                tableau_case_tmp[ligne][colonne - 1] = 2;
                casebleu(buffer,colonne -1, ligne);
            }
        }
        compteur ++;
    }




    //deuxième test
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            if(tableau_case_tmp[i][j] == 2)
            {
                if(tableau_case_tmp[i][j+1] != 2 && tableau_case_tmp[i][j-1] != 2 && tableau_case_tmp[i+1][j] != 2 && tableau_case_tmp[i-1][j] != 2)
                {
                    tableau_case_tmp[i][j] = 1;
                }
            }
        }
    }

    //On met les cases disponibles en bleu
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            if(tableau_cases[i][j] != 1)
            {
                if(tableau_case_tmp[i][j] == 2)
                {
                    casebleu(buffer,j,i);
                }

            }


        }
    }
}

void afficher_arbre(BITMAP* buffer, int x, int y)
{
    //Déclaration des variables
    BITMAP* arbre = load_bitmap("arbre1.bmp",NULL);
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
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    int casex = -30, casey = -32;

    //On affiche la bitmap sur le buffer
    blit(casefiltre,buffer,posx * casex,posy * casey,0,0,buffer->w,buffer->h);
    //blit(buffer,screen,0,0,0,0,1200,711);
}

void casebleu_foncee(BITMAP* buffer, int posx, int posy)
{
    //déclaration des variables
    BITMAP* casefiltre_foncee= load_bitmap("casefiltrefonce.bmp",NULL);
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
    BITMAP* lac1=load_bitmap("lac1.bmp",NULL);
    BITMAP* lac2=load_bitmap("lac2.bmp",NULL);
    BITMAP* lac3=load_bitmap("lac3.bmp",NULL);
    BITMAP* lac4=load_bitmap("lac4.bmp",NULL);
    BITMAP* lac5=load_bitmap("lac5.bmp",NULL);

    int casex = 30;
    int casey = 32;

    blit(lac1,buffer,0,0,casex*0,casey*0,91,97);
    blit(lac2,buffer,0,0,casex*11,casey*6,151,65);
    blit(lac3,buffer,0,0,casex*24,casey*5,91,97);
    blit(lac4,buffer,0,0,casex*0,casey*13,61,129);
    blit(lac5,buffer,0,0,casex*17,casey*13,121,97);

}
