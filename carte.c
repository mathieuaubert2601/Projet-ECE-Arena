#include "header.h"

void afficher_map(BITMAP* buffer)
{
    //déclaration des variables
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
                casebleu(buffer,j,i);
            }
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
}
