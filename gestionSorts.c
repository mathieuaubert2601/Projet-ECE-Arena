#include "header.h"

void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur* tabJoueurs[], int nombreJoueur, int tourJoueur, BITMAP* page)
{
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* pasZone = load_bitmap("phrases/phraseZoneImpact.bmp",NULL);
    int totalTouche = 0;
    int touche=0;
    if (sort1.type == 1)
    {
        if (joueurA->pa>=sort1.nbrPa)
        {
            while((tourJoueur+1) != (joueurA->numero))
            {
                touche = sortAttaque(sort1,joueurA,tabJoueurs[tourJoueur+1],page);
                totalTouche+=touche;
                tourJoueur++;
                if (tourJoueur == nombreJoueur-1)
                {
                    tourJoueur=0;
                }
            }
            if(totalTouche>=1)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else if (totalTouche<1)
            {
                masked_blit(pasZone,page,0,0,300,300,pasZone->w,pasZone->h);
            }
        }
        else if (joueurA->pa<sort1.nbrPa)
        {
            masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
        }
    }
    if (sort1.type == 2)
    {
        sortMouvement(sort1,joueurA,page);
    }
    if (sort1.type == 3)
    {
        if (joueurA->pa>=sort1.nbrPa)
        {
            while((tourJoueur+1) != (joueurA->numero))
            {
                touche = sortStatut(sort1,joueurA,tabJoueurs[tourJoueur+1],page);
                totalTouche+=touche;
                tourJoueur++;
                if (tourJoueur == nombreJoueur-1)
                {
                    tourJoueur=0;
                }
            }
            if(totalTouche>=1)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else if (totalTouche<1)
            {
                masked_blit(pasZone,page,0,0,300,300,pasZone->w,pasZone->h);
            }
        }
        else if (joueurA->pa<sort1.nbrPa)
        {
            masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
        }
    }
    if (sort1.type == 4)
    {
        sortVie(sort1,joueurA,page);
    }
    if (sort1.numero==20)
    {
        if (joueurA->pa>=sort1.nbrPa)
        {
            while((tourJoueur+1) != (joueurA->numero))
            {
                touche = sortSoin(sort1,joueurA,tabJoueurs[tourJoueur+1],page);
                totalTouche+=touche;
                tourJoueur++;
                if (tourJoueur == nombreJoueur-1)
                {
                    tourJoueur=0;
                }
            }
            if(totalTouche>=1)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else if (totalTouche<1)
            {
                masked_blit(pasZone,page,0,0,300,300,pasZone->w,pasZone->h);
            }
        }
        else if (joueurA->pa<sort1.nbrPa)
        {
            masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
        }
    }
}

