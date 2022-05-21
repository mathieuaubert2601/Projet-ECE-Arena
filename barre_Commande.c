#include "header.h"

void afficher_commande (BITMAP* buffer,t_joueur tab[],int nbJ, int j)
{
    FONT* maPolice = load_font("police_ecriture/calibri.pcx",NULL,NULL);

    BITMAP* casefiltre = load_bitmap("casefiltre.bmp",NULL);
    BITMAP* fondbas = load_bitmap("fond/fondbas.bmp",NULL);
    BITMAP* fondcote = load_bitmap("fond/fondcote.bmp",NULL);

    BITMAP* PA = load_bitmap("boutons/PA.bmp",NULL);
    BITMAP* PM = load_bitmap("boutons/PM.bmp",NULL);
    BITMAP* PV = load_bitmap("boutons/PV.bmp",NULL);

    BITMAP* JoueurS = load_bitmap("boutons/JoueurSuivant.bmp",NULL);
    BITMAP* JoueurSInv = load_bitmap("boutons/JoueurSuivantInv.bmp",NULL);

    BITMAP* fond = load_bitmap("fond/fondflou",NULL);
    BITMAP* menu = load_bitmap("boutons/Menu.bmp",NULL);
    BITMAP* menuInv = load_bitmap("boutons/MenuInv.bmp",NULL);

    int casex, casey, casex2, casey2;
    casex = -30;
    casey = -32;
    casex2 = 30;
    casey2 = 32;


    blit(fondbas,buffer,0,casey*18,0,0,buffer->w,buffer->h);
    blit(fondcote,buffer,casex*36,0,0,0,buffer->w,buffer->h);

    commande_pokemon(buffer,tab,j);
    affichage_profil(buffer,tab,nbJ,j);

    masked_blit(PA,buffer,casex*3,-600,0,0,buffer->w,buffer->h);
    masked_blit(PM,buffer,casex*3,-660,0,0,buffer->w,buffer->h);
    masked_blit(PV,buffer,-15,-620,0,0,buffer->w,buffer->h);
    if ( tab[j].pa == 10)
    {
        textprintf_ex(buffer,maPolice,101,575,makecol(255,255,255),-1,"%d",tab[j].pa);
    }
    if (tab[j].pa<10)
    {
        textprintf_ex(buffer,maPolice,105,580,makecol(255,255,255),-1,"%d",tab[j].pa);
    }
    textprintf_ex(buffer,maPolice,105,633,makecol(255,255,255),-1,"%d",tab[j].pm);
    if(tab[j].pv <100)
    {
        textprintf_ex(buffer,maPolice,23,600,makecol(255,255,255),-1,"%d",tab[j].pv);
    }
    if(tab[j].pv >= 100)
    {
        textprintf_ex(buffer,maPolice,20,600,makecol(255,255,255),-1,"%d",tab[j].pv);
    }

    AffichageBouton(JoueurS,JoueurSInv,buffer,0,0,casex2*37,640,130,115);
    AffichageBouton(menu,menuInv,buffer,0,0,1100,0,90,70);
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
    FONT* ecrit = load_font("police_ecriture/police_pv_petite.pcx",NULL,NULL);

    int casey = 32;
    for (int i=0; i<nbJoueurs; i++)
    {
        if(i==j)
        {
            masked_blit(tab[i].classe.profilvert,buffer,0,0,1105,casey*i*4+90,90,80);
            textprintf_ex(buffer,ecrit,1105,casey*i*4+170,makecol(34,177,76),-1,"PV : %d",tab[i].pv);
            textprintf_ex(buffer,ecrit,1105,casey*i*4+190,makecol(34,177,76),-1,"%s",tab[i].pseudo);
        }
        else
        {
            masked_blit(tab[i].classe.profil,buffer,0,0,1105,casey*i*4+90,90,80);
            textprintf_ex(buffer,ecrit,1105,casey*i*4+170,makecol(34,177,76),-1,"PV : %d",tab[i].pv);
            textprintf_ex(buffer,ecrit,1105,casey*i*4+190,makecol(34,177,76),-1,"%s",tab[i].pseudo);
        }
    }
}

void affichage_barres(BITMAP* buffer)
{
    int casex, casey;
    casex = -30;
    casey = -32;

    BITMAP* fondbas = load_bitmap("fond/fondbas.bmp",NULL);
    BITMAP* fondcote = load_bitmap("fond/fondcote.bmp",NULL);

    blit(fondbas,buffer,0,casey*18,0,0,buffer->w,buffer->h);
    blit(fondcote,buffer,casex*36,0,0,0,buffer->w,buffer->h);
}

void demande_placement (BITMAP* buffer, t_joueur* joueur,int tab[18][36], int tab_arbres[18][36])
{
    FONT* maPolice = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    int test4=0;
    int clic=0;
    int testclic=0;

    int m,n;

    BITMAP* confirmer = load_bitmap("boutons/Confirmer.bmp",NULL);
    BITMAP* confirmerInv = load_bitmap("boutons/ConfirmerInv.bmp",NULL);

    int casex, casey;
    casex = 30;
    casey = 32;

    while (test4!=1)
    {
        afficher_map(buffer);
        afficher_tout_arbre(buffer,tab_arbres);
        affichage_barres(buffer);
        textprintf_ex(buffer,maPolice,casex*7,casey*18,makecol(0,0,0),-1,"%s", joueur->pseudo);
        textprintf_ex(buffer,maPolice,casex*4,casey*19,makecol(0,0,0),-1,"Choisit ton placement !");
        AffichageBouton(confirmer,confirmerInv,buffer,0,0,casex*21,casey*19,200,70);
        clic=0;
        while(clic!=1)
        {
            show_mouse(buffer);
            blit(buffer,screen,0,0,0,0,1200,711);
            if(((mouse_x>=(0)&& mouse_x<=(1080))&& ((mouse_y)>=(0)&& mouse_y<=(576)))&&(tab[mouse_y/32][mouse_x/30]==0)&&(mouse_b&&1))
            {
                testclic=1;
                m=mouse_x;
                n=mouse_y;
                m=m/30;
                n=n/32;
                casebleu(buffer,m,n);
                joueur->colonne=m*30;
                joueur->ligne=n*32;
            }
            if(testclic==1)
                casebleu(buffer,m,n);
            clic=1;
        }
        if((mouse_x>=(casex*21)&& mouse_x<=(casex*21+200))&& ((mouse_y)>=(casey*19)&& mouse_y<=(casey*19+70))&&(mouse_b &&1))
        {
            test4=1;
        }
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,1200,711);
    }
}

