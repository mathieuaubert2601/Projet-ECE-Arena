#include "header.h"

void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur tabJoueurs[], int nombreJoueur, int tourJoueur, BITMAP* page, int tab[18][36])
{
    BITMAP* pasPA = load_bitmap("phrases/phrasePA.bmp",NULL);
    BITMAP* pasZone = load_bitmap("phrases/phraseZoneImpact.bmp",NULL);
    int totalTouche = 0;
    int touche=0;
    if (sort1.type == 2)
    {
        sortMouvement(sort1,joueurA,page,tab, nombreJoueur,tabJoueurs);
    }
    if (sort1.type == 4)
    {
        sortVie(sort1,joueurA,page);
    }
}


void sortAttaque2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0;
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
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,711);
        }
        while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
        if (sortie_mouv == 0)
        {
            if (joueurB->tourBouclier>0)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv -= nombrePv;
                    if (joueurB->pv <0)
                    {
                        joueurB->pv = 0;
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
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
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
            if (joueurB->tourBouclier>0)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv -= nombrePv;
                    if (joueurB->pv <0)
                    {
                        joueurB->pv = 0;
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

void sortAttaque3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
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
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
                if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
                {
                    testTouche = 1;
                    joueurCTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,711);
        }
        while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
        if (sortie_mouv == 0)
        {
            if (joueurBTouche == 1)
            {
                if (joueurB->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        if (joueurB->pv <0)
                        {
                            joueurB->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurC->pv -= nombrePv;
                        if (joueurC->pv <0)
                        {
                            joueurC->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
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
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
                if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
                {
                    testTouche = 1;
                    joueurCTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
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
            if (joueurBTouche == 1)
            {
                if (joueurB->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        if (joueurB->pv <0)
                        {
                            joueurB->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurC->pv -= nombrePv;
                        if (joueurC->pv <0)
                        {
                            joueurC->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            joueurA->pa-=sort1.nbrPa;
        }
    }
}


void sortAttaque4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
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
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
                if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
                {
                    testTouche = 1;
                    joueurCTouche = 1;
                }
                if ((caseChoisieColonne==joueurD->colonne/30)&& (caseChoisieLigne==joueurD->ligne/32))
                {
                    testTouche = 1;
                    joueurDTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,711);
        }
        while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
        if (sortie_mouv == 0)
        {
            if (joueurBTouche == 1)
            {
                if (joueurB->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        if (joueurB->pv <0)
                        {
                            joueurB->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurC->pv -= nombrePv;
                        if (joueurC->pv <0)
                        {
                            joueurC->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurDTouche == 1)
            {
                if (joueurD->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurD->pv -= nombrePv;
                        if (joueurD->pv <0)
                        {
                            joueurD->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
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
                if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
                {
                    testTouche = 1;
                    joueurBTouche = 1;
                }
                if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
                {
                    testTouche = 1;
                    joueurCTouche = 1;
                }
                if ((caseChoisieColonne==joueurD->colonne/30)&& (caseChoisieLigne==joueurD->ligne/32))
                {
                    testTouche = 1;
                    joueurDTouche = 1;
                }
            }
            if (mouse_b & 2)
            {
                sortie_mouv = 1;
            }
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
            if (joueurBTouche == 1)
            {
                if (joueurB->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        if (joueurB->pv <0)
                        {
                            joueurB->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurC->pv -= nombrePv;
                        if (joueurC->pv <0)
                        {
                            joueurC->pv = 0;
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurDTouche == 1)
            {
                if (joueurD->tourBouclier>0)
                {
                    //Afficher joueur a un bouclier ou attaque echouée
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurD->pv -= nombrePv;
                        if (joueurD->pv <0)
                        {
                            joueurD->pv = 0;
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

void sortStatut2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurB->tourBouclier>0)
        {
            joueurA->pa-=sort1.nbrPa;
        }
        else
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
                masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                blit(page,screen,0,0,0,0,1200,711);
                rest(500);
            }
        }

        joueurA->pa-=sort1.nbrPa;
    }
}


void sortStatut3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
            if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
            {
                testTouche = 1;
                joueurCTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurBTouche == 1)
        {
            if (joueurB->tourBouclier>0)
            {
                //Afficher joueur a un bouclier ou attaque echouée
            }
            else
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
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }
        }
        if (joueurCTouche == 1)
        {
            if (joueurC->tourBouclier>0)
            {
                //Afficher joueur a un bouclier ou attaque echouée
            }
            else
            {
                probabilite=rand() % 100;
                if (probabilite<sort1.chance)
                {
                    if (sort1.typeStatus == 1)
                    {
                        joueurC->tourPoison = 5;
                    }
                    if (sort1.typeStatus == 2)
                    {
                        joueurC->tourDodo = 3;
                    }
                    if (sort1.typeStatus == 3)
                    {
                        joueurC->tourParalysie = 2;
                    }
                    if (sort1.typeStatus == 4)
                    {
                        joueurC->tourPeur = 1;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }
        }
        joueurA->pa-=sort1.nbrPa;
    }
}

void sortStatut4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
            if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
            {
                testTouche = 1;
                joueurCTouche = 1;
            }
            if ((caseChoisieColonne==joueurD->colonne/30)&& (caseChoisieLigne==joueurD->ligne/32))
            {
                testTouche = 1;
                joueurDTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurBTouche == 1)
        {
            if (joueurB->tourBouclier>0)
            {
                //Afficher joueur a un bouclier ou attaque echouée
            }
            else
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
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }
        }
        if (joueurCTouche == 1)
        {
            if (joueurC->tourBouclier>0)
            {
                //Afficher joueur a un bouclier ou attaque echouée
            }
            else
            {
                probabilite=rand() % 100;
                if (probabilite<sort1.chance)
                {
                    if (sort1.typeStatus == 1)
                    {
                        joueurC->tourPoison = 5;
                    }
                    if (sort1.typeStatus == 2)
                    {
                        joueurC->tourDodo = 3;
                    }
                    if (sort1.typeStatus == 3)
                    {
                        joueurC->tourParalysie = 2;
                    }
                    if (sort1.typeStatus == 4)
                    {
                        joueurC->tourPeur = 1;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }
        }
        if (joueurDTouche == 1)
        {
            if (joueurD->tourBouclier>0)
            {
                //Afficher joueur a un bouclier ou attaque echouée
            }
            else
            {
                probabilite=rand() % 100;
                if (probabilite<sort1.chance)
                {
                    if (sort1.typeStatus == 1)
                    {
                        joueurD->tourPoison = 5;
                    }
                    if (sort1.typeStatus == 2)
                    {
                        joueurD->tourDodo = 3;
                    }
                    if (sort1.typeStatus == 3)
                    {
                        joueurD->tourParalysie = 2;
                    }
                    if (sort1.typeStatus == 4)
                    {
                        joueurD->tourPeur = 1;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
            }
        }
        joueurA->pa-=sort1.nbrPa;
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

void sortSoin2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    rest(400);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurA->equipe==joueurB->equipe)
        {
            probabilite=rand() % 100 ;
            if (probabilite<sort1.chance)
            {
                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                joueurB->pv += nombrePv;
                if (joueurB->pv > joueurB->classe.pv)
                {
                    joueurB->pv = joueurB->classe.pv ;
                }
            }
            else if (probabilite>=sort1.chance)
            {
                masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                blit(page,screen,0,0,0,0,1200,711);
                rest(500);
            }
            joueurA->pa-=sort1.nbrPa;
        }
        else
        {
            //Afficher pas meme equipe
        }


    }
}



void sortSoin3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
            if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
            {
                testTouche = 1;
                joueurCTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurBTouche == 1)
        {
            if (joueurA->equipe==joueurB->equipe)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv += nombrePv;
                    if (joueurB->pv > joueurB->classe.pv)
                    {
                        joueurB->pv = joueurB->classe.pv ;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }
        }
        if (joueurCTouche == 1)
        {
            if (joueurA->equipe==joueurC->equipe)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurC->pv += nombrePv;
                    if (joueurC->pv > joueurC->classe.pv)
                    {
                        joueurC->pv = joueurC->classe.pv ;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }
        }
    }
}

void sortSoin4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
    int nombrePv;
    BITMAP* rate = load_bitmap("phrases/phraseRate.bmp",NULL);
    do
    {
        if (mouse_b & 1)
        {
            caseChoisieColonne = mouse_x/30;
            caseChoisieLigne = mouse_y/32;
            if ((caseChoisieColonne==joueurB->colonne/30)&& (caseChoisieLigne==joueurB->ligne/32))
            {
                testTouche = 1;
                joueurBTouche = 1;
            }
            if ((caseChoisieColonne==joueurC->colonne/30)&& (caseChoisieLigne==joueurC->ligne/32))
            {
                testTouche = 1;
                joueurCTouche = 1;
            }
            if ((caseChoisieColonne==joueurD->colonne/30)&& (caseChoisieLigne==joueurD->ligne/32))
            {
                testTouche = 1;
                joueurDTouche = 1;
            }
        }
        if (mouse_b & 2)
        {
            sortie_mouv = 1;
        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }
    while(((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<sort1.pMin) || (abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>sort1.pMax) || (testTouche==0)) && (sortie_mouv == 0));
    if (sortie_mouv == 0)
    {
        if (joueurBTouche == 1)
        {
            if (joueurA->equipe==joueurB->equipe)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurB->pv += nombrePv;
                    if (joueurB->pv > joueurB->classe.pv)
                    {
                        joueurB->pv = joueurB->classe.pv ;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }
        }
        if (joueurCTouche == 1)
        {
            if (joueurA->equipe==joueurC->equipe)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurC->pv += nombrePv;
                    if (joueurC->pv > joueurC->classe.pv)
                    {
                        joueurC->pv = joueurC->classe.pv ;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }
        }
        if (joueurDTouche == 1)
        {
            if (joueurA->equipe==joueurD->equipe)
            {
                probabilite=rand() % 100 ;
                if (probabilite<sort1.chance)
                {
                    nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                    joueurD->pv += nombrePv;
                    if (joueurD->pv > joueurD->classe.pv)
                    {
                        joueurD->pv = joueurD->classe.pv ;
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    masked_blit(rate,page,0,0,330,400,rate->w,rate->h);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(500);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }
        }
    }
}
