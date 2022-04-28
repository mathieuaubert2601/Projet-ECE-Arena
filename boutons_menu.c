#include "header.h"

void AffichageBouton(BITMAP* page,int posx,int posy,int posx2,int posy2,int couleur)
{

    if((mouse_x<=(posx2) && mouse_x>=(posx)) && (mouse_y)<=(posy2) && mouse_y>=(posy))
    {
        couleur = makecol(128,128,128);
        rectfill(page, posx, posy, posx2, posy2, couleur);
    }
    else
        rectfill(page, posx, posy, posx2, posy2, couleur);
}
