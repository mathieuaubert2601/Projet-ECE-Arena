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
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<36;j++)
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

void afficher_cases_dispo_joueur(BITMAP* buffer,int x,int y , int pm,int tableau_cases[18][36])
{
    //déclaration des variables
    int soustractionX, soustractionY, additionF, pm_tmp1 = pm,pm_tmp_Bas = pm,pm_tmp_Haut = pm,obstacle1 = 0,obstacle2 = 0,compteur = 1,change = 1;
    int pm_tmp_Bas1 = pm, pm_tmp_Haut1 = pm;
    int tableau_case_bleu[18][36];
    for(int i = 0 ; i<18 ; i++)
    {
        for(int j=0 ; j<36 ; j++)
        {
            tableau_case_bleu[i][j] = tableau_cases[i][j];
        }
    }

    for(int i = y ; i < y+pm ; i++)
    {
        if(tableau_cases[i][x] == 1 && obstacle2 == 0)
        {
            pm_tmp_Bas = pm_tmp_Bas - 2;
            obstacle2 = 1;
            tableau_case_bleu[y+pm][x] = 3;
            tableau_case_bleu[y+pm-1][x] = 3;
            tableau_case_bleu[y+pm][x+1] = 3;
            tableau_case_bleu[y+pm][x-1] = 3;
        }
    }
    for(int i = y ; i > y-pm ; i--)
    {
        if(tableau_cases[i][x] == 1 && obstacle2 == 0)
        {
            pm_tmp_Haut = pm_tmp_Haut- 2;
            obstacle2 = 1;
            tableau_case_bleu[y-pm][x] = 3;
            tableau_case_bleu[y+pm+1][x] = 3;
        }
    }


    //Boucle qui met en place les chemins possibles
    for(int i = y ; i<=y+pm_tmp_Bas ; i++)
    {

        for(int j=x ; j>=x-pm ; j--)
        {

            //allegro_message("x : %d, y : %d, obstacle : %d, valTab : %d",j,i,obstacle1,tableau_cases[i][j]);
            if(tableau_cases[i][j] == 1 && obstacle1 == 0)
            {
                obstacle1 = 1;
                pm_tmp1 = pm_tmp1 - 2;
            }
            soustractionX = abs(x - j);
            soustractionY = abs(y - i);
            additionF = soustractionX + soustractionY;
            if((additionF <= pm_tmp1) && (tableau_cases[i][j] == 0))
            {
                tableau_case_bleu[i][j] = 2;
                casebleu(buffer,j,i);
            }
        }
        pm_tmp1 = pm;
        obstacle1 = 0;
    }
    for(int i = y ; i<=y+pm_tmp_Bas ; i++)
    {

        for(int j=x ; j<=x+pm ; j++)
        {


            if(tableau_cases[i][j] == 1 && obstacle1 == 0)
            {
                obstacle1 = 1;
                pm_tmp1 = pm_tmp1 - 2;
            }
            soustractionX = abs(x - j);
            soustractionY = abs(y - i);
            additionF = soustractionX + soustractionY;
            if((additionF <= pm_tmp1) && (tableau_cases[i][j] == 0))
            {
                tableau_case_bleu[i][j] = 2;
                casebleu(buffer,j,i);
                //allegro_message("x : %d, y : %d, bleu : %d, valTab : %d",j,i,tableau_case_bleu[i][j],tableau_cases[i][j]);
            }

        }
        pm_tmp1 = pm;
        obstacle1 = 0;
    }
    for(int i = y ; i>=y-pm_tmp_Haut ; i--)
    {

        for(int j=x ; j<=x+pm ; j++)
        {

            //allegro_message("x : %d, y : %d, obstacle : %d, valTab : %d",j,i,obstacle1,tableau_cases[i][j]);
            if(tableau_cases[i][j] == 1 && obstacle1 == 0)
            {
                obstacle1 = 1;
                pm_tmp1 = pm_tmp1 - 2;
            }
            soustractionX = abs(x - j);
            soustractionY = abs(y - i);
            additionF = soustractionX + soustractionY;
            if((additionF <= pm_tmp1) && (tableau_cases[i][j] == 0))
            {
                tableau_case_bleu[i][j] = 2;
                casebleu(buffer,j,i);
            }
        }
        pm_tmp1 = pm;
        obstacle1 = 0;
    }
    for(int i = y ; i>=y-pm_tmp_Haut ; i--)
    {

        for(int j=x ; j>=x-pm ; j--)
        {

            //allegro_message("x : %d, y : %d, obstacle : %d, valTab : %d",j,i,obstacle1,tableau_cases[i][j]);
            if(tableau_cases[i][j] == 1 && obstacle1 == 0)
            {
                obstacle1 = 1;
                pm_tmp1 = pm_tmp1 - 2;
            }
            soustractionX = abs(x - j);
            soustractionY = abs(y - i);
            additionF = soustractionX + soustractionY;
            if((additionF <= pm_tmp1) && (tableau_cases[i][j] == 0))
            {
                tableau_case_bleu[i][j] = 2;
                casebleu(buffer,j,i);
            }
        }
        pm_tmp1 = pm;
        obstacle1 = 0;
    }

    //Second test
    while(change == 1)
    {
        change = 0;
        compteur = 1;
        for(int i = y ; i <= (y+pm_tmp_Bas) ; i++)
        {

            for(int j = x ; j<=(x+pm)-(compteur) ; j++)
            {
               // allegro_message("x : %d, y : %d, obstacle : %d, valTab i+1 j : %d, valTabB i j %d",j,i,obstacle1,tableau_cases[i+1][j],tableau_case_bleu[i][j]);
                if(tableau_case_bleu[i][j] == 2 && tableau_cases[i+1][j] == 0 && tableau_case_bleu[i+1][j] != 3)
                {
                    casebleu(buffer,j,i+1);
                    tableau_case_bleu[i][j] = 4;
                    tableau_case_bleu[i+1][j] = 2;
                    change = 1;
                }
            }
            compteur ++;

        }
        compteur = 1;
        for(int i = y ; i <= (y+pm_tmp_Bas) ; i++)
        {
            for(int j = x ; j>=(x-pm)+(compteur) ; j--)
            {

                if(tableau_case_bleu[i][j] == 2 && tableau_cases[i+1][j] == 0 && tableau_case_bleu[i+1][j] != 3)
                {
                    casebleu(buffer,j,i+1);
                    tableau_case_bleu[i][j] = 4;
                    tableau_case_bleu[i+1][j] = 2;
                    change = 1;
                }
            }
            compteur ++;
        }
        compteur = 1;
        for(int i = y ; i >= (y-pm_tmp_Haut) ; i--)
        {
            for(int j = x ; j<=(x+pm)-(compteur) ; j++)
            {
                if(tableau_case_bleu[i][j] == 2 && tableau_cases[i-1][j] == 0 && tableau_case_bleu[i-1][j] != 3)
                {
                    casebleu(buffer,j,i-1);
                    tableau_case_bleu[i][j] = 4;
                    tableau_case_bleu[i-1][j] = 2;
                    change = 1;
                }
            }
            compteur ++;
        }
        compteur = 1;
        for(int i = y ; i >=(y-pm_tmp_Haut) ; i--)
        {
            for(int j = x ; j>=(x-pm)+(compteur) ; j--)
            {
                if(tableau_case_bleu[i][j] == 2 && tableau_cases[i-1][j] == 0 && tableau_case_bleu[i-1][j] != 3)
                {
                    casebleu(buffer,j,i-1);
                    tableau_case_bleu[i][j] = 4;
                    tableau_case_bleu[i-1][j] = 2;
                    change = 1;
                }
            }
            compteur ++;
        }
    }


}
void afficher_arbre(BITMAP* buffer)
{
    //Déclaration des variables
    BITMAP* arbre = load_bitmap("arbre1.bmp",NULL);

    //affichage des arbres sur le buffer
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,53,195,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,50,390,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,500,160,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,318,385,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,1008,35,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,890,480,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,770,225,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,318,0,arbre->w/5,arbre->h/5);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,623,385,arbre->w/5,arbre->h/5);

    show_mouse(buffer);
}


void casebleu(BITMAP* buffer, int posx, int posy)
{
    //déclaration des variables
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    int casex = -30, casey = -32;

    //On affiche la bitmap sur le buffer
    blit(casefiltre,buffer,posx * casex,posy * casey,0,0,buffer->w,buffer->h);
    blit(buffer,screen,0,0,0,0,1200,711);
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
