#include "header.h"

void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur tabJoueurs[], int nombreJoueur, int tourJoueur, BITMAP* page, int tab[18][36])
{
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
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0,joueurBTouche = 0;
    int nombrePv;
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);

    if (joueurA->pa>=sort1.nbrPa)
    {
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
                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurA);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurA);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurA);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurA);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurA);
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
                    phrases(page,9);
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        joueurA->degats += nombrePv;
                        if (joueurB->pv <=0)
                        {
                            joueurB->pv = 0;
                            joueurB->mort=1;
                            joueurB->colonne=2000;
                            joueurB->ligne=2000;
                            joueurA->kills++;
                        }
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                        textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);

                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
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
                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1200,711);
            }
            while          ((((joueurA->ligne/32==caseChoisieLigne)
                              && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                  ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))
                              && ((joueurA->colonne/30==caseChoisieColonne)
                                  && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                      ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))))
                             || (testTouche==0)) && (sortie_mouv == 0));
            if (sortie_mouv == 0)
            {
                if (joueurB->tourBouclier>0)
                {
                    joueurA->pa-=sort1.nbrPa;
                    phrases(page,9);
                }
                else
                {
                    probabilite=rand() % 100 ;
                    if (probabilite<sort1.chance)
                    {
                        nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                        joueurB->pv -= nombrePv;
                        joueurA->degats += nombrePv;
                        if (joueurB->pv <=0)
                        {
                            joueurB->pv = 0;
                            joueurB->mort=1;
                            joueurB->colonne=2000;
                            joueurB->ligne=2000;
                            joueurA->kills = joueurA->kills+1 ;
                        }
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }

                        textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                }

                joueurA->pa-=sort1.nbrPa;
            }
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}

