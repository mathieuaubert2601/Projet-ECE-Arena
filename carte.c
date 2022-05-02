#include "header.h"

void afficher_map(BITMAP* buffer)
{
    //déclaration des variables
    BITMAP* carte = load_bitmap("map.bmp",NULL);
    BITMAP* arbre = load_bitmap("arbre1.bmp",NULL);

    //affichage de la carte sur le buffer
    blit(carte,buffer,0,0,0,0,buffer->w,buffer->h);
}

void afficher_arbre(BITMAP* buffer)
{
    //Déclaration des variables
    BITMAP* arbre = load_bitmap("arbre1.bmp",NULL);
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);

    int casex, casey;
    casex = -30;
    casey = -32;

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

    casebleu(casefiltre,buffer,casex*0,casey*4);
    casebleu(casefiltre,buffer,casex*1,casey*4);
    casebleu(casefiltre,buffer,casex*2,casey*4);
    casebleu(casefiltre,buffer,casex*3,casey*4);

    show_mouse(buffer);
}

void afficher_coordonnees(BITMAP* buffer)
{
    textprintf(buffer,font,150,150,makecol(255,255,255),"x : %d, y : %d",mouse_x/30,mouse_y/32);
}

void casebleu(BITMAP* casefiltre,BITMAP* buffer, int posx, int posy)
{
    blit(casefiltre,buffer,posx,posy,0,0,buffer->w,buffer->h);
}