int sortAttaque(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page )
{
    int probabilite;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    ///Attaque en zone
    if (sort1.typePortee == 3)
    {
        if (((abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)>=sort1.pMin)&&(abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)<=sort1.pMax)))
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                if (joueurB->tourBouclier==1)
                {
                    return 1;
                }
                else
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv -= nombrePv;
                    if (joueurB->pv <0)
                    {
                        joueurB->pv = 0;
                    }
                }
            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    ///Attaque en ligne droite
    if (sort1.typePortee == 1)
    {
        if ((joueurA->ligne/32==joueurB->ligne/32)
             && ((abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)>=sort1.pMin)
                 &&(abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)<=sort1.pMax))
             || ((joueurA->colonne/30==joueurB->colonne/30)
                  && ((abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)>=sort1.pMin)
                      &&(abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)<=sort1.pMax))))

        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                if (joueurB->tourBouclier==1)
                {
                    return 1;
                }
                else
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv -= nombrePv;
                    if (joueurB->pv <0)
                    {
                        joueurB->pv = 0;
                    }
                }
            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void sortMouvement(t_sorts sort1, t_joueur* joueurA, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite;
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    BITMAP* rouler = load_bitmap("phrases/phraseRouler.bmp",NULL);
    BITMAP* teleporter = load_bitmap("phrases/phraseTeleporter.bmp",NULL);
    BITMAP* deplacer = load_bitmap("phrases/phraseDeplacer.bmp",NULL);
    if(joueurA->pa>=sort1.nbrPa)
    {
        if (sort1.numero==13)
        {
            probabilite=rand() % 100 ;
            if (probabilite<sort1.chance)
            {
                joueurA->tourHate += 3;
            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
            }
            joueurA->pa-=sort1.nbrPa;
        }
        else
        {

            do
            {
                if (mouse_b & 1)
                {
                    caseChoisieColonne = mouse_x/30;
                    caseChoisieLigne = mouse_y/32;
                }
                if(sort1.numero==22)
                {
                    masked_blit(deplacer,page,0,0,300,300,deplacer->w,deplacer->h);
                }
                if(sort1.numero==0)
                {
                    masked_blit(deplacer,page,0,0,300,300,deplacer->w,deplacer->h);
                }
                if(sort1.numero==16)
                {
                    masked_blit(teleporter,page,0,0,300,300,teleporter->w,teleporter->h);
                }
                if(sort1.numero==22)
                {
                    masked_blit(rouler,page,0,0,300,300,rouler->w,rouler->h);
                }
                if (mouse_b & 2)
                {
                    sortie_mouv = 1;
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1200,711);
            }
            while ((((abs((joueurA->ligne)-caseChoisieLigne)+abs((joueurA->colonne)-caseChoisieColonne)>=sort1.pMin)&&(abs((joueurA->ligne)-caseChoisieLigne)+abs((joueurA->colonne)-caseChoisieColonne)<=sort1.pMax)))|| (sortie_mouv != 1));
            if (sortie_mouv == 0)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    joueurA->ligne = caseChoisieLigne;
                    joueurA->colonne = caseChoisieColonne;
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
                }
                joueurA->pa-=sort1.nbrPa;
            }
        }
    }
    else
    {
        masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
    }



}

int sortStatut(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int probabilite;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    if (((abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)>=sort1.pMin)&&(abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)<=sort1.pMax)))

    {
        probabilite=rand() % 100;
        if (probabilite<sort1.chance)
        {
            if (sort1.typeStatus == 1)
            {
                joueurB->tourPoison = 5;
            }
            if (sort1.typeStatus == 2)
            {
                joueurB->tourDodo = 3;
            }
            if (sort1.typeStatus == 3)
            {
                joueurB->tourParalysie = 2;
            }
            if (sort1.typeStatus == 4)
            {
                joueurB->tourPeur = 1;
            }
        }
        else if (probabilite>=sort1.chance)
        {
            masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void sortVie(t_sorts sort1, t_joueur* joueurA, BITMAP* page)
{
    int probabilite,nombrePv;
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    if(joueurA->pa>=sort1.nbrPa)
    {
        if (sort1.typeSoin==1)
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                joueurA->tourBouclier=1;

            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
            }
            joueurA->pa-=sort1.nbrPa;
        }
        if (sort1.typeSoin==2)
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                joueurA->pv+=nombrePv;
                if (joueurA->pv>joueurA->classe.pv)
                {
                    joueurA->pv = joueurA->classe.pv;
                }
            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
            }
            joueurA->pa-=sort1.nbrPa;
        }
    }
    else
    {
        masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
    }

}

int sortSoin(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int probabilite, nombrePv;
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    if(joueurA->pa>=sort1.nbrPa)
    {
        if (joueurB->equipe==joueurA->equipe)
        {
            if (((abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)>=sort1.pMin)&&(abs((joueurA->ligne/32)-joueurB->ligne/32)+abs((joueurA->colonne/30)-joueurB->colonne/30)<=sort1.pMax)))

            {
                probabilite=rand() % 100;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv+=nombrePv;
                    if (joueurB->pv>joueurB->classe.pv)
                    {
                        joueurB->pv = joueurB->classe.pv;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,300,300,rate->w,rate->h);
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        masked_blit(pasPA,page,0,0,300,300,pasPA->w,pasPA->h);
    }

}