void sortAttaque3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
    int nombrePv;
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);

    if (joueurA->pa>=sort1.nbrPa)
    {
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
                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }

                ///Afficher joueurC
                if (joueurC->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
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
                        phrases(page,9);
                    }
                    else
                    {
                        probabilite=rand() % 100 ;
                        if (probabilite<sort1.chance)
                        {
                            nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                            joueurB->pv -= nombrePv;
                            joueurA->degats += nombrePv;
                            if (joueurB->pv <=0)
                            {
                                joueurB->pv = 0;
                                joueurB->mort=1;
                                joueurB->colonne=2000;
                                joueurB->ligne=2000;
                                joueurA->kills++;
                            }
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                            textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                }
                if (joueurCTouche == 1)
                {
                    if (joueurC->tourBouclier>0)
                    {
                        phrases(page,9);
                    }
                    else
                    {
                        probabilite=rand() % 100 ;
                        if (probabilite<sort1.chance)
                        {
                            nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                            joueurC->pv -= nombrePv;
                            joueurA->degats += nombrePv;
                            if (joueurC->pv < 0)
                            {
                                joueurC->pv = 0;
                                joueurC->mort=1;
                                joueurC->colonne=2000;
                                joueurC->ligne=2000;
                                joueurA->kills++;
                            }
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                            textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
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

                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }

                ///Afficher joueurC
                if (joueurC->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1200,711);
            }
            while          ((((joueurA->ligne/32==caseChoisieLigne)
                              && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                  ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))
                              && ((joueurA->colonne/30==caseChoisieColonne)
                                  && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                      ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))))
                             || (testTouche==0)) && (sortie_mouv == 0));
            if (sortie_mouv == 0)
            {
                if (joueurBTouche == 1)
                {
                    if (joueurB->tourBouclier>0)
                    {
                        phrases(page,9);
                    }
                    else
                    {
                        probabilite=rand() % 100 ;
                        if (probabilite<sort1.chance)
                        {
                            nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                            joueurB->pv -= nombrePv;
                            joueurA->degats += nombrePv;
                            if (joueurB->pv <=0)
                            {
                                joueurB->pv = 0;
                                joueurB->mort=1;
                                joueurB->colonne=2000;
                                joueurB->ligne=2000;
                                joueurA->kills++;
                            }
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                            textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                }
                if (joueurCTouche == 1)
                {
                    if (joueurC->tourBouclier>0)
                    {
                        phrases(page,9);
                    }
                    else
                    {
                        probabilite=rand() % 100 ;
                        if (probabilite<sort1.chance)
                        {
                            nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                            joueurC->pv -= nombrePv;
                            joueurA->degats += nombrePv;
                            if (joueurC->pv <=0)
                            {
                                joueurC->pv = 0;
                                joueurC->mort=1;
                                joueurC->colonne=2000;
                                joueurC->ligne=2000;
                                joueurA->kills++;
                            }
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                            textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                }
                joueurA->pa-=sort1.nbrPa;
            }
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}


void sortAttaque4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
    int nombrePv;
    FONT* maPolice = load_font("police_ecriture/calibri.pcx",NULL,NULL);

    if (joueurA->pa>=sort1.nbrPa)
    {
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

                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }

                ///Afficher joueurC
                if (joueurC->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }

                ///Afficher joueurD
                if (joueurD->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
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
                        phrases(page,9);
                    }
                    else
                    {
                        if(joueurA->equipe!=joueurB->equipe)
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurB->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurB->pv <=0)
                                {
                                    joueurB->pv = 0;
                                    joueurB->mort=1;
                                    joueurB->colonne=2000;
                                    joueurB->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            joueurA->pa-=sort1.nbrPa;
                        }
                        else
                        {
                            phrases(page,11);
                        }

                    }
                }
                if (joueurCTouche == 1)
                {
                    if(joueurA->equipe!=joueurC->equipe)
                    {
                        if (joueurC->tourBouclier>0)
                        {
                            phrases(page,9);
                        }
                        else
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurC->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurC->pv <=0)
                                {
                                    joueurC->pv = 0;
                                    joueurC->mort=1;
                                    joueurC->colonne=2000;
                                    joueurC->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                        }
                        joueurA->pa-=sort1.nbrPa;
                    }
                    else
                    {
                        phrases(page,11);
                    }
                }
                if (joueurDTouche == 1)
                {
                    if (joueurD->tourBouclier>0)
                    {
                        phrases(page,9);
                        joueurA->pa-=sort1.nbrPa;
                    }
                    else
                    {
                        if(joueurA->equipe!=joueurD->equipe)
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurD->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurD->pv <=0)
                                {
                                    joueurD->pv = 0;
                                    joueurD->mort=1;
                                    joueurD->colonne=2000;
                                    joueurD->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            joueurA->pa-=sort1.nbrPa;
                        }

                        else
                        {
                            phrases(page,11);
                        }
                    }

                }
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

                ///Afficher joueurA
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
                }

                ///Afficher joueurB
                if (joueurB->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }
                if (joueurB->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
                }

                ///Afficher joueurC
                if (joueurC->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }
                if (joueurC->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
                }

                ///Afficher joueurD
                if (joueurD->numeroClasse==1)///Pikachu
                {
                    afficher_personnage_pikachu(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==2)///Ronflex
                {
                    afficher_personnage_ronflex(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==3)///Lucario
                {
                    afficher_personnage_lucario(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==4)///Alakazam
                {
                    afficher_personnage_alakazam(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                if (joueurD->numeroClasse==5)///Rondoudou
                {
                    afficher_personnage_rondoudou(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1200,711);
            }
            while          ((((joueurA->ligne/32==caseChoisieLigne)
                              && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                  ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))
                              && ((joueurA->colonne/30==caseChoisieColonne)
                                  && ((abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)>=sort1.pMin)
                                      ||(abs((joueurA->ligne/32)-caseChoisieLigne)+abs((joueurA->colonne/30)-caseChoisieColonne)<=sort1.pMax))))
                             || (testTouche==0)) && (sortie_mouv == 0));
            if (sortie_mouv == 0)
            {
                if (joueurBTouche == 1)
                {
                    if (joueurB->tourBouclier>0)
                    {
                        phrases(page,9);
                        joueurA->pa-=sort1.nbrPa;
                    }
                    else
                    {
                        if(joueurA->equipe!=joueurB->equipe)
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurB->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurB->pv <=0)
                                {
                                    joueurB->pv = 0;
                                    joueurB->mort=1;
                                    joueurB->colonne=2000;
                                    joueurB->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            joueurA->pa-=sort1.nbrPa;
                        }
                        else
                        {
                            phrases(page,11);
                        }

                    }
                }
                if (joueurCTouche == 1)
                {
                    if(joueurA->equipe!=joueurC->equipe)
                    {
                        if (joueurC->tourBouclier>0)
                        {
                            phrases(page,9);
                        }
                        else
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurC->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurC->pv <=0)
                                {
                                    joueurC->pv = 0;
                                    joueurC->mort=1;
                                    joueurC->colonne=2000;
                                    joueurC->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                        }
                        joueurA->pa-=sort1.nbrPa;
                    }
                    else
                    {
                        phrases(page,11);
                    }
                }
                if (joueurDTouche == 1)
                {
                    if (joueurD->tourBouclier>0)
                    {
                        phrases(page,9);
                    }
                    else
                    {
                        if(joueurA->equipe!=joueurD->equipe)
                        {
                            probabilite=rand() % 100 ;
                            if (probabilite<sort1.chance)
                            {
                                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                                joueurD->pv -= nombrePv;
                                joueurA->degats += nombrePv;
                                if (joueurD->pv <=0)
                                {
                                    joueurD->pv = 0;
                                    joueurD->mort=1;
                                    joueurD->colonne=2000;
                                    joueurD->ligne=2000;
                                    joueurA->kills++;
                                }
                                if (joueurA->numeroClasse==1)///Pikachu
                                {
                                    afficher_attaque_pikachu(page);
                                }
                                if (joueurA->numeroClasse==2)///Ronflex
                                {
                                    afficher_attaque_ronflex(page);
                                }
                                if (joueurA->numeroClasse==3)///Lucario
                                {
                                    afficher_attaque_lucario(page);
                                }
                                if (joueurA->numeroClasse==4)///Alakazam
                                {
                                    afficher_attaque_alakazam(page);
                                }
                                if (joueurA->numeroClasse==5)///Rondoudou
                                {
                                    afficher_attaque_rondoudou(page);
                                }
                                textprintf_ex(page,maPolice,300,300,makecol(255,0,0),-1,"Vous avez inflige %d degats",nombrePv);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            else if (probabilite>=sort1.chance)
                            {
                                phrases(page,1);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                        }
                        else
                        {
                            phrases(page,11);
                        }
                    }
                    joueurA->pa-=sort1.nbrPa;
                }

            }
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}


void sortMouvement(t_sorts sort1, t_joueur* joueurA, BITMAP* page, int tab[18][36], int nbJoueurs,t_joueur* tabJoueur[])
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite;
    if(joueurA->pa>=sort1.nbrPa)
    {
        if (sort1.numero==13)
        {
            probabilite=rand() % 100 ;
            if (probabilite<sort1.chance)
            {
                joueurA->tourHate += 3;
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_attaque_pikachu(page);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_attaque_ronflex(page);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_attaque_lucario(page);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_attaque_alakazam(page);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_attaque_rondoudou(page);
                }
            }
            else if (probabilite>=sort1.chance)
            {
                phrases(page,1);
            }
            joueurA->pa-=sort1.nbrPa;
        }
        if(sort1.numero!=13)
        {



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
                    phrases(page,3);
                }
                if(sort1.numero==0)
                {
                    phrases(page,3);
                }
                if(sort1.numero==16)
                {
                    phrases(page,4);
                }
                if(sort1.numero==9)
                {
                    phrases(page,5);
                }
                if (mouse_b & 2)
                {
                    sortie_mouv = 1;
                }


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
                    if (joueurA->numeroClasse==1)///Pikachu
                    {
                        afficher_attaque_pikachu(page);
                    }
                    if (joueurA->numeroClasse==2)///Ronflex
                    {
                        afficher_attaque_ronflex(page);
                    }
                    if (joueurA->numeroClasse==3)///Lucario
                    {
                        afficher_attaque_lucario(page);
                    }
                    if (joueurA->numeroClasse==4)///Alakazam
                    {
                        afficher_attaque_alakazam(page);
                    }
                    if (joueurA->numeroClasse==5)///Rondoudou
                    {
                        afficher_attaque_rondoudou(page);
                    }
                }

                else if (probabilite>=sort1.chance)
                {
                    phrases(page,1);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
                }
                joueurA->pa-=sort1.nbrPa;
            }
        }
        if (joueurA->pa<sort1.nbrPa)
        {
            phrases(page,2);
            blit(page,screen,0,0,0,0,1200,711);
            rest(1000);
        }
    }
}

