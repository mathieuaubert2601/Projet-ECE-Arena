#include "header.h"

void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur))
    {
        masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);

    }
    else
        masked_blit(bouton,page,sourcex,sourcey,destx,desty,longueur,hauteur);
}

void AffichageSorts(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur,int hauteur,int longueurinfos,int hauteurinfos)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur))
    {
        masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);
        masked_blit(infos,page,sourcex,sourcey,destx-50,desty+40,longueurinfos,hauteurinfos);
    }
    else
        masked_blit(bouton,page,sourcex,sourcey,destx,desty,longueur,hauteur);
}

void AffichageSorts2(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur,int hauteur,int longueurinfos,int hauteurinfos)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur))
    {
        masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);
        masked_blit(infos,page,sourcex,sourcey,destx+80,desty,longueurinfos,hauteurinfos);
    }
    else
        masked_blit(bouton,page,sourcex,sourcey,destx,desty,longueur,hauteur);
}

void phrases(BITMAP* page,int p)
{
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    BITMAP* barreBasRouge = load_bitmap("fond/barreBasRouge.bmp",NULL);
    BITMAP* barreCoteRouge = load_bitmap("fond/barreCoteRouge.bmp",NULL);

    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* deplacer = load_bitmap("phrases/phraseDeplacer.bmp",NULL);
    BITMAP* teleporter = load_bitmap("phrases/phraseTeleporter.bmp",NULL);
    BITMAP* rouler = load_bitmap("phrases/phraseRouler.bmp",NULL);
    BITMAP* zoneImpact = load_bitmap("phrases/phraseZoneImpact.bmp",NULL);
    BITMAP* nom = load_bitmap("phrases/phraseNom.bmp",NULL);
    BITMAP* allieSoin = load_bitmap("phrases/phraseAllieSoin.bmp",NULL);
    BITMAP* memeEquipe = load_bitmap("phrases/phraseMemeEquipe.bmp",NULL);
    BITMAP* pasMemeEquipe = load_bitmap("phrases/phrasePasMemeEquipe.bmp",NULL);

    BITMAP* endormi = load_bitmap("phrases/phraseEndormi.bmp",NULL);
    BITMAP* paralyse = load_bitmap("phrases/phraseParalyse.bmp",NULL);
    BITMAP* apeure = load_bitmap("phrases/phraseApeure.bmp",NULL);
    BITMAP* protege = load_bitmap("phrases/phraseProtege.bmp",NULL);
    BITMAP* empoisonne = load_bitmap("phrases/phraseEmpoisonne.bmp",NULL);

    if(p==1)
    {
        masked_blit(rate,page,0,0,300,100,rate->w,rate->h);
        blit(barreCoteRouge,page,0,0,1060,0,barreCoteRouge->w,barreCoteRouge->h);
        blit(barreBasRouge,page,0,0,0,576,barreBasRouge->w,barreBasRouge->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==2)
    {
        masked_blit(pasPA,page,0,0,150,300,pasPA->w,pasPA->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==3)
    {
        masked_blit(deplacer,page,0,0,150,300,deplacer->w,deplacer->h);
        blit(page,screen,0,0,0,0,1200,711);
    }
    if(p==4)
    {
        masked_blit(teleporter,page,0,0,150,300,teleporter->w,teleporter->h);
        blit(page,screen,0,0,0,0,1200,711);
    }
    if(p==5)
    {
        masked_blit(rouler,page,0,0,150,300,rouler->w,rouler->h);
        blit(page,screen,0,0,0,0,1200,711);
    }
    if(p==6)
    {
        masked_blit(endormi,page,0,0,150,300,endormi->w,endormi->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==7)
    {
        masked_blit(paralyse,page,0,0,150,300,paralyse->w,paralyse->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==8)
    {
        masked_blit(apeure,page,0,0,150,300,apeure->w,apeure->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==9)
    {
        masked_blit(protege,page,0,0,150,300,protege->w,protege->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==10)
    {
        masked_blit(empoisonne,page,0,0,150,300,empoisonne->w,empoisonne->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==11)
    {
        masked_blit(memeEquipe,page,0,0,150,300,memeEquipe->w,memeEquipe->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
    if(p==12)
    {
        masked_blit(pasMemeEquipe,page,0,0,150,300,pasMemeEquipe->w,pasMemeEquipe->h);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}
