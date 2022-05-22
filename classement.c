#include "header.h"


void classement2J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);

    textprintf_ex(buffer,maPolice,380,40,makecol(0,0,0),-1,"GAGNANT");
    masked_stretch_blit(joueurG.classe.profil,buffer,0,0,joueurG.classe.profil->w,joueurG.classe.profil->h,400,110,joueurG.classe.profil->w*2,joueurG.classe.profil->h*2);
    textprintf_ex(buffer,maPolice,430,240,makecol(0,0,0),-1,"%s",joueurG.pseudo);
    textprintf_ex(buffer,maPolice,380,270,makecol(0,0,0),-1,"Kills : %d",joueurG.kills);

    textprintf_ex(buffer,maPolice,380,330,makecol(0,0,0),-1,"2e : %s",joueurP1.pseudo);
    textprintf_ex(buffer,maPolice,380,370,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

    blit(buffer,screen,0,0,0,0,1200,711);

}


void classement3J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2)
{
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);

    blit(buffer,screen,0,0,0,0,1200,711);
}


void classement4J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2, t_joueur joueurP3)
{
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);

    blit(buffer,screen,0,0,0,0,1200,711);
}
