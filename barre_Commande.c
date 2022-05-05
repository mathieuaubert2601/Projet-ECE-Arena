#include "header.h"

void afficher_commande (BITMAP* buffer, t_joueur* joueur)
{
    FONT* maPolice = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    BITMAP* fondbas = load_bitmap("fondbas.bmp",NULL);
    BITMAP* fondcote = load_bitmap("fondcote.bmp",NULL);

    BITMAP* PA = load_bitmap("PA.bmp",NULL);
    BITMAP* PM = load_bitmap("PM.bmp",NULL);
    BITMAP* PV = load_bitmap("PV.bmp",NULL);

    BITMAP* JoueurS = load_bitmap("JoueurSuivant.bmp",NULL);
    BITMAP* JoueurSInv = load_bitmap("JoueurSuivantInv.bmp",NULL);

    int casex, casey, casex2, casey2;
    casex = -30;
    casey = -32;
    casex2 = 30;
    casey2 = 32;

    blit(fondbas,buffer,0,casey*18,0,0,buffer->w,buffer->h);
    blit(fondcote,buffer,casex*36,0,0,0,buffer->w,buffer->h);

    commande_pokemon(buffer,joueur);

    masked_blit(PA,buffer,casex*5,-600,0,0,buffer->w,buffer->h);
    masked_blit(PM,buffer,casex*5,-660,0,0,buffer->w,buffer->h);
    masked_blit(PV,buffer,casex*2,-620,0,0,buffer->w,buffer->h);
    if ( joueur->pa == 10)
    {
        textprintf_ex(buffer,maPolice,158,604,makecol(255,255,255),-1,"%d",joueur->pa);
    }
    if (joueur->pa<10)
    {
        textprintf_ex(buffer,maPolice,168,604,makecol(255,255,255),-1,"%d",joueur->pa);
    }
    textprintf_ex(buffer,maPolice,168,664,makecol(255,255,255),-1,"%d",joueur->pm);
    if(joueur->pv <100)
    {
        textprintf_ex(buffer,maPolice,74,630,makecol(255,255,255),-1,"%d",joueur->pv);
    }
    if(joueur->pv >= 100)
    {
        textprintf_ex(buffer,maPolice,65,630,makecol(255,255,255),-1,"%d",joueur->pv);
    }

    AffichageBouton(JoueurS,JoueurSInv,buffer,0,0,casex2*37,620,130,115);
}

void commande_pokemon (BITMAP* buffer,t_joueur* joueur)
{
    int casex, casey;
    casex = 30;
    casey = 32;

    AffichageSorts(joueur->classe.sort1.bouton,joueur->classe.sort1.boutonInv,joueur->classe.sort1.infos,buffer,0,0,casex*10,casey*19,75,54,200,80);
    AffichageSorts(joueur->classe.sort2.bouton,joueur->classe.sort2.boutonInv,joueur->classe.sort2.infos,buffer,0,0,casex*14,casey*19,75,54,200,80);
    AffichageSorts(joueur->classe.sort3.bouton,joueur->classe.sort3.boutonInv,joueur->classe.sort3.infos,buffer,0,0,casex*18,casey*19,75,54,200,80);
    AffichageSorts(joueur->classe.sort4.bouton,joueur->classe.sort4.boutonInv,joueur->classe.sort4.infos,buffer,0,0,casex*22,casey*19,75,54,200,80);
    AffichageSorts(joueur->classe.sort5.bouton,joueur->classe.sort5.boutonInv,joueur->classe.sort5.infos,buffer,0,0,casex*26,casey*19,75,54,200,80);
    AffichageSorts(joueur->classe.corps.bouton,joueur->classe.corps.boutonInv,joueur->classe.corps.infos,buffer,0,0,casex*30,casey*19,100,100,200,80);

    masked_stretch_blit(joueur->classe.profilvert,buffer,0,0,50,50,1100,casey*1,90,90);
}