void sortStatut2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0;
    int nombrePv;
    if (joueurA->pa>=sort1.nbrPa)
    {
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
            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
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
                phrases(page,9);
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
                    if (joueurA->numeroClasse==1)///Pikachu
                    {
                        afficher_attaque_pikachu(page);
                    }
                    if (joueurA->numeroClasse==2)///Ronflex
                    {
                        afficher_attaque_ronflex(page);
                    }
                    if (joueurA->numeroClasse==3)///Lucario
                    {
                        afficher_attaque_lucario(page);
                    }
                    if (joueurA->numeroClasse==4)///Alakazam
                    {
                        afficher_attaque_alakazam(page);
                    }
                    if (joueurA->numeroClasse==5)///Rondoudou
                    {
                        afficher_attaque_rondoudou(page);
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    phrases(page,1);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
                }
            }

            joueurA->pa-=sort1.nbrPa;
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}


void sortStatut3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
    int nombrePv;
    if (joueurA->pa>=sort1.nbrPa)
    {
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
            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }

            ///Afficher joueurC
            if (joueurC->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
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
                    phrases(page,9);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(500);
                    }
                }
            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    phrases(page,9);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                }
            }
            joueurA->pa-=sort1.nbrPa;
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}

void sortStatut4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
    int nombrePv;
    if (joueurA->pa>=sort1.nbrPa)
    {
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

            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }

            ///Afficher joueurC
            if (joueurC->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }

            ///Afficher joueurD
            if (joueurD->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
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
                    phrases(page,9);
                }
                else
                {
                    if(joueurA->equipe!=joueurB->equipe)
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
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                    else
                    {
                        phrases(page, 11);
                    }
                }

            }
            if (joueurCTouche == 1)
            {
                if (joueurC->tourBouclier>0)
                {
                    phrases(page,9);
                }
                else
                {
                    if(joueurA->equipe!=joueurC->equipe)
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
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                    else
                    {
                        phrases(page,11);
                    }
                }
            }
            if (joueurDTouche == 1)
            {
                if (joueurD->tourBouclier>0)
                {
                    phrases(page,9);
                }
                else
                {
                    if(joueurA->equipe!=joueurD->equipe)
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
                            if (joueurA->numeroClasse==1)///Pikachu
                            {
                                afficher_attaque_pikachu(page);
                            }
                            if (joueurA->numeroClasse==2)///Ronflex
                            {
                                afficher_attaque_ronflex(page);
                            }
                            if (joueurA->numeroClasse==3)///Lucario
                            {
                                afficher_attaque_lucario(page);
                            }
                            if (joueurA->numeroClasse==4)///Alakazam
                            {
                                afficher_attaque_alakazam(page);
                            }
                            if (joueurA->numeroClasse==5)///Rondoudou
                            {
                                afficher_attaque_rondoudou(page);
                            }
                        }
                        else if (probabilite>=sort1.chance)
                        {
                            phrases(page,1);
                            blit(page,screen,0,0,0,0,1200,711);
                            rest(1000);
                        }
                    }
                    else
                    {
                        phrases(page,11);
                    }
                }

            }
            joueurA->pa-=sort1.nbrPa;
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}


