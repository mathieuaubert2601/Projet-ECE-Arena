#include "header.h"

void menuJeu(BITMAP* page, BITMAP* fond,BITMAP* logo)
{
    BITMAP* jouer=load_bitmap("boutons/boutonJouer.bmp",NULL);
    BITMAP* invJouer=load_bitmap("boutons/boutonInvJouer.bmp",NULL);


    blit(fond,page,0,0,0,0,1200,711);
    masked_blit(logo,page,0,0,200,50,755,374);
    AffichageBouton(jouer,invJouer,page,0,0,375,500,444,156);
}
