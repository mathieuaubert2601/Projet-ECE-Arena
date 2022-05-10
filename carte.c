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
    //int tableau_case_tmp[18][36];
    int tableau_case_tmp[18][36] ;

    //Copie des information du premier tableau dans le second
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {
            tableau_case_tmp[i][j] = tableau_cases[i][j];

        }

    }

    //On met la case sur laquelle on est à 2
    tableau_case_tmp[y][x] = 2;

    for(int i= 2; i<pm+2 ; i++)
    {
        for(int colonne=0 ; colonne<36 ; colonne++)
        {
            for(int ligne = 0; ligne <18 ; ligne ++)
            {
                if(tableau_case_tmp[ligne][colonne] == i)
                {
                    if(ligne > 0 && tableau_case_tmp[ligne - 1][colonne] == 0)
                    {
                        tableau_case_tmp[ligne - 1][colonne] = i+1;
                    }
                    if(ligne<17 && tableau_case_tmp[ligne + 1][colonne] == 0 )
                    {
                        tableau_case_tmp[ligne + 1][colonne] = i+1;
                    }
                    if(colonne > 0 && tableau_case_tmp[ligne][colonne-1] == 0)
                    {
                        tableau_case_tmp[ligne][colonne-1] = i+1;
                    }
                    if(colonne < 35 && tableau_case_tmp[ligne][colonne+1] == 0)
                    {
                        tableau_case_tmp[ligne][colonne+1] = i+1;
                    }
                }
            }
        }
    }



    //On met les cases disponibles en bleu
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j = 0 ; j<36 ; j++)
        {

            if(tableau_case_tmp[i][j] != 1 && tableau_case_tmp[i][j] != 0)
            {
                casebleu(buffer,j,i);
            }
        }
    }
    //On met la case sur laquelle on est en bleu foncé
    casebleu_foncee(buffer,x,y);
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
