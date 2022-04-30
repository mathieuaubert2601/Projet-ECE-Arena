#include "header.h"

void afficher_map(BITMAP* buffer)
{
    BITMAP* carte = load_bitmap("map.bmp",NULL);
    BITMAP* arbre = load_bitmap("arbre.bmp",NULL);

    stretch_blit(carte,buffer,0,0,carte->w,carte->h,0,0,1200,800);
    masked_stretch_blit(arbre,buffer,0,0,arbre->w,arbre->h,45,150,arbre->w/2.1,arbre->h/2.1);
    show_mouse(buffer);
    //textprintf(buffer,font,150,150,makecol(255,255,255),"x : %d, y : %d",mouse_x/30,mouse_y/32);
    blit(buffer,screen,0,0,0,0,1200,800);
}