void sortVie(t_sorts sort1, t_joueur* joueurA, BITMAP* page)
{
    int probabilite,nombrePv;
    if(joueurA->pa>=sort1.nbrPa)
    {
        if (sort1.typeSoin==1)
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                joueurA->tourBouclier=2;
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_attaque_pikachu(page);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_attaque_ronflex(page);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_attaque_lucario(page);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_attaque_alakazam(page);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_attaque_rondoudou(page);
                }

            }
            else if (probabilite>=sort1.chance)
            {
                phrases(page,1);
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
                joueurA->tourDodo=3;

                if (joueurA->pv>joueurA->classe.pv)
                {
                    joueurA->pv = joueurA->classe.pv;
                }
                if (joueurA->numeroClasse==1)///Pikachu
                {
                    afficher_attaque_pikachu(page);
                }
                if (joueurA->numeroClasse==2)///Ronflex
                {
                    afficher_attaque_ronflex(page);
                }
                if (joueurA->numeroClasse==3)///Lucario
                {
                    afficher_attaque_lucario(page);
                }
                if (joueurA->numeroClasse==4)///Alakazam
                {
                    afficher_attaque_alakazam(page);
                }
                if (joueurA->numeroClasse==5)///Rondoudou
                {
                    afficher_attaque_rondoudou(page);
                }
            }
            else if (probabilite>=sort1.chance)
            {
                phrases(page,1);
            }
            joueurA->pa-=sort1.nbrPa;
        }
    }
    else
    {
        phrases(page,2);
    }

}

