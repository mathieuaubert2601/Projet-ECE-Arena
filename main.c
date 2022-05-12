#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    srand(time(NULL));

    t_joueur tabJoueur[4],tabJoueurInit[4];
    int pmDebut;
    int sortieMenu = 0;
    int nbJoueurs;
    int i=0;
    int joueurSuivant = 0;
    int j=0;
    int pikachuPm=6;
    int ronflexPm=2;
    int lucarioPm=4;
    int alakazamPm=3;
    int rondoudouPm=5;
    int test=1;
    int sortieJeu=0;
    int casex, casey;
    casex = 30;
    casey = 32;

    t_joueur joueur1,joueur2,joueur3,joueur4;
    for (int c=0;i<15;i++)
    {
        tabJoueurInit[0].pseudo[c]=' ';
    }
    for (int c=0;i<15;i++)
    {
        tabJoueurInit[1].pseudo[c]=' ';
    }
    for (int c=0;i<15;i++)
    {
        tabJoueurInit[2].pseudo[c]=' ';
    }
    for (int c=0;i<15;i++)
    {
        tabJoueurInit[3].pseudo[c]=' ';
    }

    int violetCity=0;


    //DÃ©claration du tableau de case :
    int tableau_Cases[18][36];
    int tableau_affichage_arbre[18][36];

    //initialisation des tableaux
    mettre_arbre_ou_non(tableau_Cases);
    remettre_case_obstacle(tableau_Cases);
    lecture_fichier_matrice_map_arbre(tableau_affichage_arbre);

    ///Declaration des BITMAP
    BITMAP* fondMenu = load_bitmap("fond/fondMenu.bmp",NULL);
    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* quitter = load_bitmap("boutons/Quitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/QuitterInv.bmp",NULL);
    BITMAP* reprendre = load_bitmap("boutons/Reprendre.bmp",NULL);
    BITMAP* reprendreInv = load_bitmap("boutons/ReprendreInv.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");
    BITMAP* lucario = load_bitmap("lucario/lucario1.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou/rondoudou1.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikachu/pikachu1.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex/ronflex1.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam/alakazam1.bmp",NULL);


    BITMAP* logo = load_bitmap("fond/logo.bmp",NULL);


    int x=0,y=0;

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);


    while(!key[KEY_ESC])
    {
        sortieMenu=0;
        clear_bitmap(page);
        if (violetCity==0)
        {
            play_sample(musiqueFond,200,0,1000,1);
            violetCity++;
        }

        menuJeu(page,fondMenu,logo);
        if(((mouse_x>=(375)&& mouse_x<=(375+444))&& (mouse_y)>=(500)&& mouse_y<=(156+500))&&(mouse_b && 1))
        {
            rest(100);
            sortieMenu=0;
            while(sortieMenu!=1)
            {
                menuNbJoueur(page,fondMenu,logo,&violetCity);
                if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
                {
                    sortieMenu=1;
                }
                if(((mouse_x>=(320) && mouse_x<=(320+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 2 joueurs
                {

                    nbJoueurs = 2;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);

                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if(((mouse_x>=(520)&& mouse_x<=(520+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 3 joueurs
                {
                    nbJoueurs = 3;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);
                    Saisir_nom(tabJoueurInit[2].pseudo,page);
                    //ordreJoueurs3(tabJoueur,nbJoueurs,joueur1,joueur2,joueur3);
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if(((mouse_x>=(720)&& mouse_x<=(720+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 4 joueurs
                {
                    nbJoueurs = 4;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);
                    Saisir_nom(tabJoueurInit[2].pseudo,page);
                    Saisir_nom(tabJoueurInit[3].pseudo,page);
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if (i==nbJoueurs)
                {
                    time_t temps1=time(NULL);
                    sortieJeu=0;
                    for (int z=0; z<nbJoueurs; z++)
                        {
                            if (tabJoueur[z].numeroClasse==1)///Pikachu
                            {
                                tabJoueur[z].pm=pikachuPm;
                            }
                            if (tabJoueur[z].numeroClasse==2)///Ronflex
                            {
                                tabJoueur[z].pm=ronflexPm;
                            }
                            if (tabJoueur[z].numeroClasse==3)///Lucario
                            {
                                tabJoueur[z].pm=lucarioPm;
                            }
                            if (tabJoueur[z].numeroClasse==4)///Alakazam
                            {
                                tabJoueur[z].pm=alakazamPm;
                            }
                            if (tabJoueur[z].numeroClasse==5)///Rondoudou
                            {
                                tabJoueur[z].pm=rondoudouPm;
                            }
                            tabJoueur[z].pa=10;
                        }
                    while(sortieJeu!=1)
                    {
                        if (j==nbJoueurs)
                        {
                            j=0;
                        }
                        pmDebut=tabJoueur[j].pm;
                        afficher_map(page);
                        for (int z=0; z<nbJoueurs; z++)
                        {
                            if (tabJoueur[z].numeroClasse==1)///Pikachu
                            {
                                afficher_personnage_pikachu(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==2)///Ronflex
                            {
                                afficher_personnage_ronflex(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==3)///Lucario
                            {
                                afficher_personnage_lucario(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==4)///Alakazam
                            {
                                afficher_personnage_alakazam(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==5)///Rondoudou
                            {
                                afficher_personnage_rondoudou(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                        }
                        afficher_tout_arbre(page,tableau_affichage_arbre);
                        afficher_commande(page,tabJoueur,nbJoueurs,j);

                        ///SORTS
                        //Sort1
                        if((mouse_x>=(casex*10)&& mouse_x<=(casex*10+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort1.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort1,tabJoueur[j],page);
                            }
                            if (tabJoueur[j].classe.sort1.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort1,tabJoueur[j],page);
                            }
                        }
                        if(((mouse_x>=(casex*10)&& mouse_x<=(casex*10+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b && 1))
                        {
                            lancerSort(tabJoueur[j].classe.sort1,&tabJoueur[j],tabJoueur,nbJoueurs,j,page);
                            rest(200);
                        }
                        //Sort2
                        if((mouse_x>=(casex*14)&& mouse_x<=(casex*14+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort2.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort2,tabJoueur[j],page);
                            }
                            if (tabJoueur[j].classe.sort2.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort2,tabJoueur[j],page);
                            }
                        }
                        if(((mouse_x>=(casex*14)&& mouse_x<=(casex*14+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b && 1))
                        {
                            lancerSort(tabJoueur[j].classe.sort2,&tabJoueur[j],tabJoueur,nbJoueurs,j,page);
                            rest(200);
                        }
                        //Sort3
                        if((mouse_x>=(casex*18)&& mouse_x<=(casex*18+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort3.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort3,tabJoueur[j],page);
                            }
                            if (tabJoueur[j].classe.sort3.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort3,tabJoueur[j],page);
                            }
                        }
                        if(((mouse_x>=(casex*18)&& mouse_x<=(casex*18+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b && 1))
                        {
                            lancerSort(tabJoueur[j].classe.sort3,&tabJoueur[j],tabJoueur,nbJoueurs,j,page);
                            rest(200);
                        }
                        //Sort4
                        if((mouse_x>=(casex*22)&& mouse_x<=(casex*22+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort4.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort4,tabJoueur[j],page);
                            }
                            if (tabJoueur[j].classe.sort4.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort4,tabJoueur[j],page);
                            }
                        }
                        if(((mouse_x>=(casex*22)&& mouse_x<=(casex*22+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b && 1))
                        {
                            lancerSort(tabJoueur[j].classe.sort4,&tabJoueur[j],tabJoueur,nbJoueurs,j,page);
                            rest(200);
                        }
                        //Sort5
                        if((mouse_x>=(casex*26)&& mouse_x<=(casex*26+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort5.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort5,tabJoueur[j],page);
                            }
                            if (tabJoueur[j].classe.sort5.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort5,tabJoueur[j],page);
                            }
                        }
                        if(((mouse_x>=(casex*26)&& mouse_x<=(casex*26+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b && 1))
                        {
                            lancerSort(tabJoueur[j].classe.sort5,&tabJoueur[j],tabJoueur,nbJoueurs,j,page);
                            rest(200);
                        }
                        //if(((mouse_x>=(casex*30)&& mouse_x<=(casex*30+100))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+100))&&(mouse_b && 1))
                        //{
                        //}
                        for (int z=0; z<nbJoueurs; z++)
                        {
                            if (tabJoueur[z].numeroClasse==1)///Pikachu
                            {
                                afficher_personnage_pikachu(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==2)///Ronflex
                            {
                                afficher_personnage_ronflex(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==3)///Lucario
                            {
                                afficher_personnage_lucario(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==4)///Alakazam
                            {
                                afficher_personnage_alakazam(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                            if (tabJoueur[z].numeroClasse==5)///Rondoudou
                            {
                                afficher_personnage_rondoudou(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                            }
                        }
                        if(((mouse_x>=(1100)&& mouse_x<=(1190))&& (mouse_y)>=(0)&& mouse_y<=(70))&&(mouse_b && 1))
                        {
                            while(test==1)
                            {
                                clear_bitmap(page);
                                blit(fond,page,0,0,0,0,1200,711);
                                AffichageBouton(quitter,quitterInv,fond,0,0,200,210,200,73);
                                AffichageBouton(reprendre,reprendreInv,fond,0,0,400,210,200,73);
                                if (((mouse_x>=(400)&& mouse_x<=(600))&& (mouse_y)>=(210)&& mouse_y<=(283))&&(mouse_b && 1))
                                {
                                    test=0;
                                }
                                if (((mouse_x>=(200)&& mouse_x<=(400))&& (mouse_y)>=(210)&& mouse_y<=(283))&&(mouse_b && 1))
                                {
                                    sortieMenu=1;
                                    sortieJeu=1;
                                    test=0;
                                }
                                show_mouse(page);
                                blit(page,screen,0,0,0,0,1200,711);
                            }
                            test=1;
                        }
                        show_mouse(page);
                        blit(page,screen,0,0,0,0,1200,711);
                        time_t temps2=time(NULL);
                        if (difftime(temps2,temps1)>=15)
                        {
                            temps1=time(NULL);
                            tabJoueur[j].pa=10;
                            tabJoueur[j].pm=pmDebut;
                            if(tabJoueur[j].tourBouclier>0)
                            {
                               tabJoueur[j].tourBouclier--;
                            }
                            if(tabJoueur[j].tourDodo>0)
                            {
                               tabJoueur[j].tourDodo--;
                            }
                            if(tabJoueur[j].tourHate>0)
                            {
                               tabJoueur[j].tourHate--;
                            }
                            if(tabJoueur[j].tourParalysie>0)
                            {
                               tabJoueur[j].tourParalysie--;
                            }
                            if(tabJoueur[j].tourPeur>0)
                            {
                               tabJoueur[j].tourPeur--;
                            }
                            if(tabJoueur[j].tourPoison>0)
                            {
                               tabJoueur[j].tourPoison--;
                               tabJoueur[j].pv-=5;
                            }
                            j++;
                            rest(200);
                        }
                        if(((mouse_x>=(30*37)&& mouse_x<=((30*37)+130))&& (mouse_y)>=(620)&& mouse_y<=(620+115))&&(mouse_b && 1))
                        {
                            temps1=time(NULL);
                            tabJoueur[j].pa=10;
                            tabJoueur[j].pm=pmDebut;
                            if(tabJoueur[j].tourBouclier>0)
                            {
                               tabJoueur[j].tourBouclier--;
                            }
                            if(tabJoueur[j].tourDodo>0)
                            {
                               tabJoueur[j].tourDodo--;
                            }
                            if(tabJoueur[j].tourHate>0)
                            {
                               tabJoueur[j].tourHate--;
                            }
                            if(tabJoueur[j].tourParalysie>0)
                            {
                               tabJoueur[j].tourParalysie--;
                            }
                            if(tabJoueur[j].tourPeur>0)
                            {
                               tabJoueur[j].tourPeur--;
                            }
                            if(tabJoueur[j].tourPoison>0)
                            {
                               tabJoueur[j].tourPoison--;
                               tabJoueur[j].pv-=5;
                            }
                            j++;
                            rest(200);
                        }
                    }
                    i=0;
                }

            }

        }
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);


        /*clear_bitmap(page);
        afficher_map(page);
        afficher_cases_dispo_joueur(page,x,y,6,tableau_Cases);
        afficher_tout_arbre(page,tableau_affichage_arbre);*/
        //casebleu_foncee(page,x,y);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
        //allegro_message("ok");
        x++;
        if(x==36)
        {
            x=0;
            y++;
        }

    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
