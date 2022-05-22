#include "header.h"

void menuJeu(BITMAP* page, BITMAP* fond,BITMAP* logo)
{
    BITMAP* jouer=load_bitmap("boutons/boutonJouer.bmp",NULL);
    BITMAP* invJouer=load_bitmap("boutons/boutonInvJouer.bmp",NULL);


    blit(fond,page,0,0,0,0,1200,711);
    masked_blit(logo,page,0,0,200,50,755,374);
    AffichageBouton(jouer,invJouer,page,0,0,375,500,444,156);
}

int menuFin (BITMAP* page)
{
    int sortie = 0;
    BITMAP* fond = load_bitmap("fond/fondflou.bmp", NULL);
    BITMAP* rejouer = load_bitmap("boutons/rejouer.bmp", NULL);
    BITMAP* rejouerInv = load_bitmap("boutons/rejouerInv.bmp", NULL);
    BITMAP* nvl = load_bitmap("boutons/nvlPartie.bmp", NULL);
    BITMAP* nvlInv = load_bitmap("boutons/nvlPartieInv.bmp", NULL);
    BITMAP* quitter = load_bitmap("boutons/quitter.bmp", NULL);
    BITMAP* quitterInv = load_bitmap("boutons/quitterInv.bmp", NULL);


    while (sortie==0)
    {
        blit(fond,page,0,0,0,0,1200,711);

        AffichageBouton(rejouer,rejouerInv,page,0,0,400,100,350,125);
        AffichageBouton(nvl,nvlInv,page,0,0,400,300,350,125);
        AffichageBouton(quitter,quitterInv,page,0,0,400,500,350,125);

        if(((mouse_x>=(400)&& mouse_x<=(400+350))&& (mouse_y)>=(100)&& mouse_y<=(100+125))&&(mouse_b & 1))
        {
            return 1;
        }
        if(((mouse_x>=(400)&& mouse_x<=(400+350))&& (mouse_y)>=(300)&& mouse_y<=(300+125))&&(mouse_b & 1))
        {
            return 2;
        }
        if(((mouse_x>=(400)&& mouse_x<=(400+350))&& (mouse_y)>=(500)&& mouse_y<=(500+125))&&(mouse_b & 1))
        {
            return 3;
        }

        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);

    }
}
