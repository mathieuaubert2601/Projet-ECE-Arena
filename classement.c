#include "header.h"


void classement2J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);

    masked_stretch_blit(joueurG.classe.profil,buffer,0,0,joueurG.classe.profil->w,joueurG.classe.profil->h,400,110,joueurG.classe.profil->w*2,joueurG.classe.profil->h*2);
    textprintf_ex(buffer,maPolice,370,240,makecol(0,0,0),-1,"1er : %s",joueurG.pseudo);
    textprintf_ex(buffer,maPolice,370,285,makecol(0,0,0),-1,"Kills : %d",joueurG.kills);

    textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP1.pseudo);
    textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

    blit(buffer,screen,0,0,0,0,1200,711);

}


void classement3J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);
    masked_stretch_blit(joueurG.classe.profil,buffer,0,0,joueurG.classe.profil->w,joueurG.classe.profil->h,400,110,joueurG.classe.profil->w*2,joueurG.classe.profil->h*2);
    textprintf_ex(buffer,maPolice,370,240,makecol(0,0,0),-1,"1er : %s",joueurG.pseudo);
    textprintf_ex(buffer,maPolice,370,285,makecol(0,0,0),-1,"Kills : %d",joueurG.kills);

    if(joueurP1.kills >= joueurP2.kills)
    {
        textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP1.pseudo);
        textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

        textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP2.pseudo);
        textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);
    }
    else if(joueurP1.kills < joueurP2.kills)
    {
        textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP2.pseudo);
        textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);

        textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP1.pseudo);
        textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);
    }

    blit(buffer,screen,0,0,0,0,1200,711);
}


void classement4J(BITMAP* buffer,t_joueur joueurG, t_joueur joueurP1, t_joueur joueurP2, t_joueur joueurP3)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

    blit(fond,buffer,0,0,0,0,1200,711);
    blit(classement,buffer,0,0,300,50,classement->w,classement->h);
    masked_stretch_blit(joueurG.classe.profil,buffer,0,0,joueurG.classe.profil->w,joueurG.classe.profil->h,400,110,joueurG.classe.profil->w*2,joueurG.classe.profil->h*2);
    textprintf_ex(buffer,maPolice,370,240,makecol(0,0,0),-1,"1er : %s",joueurG.pseudo);
    textprintf_ex(buffer,maPolice,370,285,makecol(0,0,0),-1,"Kills : %d",joueurG.kills);

    if(((joueurP1.kills > joueurP2.kills)&&(joueurP1.kills > joueurP3.kills)) || ((joueurP1.kills == joueurP2.kills) && (joueurP1.degats > joueurP2.degats)) || ((joueurP1.kills == joueurP3.kills) && joueurP1.degats > (joueurP3.degats)))
    {
        textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP1.pseudo);
        textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

        if((joueurP2.kills > joueurP3.kills) || ((joueurP2.kills == joueurP3.kills) && (joueurP2.degats > joueurP3.degats)))
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP2.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP3.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP3.kills);
        }
        else
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP3.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP3.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP2.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);
        }

    }
    else if(((joueurP2.kills > joueurP1.kills)&&(joueurP2.kills > joueurP3.kills)) || ((joueurP1.kills == joueurP2.kills) && (joueurP1.degats < joueurP2.degats)) || ((joueurP2.kills == joueurP3.kills) && (joueurP2.degats > joueurP3.degats)))
    {
        textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP2.pseudo);
        textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);

        if((joueurP1.kills > joueurP3.kills) || ((joueurP1.kills == joueurP3.kills) && (joueurP1.degats > joueurP3.degats)))
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP1.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP3.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP3.kills);
        }
        else
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP3.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP3.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP1.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);
        }
    }
    else if(((joueurP3.kills > joueurP1.kills)&&(joueurP3.kills > joueurP2.kills)) || ((joueurP3.kills == joueurP2.kills) && (joueurP3.degats > joueurP2.degats)) || ((joueurP1.kills == joueurP3.kills) && (joueurP1.degats < joueurP3.degats)))
    {
        textprintf_ex(buffer,maPolice,370,350,makecol(0,0,0),-1,"2e : %s",joueurP3.pseudo);
        textprintf_ex(buffer,maPolice,370,390,makecol(0,0,0),-1,"Kills : %d",joueurP3.kills);

        if((joueurP1.kills > joueurP2.kills) || ((joueurP1.kills == joueurP2.kills) && (joueurP1.degats > joueurP2.degats)))
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP1.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP2.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);
        }
        else
        {
            textprintf_ex(buffer,maPolice,370,455,makecol(0,0,0),-1,"3e : %s",joueurP2.pseudo);
            textprintf_ex(buffer,maPolice,370,495,makecol(0,0,0),-1,"Kills : %d",joueurP2.kills);

            textprintf_ex(buffer,maPolice,370,560,makecol(0,0,0),-1,"4e : %s",joueurP1.pseudo);
            textprintf_ex(buffer,maPolice,370,600,makecol(0,0,0),-1,"Kills : %d",joueurP1.kills);
        }
    }

    blit(buffer,screen,0,0,0,0,1200,711);
}

void classementEquipe(BITMAP* buffer,t_joueur joueurG1, t_joueur joueurG2,t_joueur joueurP1,t_joueur joueurP2)
    {
        FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
        BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
        BITMAP* classement = load_bitmap("fond/classement.bmp",NULL);

        blit(fond,buffer,0,0,0,0,1200,711);
        blit(classement,buffer,0,0,300,50,classement->w,classement->h);


    }

