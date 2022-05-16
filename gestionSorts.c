#include "header.h"

void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur* tabJoueurs[], int nombreJoueur, int tourJoueur, BITMAP* page, int tab[18][36])
{
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* pasZone = load_bitmap("phrases/phraseZoneImpact.bmp",NULL);
    int totalTouche = 0;
    int touche=0;
    if (sort1.type == 1)
    {
        sortAttaque(sort1,joueurA,tab,tourJoueur,page, nombreJoueur);
    }
    if (sort1.type == 2)
    {
        sortMouvement(sort1,joueurA,page,tab, nombreJoueur,tabJoueurs);
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

void sortAttaque(t_sorts sort1, t_joueur* joueurA, t_joueur* tabjoueur[],int tour, BITMAP* page, int nbjoueur )
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, i=joueurA->numero+1;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    ///Attaque en zone
    if (sort1.typePortee == 3)
    {
        rest(400);
        do
        {
            if (mouse_b & 1)
            {
                printf("puteInitiale");
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
                printf("%d\n %d",i,tour);
                while(i!=tour)
                {
                    printf("%d",i);
                    if (i>nbjoueur-1)
                    {
                        i=0;
                    }
                    //ligne= abs((tabjoueur[i]->ligne/32)-caseChoisieLigne);
                    //colonne= abs((tabjoueur[i]->colonne/30)-caseChoisieColonne);
                    printf("%d\n",&tabjoueur[i]->ligne);
                    printf("%d",&tabjoueur[i]->colonne);
                    if ((caseChoisieColonne==tabjoueur[i]->colonne/30)&& (caseChoisieLigne==tabjoueur[i]->ligne/32))
                    {
                        testTouche = 1;
                        printf("pute2");
                    }
                    i++;

                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
            /*for (int z=0; z<nbJoueurs; z++)
                {
                    if (tabJoueur[z]->numeroClasse==1)///Pikachu
                    {
                        afficher_personnage_pikachu(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==2)///Ronflex
                    {
                        afficher_personnage_ronflex(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==3)///Lucario
                    {
                        afficher_personnage_lucario(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==4)///Alakazam
                    {
                        afficher_personnage_alakazam(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==5)///Rondoudou
                    {
                        afficher_personnage_rondoudou(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }*/


            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,711);
        }
        while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
        printf("pute3");
        if (sortie_mouv == 0)
        {
            if (tabjoueur[i]->tourBouclier>0)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    tabjoueur[i]->pv -= nombrePv;
                    if (tabjoueur[i]->pv <0)
                    {
                        tabjoueur[i]->pv = 0;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }

            joueurA->pa-=sort1.nbrPa;
        }
    }

///Attaque en ligne droite
    if (sort1.typePortee == 1)
    {
        rest(400);
        do
        {
            if (mouse_b & 1)
            {
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
                for (int i=joueurA->numero; i!=tour; i++)
                {
                    if (i>nbjoueur-1)
                    {
                        i=0;
                    }
                    if (caseChoisieColonne==tabjoueur[i]->colonne && caseChoisieLigne==tabjoueur[i]->ligne)
                    {
                        testTouche = i;
                    }
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
            /*for (int z=0; z<nbJoueurs; z++)
                {
                    if (tabJoueur[z]->numeroClasse==1)///Pikachu
                    {
                        afficher_personnage_pikachu(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==2)///Ronflex
                    {
                        afficher_personnage_ronflex(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==3)///Lucario
                    {
                        afficher_personnage_lucario(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==4)///Alakazam
                    {
                        afficher_personnage_alakazam(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }
                    if (tabJoueur[z]->numeroClasse==5)///Rondoudou
                    {
                        afficher_personnage_rondoudou(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                    }*/


            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,711);
        }
        while          ((((joueurA->ligne/32==caseChoisieLigne)
                          || ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                              ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))
                          && ((joueurA->colonne/30==caseChoisieColonne)
                              || ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                  ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))))
                         || (testTouche==0)) && (sortie_mouv == 0));
        if (sortie_mouv == 0)
        {
            if (tabjoueur[testTouche]->tourBouclier>0)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    tabjoueur[testTouche]->pv -= nombrePv;
                    if (tabjoueur[testTouche]->pv <0)
                    {
                        tabjoueur[testTouche]->pv = 0;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }

            joueurA->pa-=sort1.nbrPa;
        }
    }
}

void sortMouvement(t_sorts sort1, t_joueur* joueurA, BITMAP* page, int tab[18][36], int nbJoueurs,t_joueur* tabJoueur[])
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testClic=0;
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
            rest(400);
            do
            {
                if (mouse_b & 1)
                {
                    caseChoisieColonne = mouse_x/30;
                    caseChoisieLigne = mouse_y/32;
                    if (tab[caseChoisieLigne][caseChoisieColonne]==1)
                    {
                        caseChoisieColonne = 3;
                        caseChoisieLigne = 0;
                    }

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
                if(sort1.numero==9)
                {
                    masked_blit(rouler,page,0,0,300,300,rouler->w,rouler->h);
                }
                if (mouse_b & 2)
                {
                    sortie_mouv = 1;
                }
                /*for (int z=0; z<nbJoueurs; z++)
                    {
                        if (tabJoueur[z]->numeroClasse==1)///Pikachu
                        {
                            afficher_personnage_pikachu(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                        }
                        if (tabJoueur[z]->numeroClasse==2)///Ronflex
                        {
                            afficher_personnage_ronflex(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                        }
                        if (tabJoueur[z]->numeroClasse==3)///Lucario
                        {
                            afficher_personnage_lucario(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                        }
                        if (tabJoueur[z]->numeroClasse==4)///Alakazam
                        {
                            afficher_personnage_alakazam(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                        }
                        if (tabJoueur[z]->numeroClasse==5)///Rondoudou
                        {
                            afficher_personnage_rondoudou(page,0,0,tabJoueur[z]->colonne,tabJoueur[z]->ligne);
                        }*/


                show_mouse(page);
                blit(page,screen,0,0,0,0,1200,711);
            }
            while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax)) && (sortie_mouv == 0));
            if (sortie_mouv == 0)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    joueurA->ligne = caseChoisieLigne*32;
                    joueurA->colonne = caseChoisieColonne*30;
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
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
