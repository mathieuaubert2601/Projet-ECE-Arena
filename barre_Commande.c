#include "header.h"

void afficher_commande (BITMAP* buffer,t_joueur tab[],int nbJ, int j)
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

    commande_pokemon(buffer,tab,j);
    affichage_profil(buffer,tab,nbJ,j);

    masked_blit(PA,buffer,casex*5,-600,0,0,buffer->w,buffer->h);
    masked_blit(PM,buffer,casex*5,-660,0,0,buffer->w,buffer->h);
    masked_blit(PV,buffer,casex*2,-620,0,0,buffer->w,buffer->h);
    if ( tab[j].pa == 10)
    {
        textprintf_ex(buffer,maPolice,158,604,makecol(255,255,255),-1,"%d",tab[j].pa);
    }
    if (tab[j].pa<10)
    {
        textprintf_ex(buffer,maPolice,168,604,makecol(255,255,255),-1,"%d",tab[j].pa);
    }
    textprintf_ex(buffer,maPolice,168,664,makecol(255,255,255),-1,"%d",tab[j].pm);
    if(tab[j].pv <100)
    {
        textprintf_ex(buffer,maPolice,74,630,makecol(255,255,255),-1,"%d",tab[j].pv);
    }
    if(tab[j].pv >= 100)
    {
        textprintf_ex(buffer,maPolice,65,630,makecol(255,255,255),-1,"%d",tab[j].pv);
    }

    AffichageBouton(JoueurS,JoueurSInv,buffer,0,0,casex2*37,620,130,115);
}

void commande_pokemon (BITMAP* buffer,t_joueur joueur[],int j)
{
    int casex, casey;
    casex = 30;
    casey = 32;

    AffichageSorts(joueur[j].classe.sort1.bouton,joueur[j].classe.sort1.boutonInv,joueur[j].classe.sort1.infos,buffer,0,0,casex*10,casey*19,75,54,200,80);
    AffichageSorts(joueur[j].classe.sort2.bouton,joueur[j].classe.sort2.boutonInv,joueur[j].classe.sort2.infos,buffer,0,0,casex*14,casey*19,75,54,200,80);
    AffichageSorts(joueur[j].classe.sort3.bouton,joueur[j].classe.sort3.boutonInv,joueur[j].classe.sort3.infos,buffer,0,0,casex*18,casey*19,75,54,200,80);
    AffichageSorts(joueur[j].classe.sort4.bouton,joueur[j].classe.sort4.boutonInv,joueur[j].classe.sort4.infos,buffer,0,0,casex*22,casey*19,75,54,200,80);
    AffichageSorts(joueur[j].classe.sort5.bouton,joueur[j].classe.sort5.boutonInv,joueur[j].classe.sort5.infos,buffer,0,0,casex*26,casey*19,75,54,200,80);
    AffichageSorts(joueur[j].classe.corps.bouton,joueur[j].classe.corps.boutonInv,joueur[j].classe.corps.infos,buffer,0,0,casex*30,casey*19,100,100,200,80);
}

void affichage_profil(BITMAP* buffer,t_joueur tab[], int nbJoueurs,int j)
{

    int casey = 32;
    for (int i=0; i<nbJoueurs; i++)
    {
        if(i==j)
        {
            masked_blit(tab[i].classe.profilvert,buffer,0,0,1100,casey*i*3,90,80);
        }
        else
             masked_blit(tab[i].classe.profil,buffer,0,0,1100,casey*i*3,90,80);
    }
}