void sortSoin2J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0;
    int nombrePv;
    rest(400);
    if (joueurA->pa>=sort1.nbrPa)
    {
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
            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
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
                    if (joueurA->numeroClasse==1)///Pikachu
                    {
                        afficher_attaque_pikachu(page);
                    }
                    if (joueurA->numeroClasse==2)///Ronflex
                    {
                        afficher_attaque_ronflex(page);
                    }
                    if (joueurA->numeroClasse==3)///Lucario
                    {
                        afficher_attaque_lucario(page);
                    }
                    if (joueurA->numeroClasse==4)///Alakazam
                    {
                        afficher_attaque_alakazam(page);
                    }
                    if (joueurA->numeroClasse==5)///Rondoudou
                    {
                        afficher_attaque_rondoudou(page);
                    }
                }
                else if (probabilite>=sort1.chance)
                {
                    phrases(page,1);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
                }
                joueurA->pa-=sort1.nbrPa;
            }
            else
            {
                //Afficher pas meme equipe
            }


        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}


void sortSoin3J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0;
    int nombrePv;
    if (joueurA->pa>=sort1.nbrPa)
    {
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

            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }

            ///Afficher joueurC
            if (joueurC->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
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
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}

void sortSoin4J(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB, t_joueur* joueurC, t_joueur* joueurD, BITMAP* page)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite, testTouche=0, joueurBTouche=0, joueurCTouche=0, joueurDTouche=0;
    int nombrePv;
    if (joueurA->pa>=sort1.nbrPa)
    {
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
            ///Afficher joueurA
            if (joueurA->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }
            if (joueurA->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurA->colonne,joueurA->ligne,*joueurA);
            }

            ///Afficher joueurB
            if (joueurB->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }
            if (joueurB->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurB->colonne,joueurB->ligne,*joueurB);
            }

            ///Afficher joueurC
            if (joueurC->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }
            if (joueurC->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurC->colonne,joueurC->ligne,*joueurC);
            }

            ///Afficher joueurD
            if (joueurD->numeroClasse==1)///Pikachu
            {
                afficher_personnage_pikachu(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==2)///Ronflex
            {
                afficher_personnage_ronflex(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==3)///Lucario
            {
                afficher_personnage_lucario(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==4)///Alakazam
            {
                afficher_personnage_alakazam(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
            }
            if (joueurD->numeroClasse==5)///Rondoudou
            {
                afficher_personnage_rondoudou(page,0,0,joueurD->colonne,joueurD->ligne,*joueurD);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                    joueurA->pa-=sort1.nbrPa;
                }
                else
                {
                    phrases(page,12);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
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
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                    joueurA->pa-=sort1.nbrPa;
                }
                else
                {
                    phrases(page,12);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
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
                            joueurD->pv = joueurD->classe.pv;
                        }
                        if (joueurA->numeroClasse==1)///Pikachu
                        {
                            afficher_attaque_pikachu(page);
                        }
                        if (joueurA->numeroClasse==2)///Ronflex
                        {
                            afficher_attaque_ronflex(page);
                        }
                        if (joueurA->numeroClasse==3)///Lucario
                        {
                            afficher_attaque_lucario(page);
                        }
                        if (joueurA->numeroClasse==4)///Alakazam
                        {
                            afficher_attaque_alakazam(page);
                        }
                        if (joueurA->numeroClasse==5)///Rondoudou
                        {
                            afficher_attaque_rondoudou(page);
                        }
                    }
                    else if (probabilite>=sort1.chance)
                    {
                        phrases(page,1);
                        blit(page,screen,0,0,0,0,1200,711);
                        rest(1000);
                    }
                    joueurA->pa-=sort1.nbrPa;
                }
                else
                {
                    phrases(page,12);
                    blit(page,screen,0,0,0,0,1200,711);
                    rest(1000);
                }
            }
        }
    }
    else
    {
        phrases(page,2);
        blit(page,screen,0,0,0,0,1200,711);
        rest(1000);
    }
}
