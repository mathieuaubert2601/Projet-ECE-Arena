#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    srand(time(NULL));

    t_joueur tabJoueur[4],tabJoueurInit[4];
    int nbJeq1, nbJeq2;
    int tempohate=0;
    int sortieMenu = 0;
    int nbJoueurs,compteurMort,compteurMortEquipe;
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
    int test3=1;
    int test4=1;
    int resFin;
    int casex, casey;
    int modeEquipe=0;
    int equipe1[2], equipe2[2], vainqueur;
    casex = 30;
    casey = 32;

    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);

    t_joueur joueur1,joueur2,joueur3,joueur4;
    for (int c=0; i<15; i++)
    {
        tabJoueurInit[0].pseudo[c]=' ';
    }
    for (int c=0; i<15; i++)
    {
        tabJoueurInit[1].pseudo[c]=' ';
    }
    for (int c=0; i<15; i++)
    {
        tabJoueurInit[2].pseudo[c]=' ';
    }
    for (int c=0; i<15; i++)
    {
        tabJoueurInit[3].pseudo[c]=' ';
    }

    int violetCity=0;


    //DÃ©claration du tableau de case :
    int tableau_Cases[18][36];
    int tableau_affichage_arbre[18][36];
    int tableau_case_possible[18][36];
    int tableau_chemin_court[18][36];
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
    BITMAP* confirmer = load_bitmap("boutons/Confirmer.bmp",NULL);
    BITMAP* confirmerInv = load_bitmap("boutons/ConfirmerInv.bmp",NULL);

    BITMAP* logo = load_bitmap("fond/logo.bmp",NULL);


    int x=3,y=0,case_prec_x = 0,case_prec_y = 0,deplacement = 0;

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);



    while(!key[KEY_ESC])
    {
        sortieMenu=0;
        clear_bitmap(page);
        /*if (violetCity==0)
        {
            play_sample(musiqueFond,200,0,1000,1);
            violetCity++;
        }*/

        menuJeu(page,fondMenu,logo);
        if(((mouse_x>=(375)&& mouse_x<=(375+444))&& (mouse_y)>=(500)&& mouse_y<=(156+500))&&(mouse_b & 1))
        {
            rest(100);
            sortieMenu=0;
            while(sortieMenu!=1)
            {
                modeEquipe=0;
                menuNbJoueur(page,fondMenu,logo,&violetCity);
                if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b & 1))
                {
                    sortieMenu=1;
                }
                if(((mouse_x>=(200) && mouse_x<=(200+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b & 1))///Choix 2 joueurs
                {

                    nbJoueurs = 2;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);

                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i,modeEquipe);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if(((mouse_x>=(400)&& mouse_x<=(400+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b & 1))///Choix 3 joueurs
                {
                    nbJoueurs = 3;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);
                    Saisir_nom(tabJoueurInit[2].pseudo,page);
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i,modeEquipe);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if(((mouse_x>=(600)&& mouse_x<=(600+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b & 1))///Choix 4 joueurs
                {
                    nbJoueurs = 4;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);
                    Saisir_nom(tabJoueurInit[2].pseudo,page);
                    Saisir_nom(tabJoueurInit[3].pseudo,page);
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i,modeEquipe);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                    if(((mouse_x>=(800)&& mouse_x<=(800+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b & 1))///Choix 4 joueurs
                {
                    nbJoueurs = 4;
                    modeEquipe=1;
                    Saisir_nom(tabJoueurInit[0].pseudo,page);
                    Saisir_nom(tabJoueurInit[1].pseudo,page);
                    Saisir_nom(tabJoueurInit[2].pseudo,page);
                    Saisir_nom(tabJoueurInit[3].pseudo,page);
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,tabJoueurInit,violetCity,musiqueFond,i, tableau_Cases,i,modeEquipe);
                        rest(300);
                    }
                    ordreJoueurs(tabJoueur,tabJoueurInit,nbJoueurs);
                }
                if (i==nbJoueurs)
                {
                    test3=0;
                    for (int z=0; z<nbJoueurs; z++)
                    {
                        tabJoueur[z].tourHate=0;
                        tabJoueur[z].tourDodo=0;
                        tabJoueur[z].tourParalysie=0;
                        tabJoueur[z].tourPeur=0;
                        tabJoueur[z].tourPoison=0;
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

                    sortieJeu=0;
                    for (int z=0; z<nbJoueurs; z++)
                    {
                        if (tabJoueur[z].numeroClasse==1)///Pikachu
                        {
                            demande_placement(page,&tabJoueur[z],tableau_Cases,tableau_affichage_arbre,tabJoueur,z);
                            afficher_personnage_pikachu(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                        }
                        if (tabJoueur[z].numeroClasse==2)///Ronflex
                        {
                            demande_placement(page,&tabJoueur[z],tableau_Cases,tableau_affichage_arbre,tabJoueur,z);
                            afficher_personnage_ronflex(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                        }
                        if (tabJoueur[z].numeroClasse==3)///Lucario
                        {
                            demande_placement(page,&tabJoueur[z],tableau_Cases,tableau_affichage_arbre,tabJoueur,z);
                            afficher_personnage_lucario(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                        }
                        if (tabJoueur[z].numeroClasse==4)///Alakazam
                        {
                            demande_placement(page,&tabJoueur[z],tableau_Cases,tableau_affichage_arbre,tabJoueur,z);
                            afficher_personnage_alakazam(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                        }
                        if (tabJoueur[z].numeroClasse==5)///Rondoudou
                        {
                            demande_placement(page,&tabJoueur[z],tableau_Cases,tableau_affichage_arbre,tabJoueur,z);
                            afficher_personnage_rondoudou(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                        }

                        rest(200);
                    }
                    time_t temps1 = time(NULL);
                    while(sortieJeu!=1)
                    {
                        if (j==nbJoueurs)
                        {
                            j=0;
                        }
                        if (tabJoueur[j].mort==1 || tabJoueur[j].tourDodo>=1 || tabJoueur[j].tourParalysie>=1 || tabJoueur[j].tourPeur>=1)
                        {
                            if(tabJoueur[j].tourDodo>0)
                            {
                                tabJoueur[j].tourDodo--;
                                phrases(page,6);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            if(tabJoueur[j].tourParalysie>0)
                            {
                                tabJoueur[j].tourParalysie--;
                                phrases(page,7);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            if(tabJoueur[j].tourPeur>0)
                            {
                                tabJoueur[j].tourPeur--;
                                phrases(page,8);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            if(tabJoueur[j].tourPoison>0)
                            {
                                tabJoueur[j].tourPoison--;
                                tabJoueur[j].pv-=5;
                                phrases(page,10);
                                blit(page,screen,0,0,0,0,1200,711);
                                rest(1000);
                            }
                            j++;
                        }

                        if (tabJoueur[j].tourHate >0 && tempohate==0 )
                        {
                            tabJoueur[j].pm=tabJoueur[j].pm*2;
                            tempohate=1;
                        }
                        afficher_map(page);

                        afficher_tout_arbre(page,tableau_affichage_arbre);
                        afficher_commande(page,tabJoueur,nbJoueurs,j);

                        if (((mouse_x>=(175)&& mouse_x<=(175+90))&& (mouse_y)>=(620)&& mouse_y<=(620+80))&&(mouse_b & 1))
                        {
                            rest(100);
                            while(deplacement == 0)
                            {
                                clear_bitmap(page);
                                afficher_map(page);
                                afficher_cases_dispo_joueur(page,(tabJoueur[j].colonne)/30,(tabJoueur[j].ligne)/32,tabJoueur[j].pm,tableau_Cases,tableau_case_possible,tabJoueur,nbJoueurs,j);
                                changement_case_souris(page,mouse_x,mouse_y,&case_prec_x,&case_prec_y,tableau_case_possible,tableau_chemin_court,(tabJoueur[j].colonne)/30,(tabJoueur[j].ligne)/32);
                                afficher_chemin(page,tableau_chemin_court,tabJoueur,nbJoueurs,j);
                                afficher_tout_arbre(page,tableau_affichage_arbre);
                                afficher_commande(page,tabJoueur,nbJoueurs,j);

                                if(mouse_b & 1)
                                {
                                    deplacement_joueur(page,(tabJoueur[j].ligne)/32,(tabJoueur[j].colonne)/30,tabJoueur[j].numeroClasse,tableau_chemin_court,tableau_affichage_arbre,tabJoueur,nbJoueurs,j);
                                    deplacement = 1;
                                }
                                show_mouse(page);
                                blit(page,screen,0,0,0,0,1200,711);
                            }
                            temps1=time(NULL);
                        }
                        deplacement = 0;

                        ///CAC
                        if((mouse_x>=(casex*30)&& mouse_x<=(casex*30+100))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+100))
                        {
                            afficherPorteeCirc(tabJoueur[j].classe.corps,tabJoueur[j],page);
                        }
                        if(((mouse_x>=(casex*30)&& mouse_x<=(casex*30+100))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+100))&&(mouse_b & 1))
                        {
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.corps.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.corps.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.corps.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.corps,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }


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
                        if(((mouse_x>=(casex*10)&& mouse_x<=(casex*10+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b & 1))
                        {
                            if (tabJoueur[j].classe.sort1.type == 2 || tabJoueur[j].classe.sort1.numero == 6 || tabJoueur[j].classe.sort1.numero == 17 || tabJoueur[j].classe.sort1.numero == 5)
                            {
                                lancerSort(tabJoueur[j].classe.sort1,&tabJoueur[j],tabJoueur,nbJoueurs,j,page,tableau_Cases);
                                rest(200);
                            }
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.sort1.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.sort1.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.sort1.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort1.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort1,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }
                        //Sort2
                        if((mouse_x>=(casex*14)&& mouse_x<=(casex*14+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort2.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort2,tabJoueur[j],page);;
                            }
                            if (tabJoueur[j].classe.sort2.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort2,tabJoueur[j],page);;
                            }
                        }
                        if(((mouse_x>=(casex*14)&& mouse_x<=(casex*14+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b & 1))
                        {
                            if (tabJoueur[j].classe.sort2.type == 2 || tabJoueur[j].classe.sort2.numero == 6 || tabJoueur[j].classe.sort2.numero == 17 || tabJoueur[j].classe.sort2.numero == 5)
                            {
                                lancerSort(tabJoueur[j].classe.sort2,&tabJoueur[j],tabJoueur,nbJoueurs,j,page,tableau_Cases);
                                rest(200);
                            }
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.sort2.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.sort2.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.sort2.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort2.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort2,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }
                        //Sort3
                        if((mouse_x>=(casex*18)&& mouse_x<=(casex*18+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort3.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort3,tabJoueur[j],page);;
                            }
                            if (tabJoueur[j].classe.sort3.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort3,tabJoueur[j],page);;
                            }
                        }
                        if(((mouse_x>=(casex*18)&& mouse_x<=(casex*18+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b & 1))
                        {
                            if (tabJoueur[j].classe.sort3.type == 2 || tabJoueur[j].classe.sort3.numero == 6 || tabJoueur[j].classe.sort3.numero == 17 || tabJoueur[j].classe.sort3.numero == 5)
                            {
                                lancerSort(tabJoueur[j].classe.sort3,&tabJoueur[j],tabJoueur,nbJoueurs,j,page,tableau_Cases);
                                rest(200);
                            }
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.sort3.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.sort3.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.sort3.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort3.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort3,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }
                        //Sort4
                        if((mouse_x>=(casex*22)&& mouse_x<=(casex*22+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort4.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort4,tabJoueur[j],page);;
                            }
                            if (tabJoueur[j].classe.sort4.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort4,tabJoueur[j],page);;
                            }
                        }
                        if(((mouse_x>=(casex*22)&& mouse_x<=(casex*22+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b & 1))
                        {
                            if (tabJoueur[j].classe.sort4.type == 2 || tabJoueur[j].classe.sort4.numero == 6 || tabJoueur[j].classe.sort4.numero == 17||tabJoueur[j].classe.sort4.numero == 5)
                            {
                                lancerSort(tabJoueur[j].classe.sort4,&tabJoueur[j],tabJoueur,nbJoueurs,j,page,tableau_Cases);
                                rest(200);
                            }
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.sort4.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.sort4.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.sort4.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort4.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort4,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }
                        //Sort5
                        if((mouse_x>=(casex*26)&& mouse_x<=(casex*26+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))
                        {
                            if (tabJoueur[j].classe.sort5.typePortee==3)
                            {
                                afficherPorteeCirc(tabJoueur[j].classe.sort5,tabJoueur[j],page);;
                            }
                            if (tabJoueur[j].classe.sort5.typePortee==1)
                            {
                                afficherPorteeDroite(tabJoueur[j].classe.sort5,tabJoueur[j],page);;
                            }
                        }
                        if(((mouse_x>=(casex*26)&& mouse_x<=(casex*26+75))&& (mouse_y)>=(casey*19)&& mouse_y<=(casey*19+54))&&(mouse_b & 1))
                        {
                            if (tabJoueur[j].classe.sort5.type == 2 || tabJoueur[j].classe.sort5.numero == 6 || tabJoueur[j].classe.sort5.numero == 17 || tabJoueur[j].classe.sort5.numero == 5 )
                            {
                                lancerSort(tabJoueur[j].classe.sort5,&tabJoueur[j],tabJoueur,nbJoueurs,j,page,tableau_Cases);
                                rest(200);
                            }
                            if (nbJoueurs == 2)
                            {
                                if (tabJoueur[j].classe.sort5.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin2J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 3)
                            {
                                if (tabJoueur[j].classe.sort5.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin3J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[1],page);
                                    }
                                }
                            }
                            if (nbJoueurs == 4)
                            {
                                if (tabJoueur[j].classe.sort5.type == 1)
                                {
                                    if (j == 0)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortAttaque4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.type == 3)
                                {
                                    if (j == 0)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortStatut4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                                if (tabJoueur[j].classe.sort5.numero==20)
                                {
                                    if (j == 0)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 1)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[0],&tabJoueur[2],&tabJoueur[3],page);
                                    }
                                    if (j == 2)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[0],&tabJoueur[3],page);
                                    }
                                    if (j == 3)
                                    {
                                        sortSoin4J(tabJoueur[j].classe.sort5,&tabJoueur[j],&tabJoueur[1],&tabJoueur[2],&tabJoueur[0],page);
                                    }
                                }
                            }
                        }
                        for (int z=0; z<nbJoueurs; z++)
                        {
                            if (tabJoueur[z].numeroClasse==1)///Pikachu
                            {
                                afficher_personnage_pikachu(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                            }
                            if (tabJoueur[z].numeroClasse==2)///Ronflex
                            {
                                afficher_personnage_ronflex(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                            }
                            if (tabJoueur[z].numeroClasse==3)///Lucario
                            {
                                afficher_personnage_lucario(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                            }
                            if (tabJoueur[z].numeroClasse==4)///Alakazam
                            {
                                afficher_personnage_alakazam(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                            }
                            if (tabJoueur[z].numeroClasse==5)///Rondoudou
                            {
                                afficher_personnage_rondoudou(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne,tabJoueur[z]);
                            }
                        }
                        time_t temps3=time(NULL);
                        unsigned long diff=difftime(temps3,temps1);
                        textprintf_ex(page,maPolice,1150,565,makecol(0,0,0),-1,"%d",diff);
                        compteurMort=0;
                        for (int d=0; d<nbJoueurs; d++)
                        {
                            if (tabJoueur[d].mort==0)
                            {
                                compteurMort++;
                            }
                        }
                        if (compteurMort == 1 || (compteurMort == 2 && modeEquipe==1))
                        {
                            if (nbJoueurs==2)
                            {
                                if (tabJoueur[0].mort==0)
                                {
                                    classement2J(page,tabJoueur[0],tabJoueur[1]);
                                }
                                else
                                {
                                    classement2J(page,tabJoueur[1],tabJoueur[0]);
                                }
                            }
                            if (nbJoueurs==3)
                            {
                                if (tabJoueur[0].mort==0)
                                {
                                    classement3J(page,tabJoueur[0],tabJoueur[1],tabJoueur[2]);
                                }
                                if (tabJoueur[1].mort==0)
                                {
                                    classement3J(page,tabJoueur[1],tabJoueur[0],tabJoueur[2]);
                                }
                                else
                                {
                                    classement3J(page,tabJoueur[2],tabJoueur[1],tabJoueur[0]);
                                }
                            }
                            if (nbJoueurs==4)
                            {
                                if(modeEquipe==1)
                                {
                                    nbJeq1=0;
                                    nbJeq2=0;
                                    for (int d=0;d<4;d++)
                                    {
                                        if(tabJoueur[d].equipe==1)
                                        {
                                            equipe1[nbJeq1]=d;
                                            nbJeq1++;
                                        }
                                        if(tabJoueur[d].equipe==2)
                                        {
                                            equipe2[nbJeq2]=d;
                                            nbJeq2++;
                                        }
                                    }
                                    compteurMortEquipe=0;
                                    vainqueur=0;
                                    for (int f=0;f<4;f++)
                                    {
                                        if (tabJoueur[f].mort==0)
                                        {
                                            compteurMortEquipe=f;
                                        }
                                    }
                                    if (tabJoueur[compteurMortEquipe].equipe==1)
                                    {
                                        vainqueur=1;
                                    }
                                    if (tabJoueur[compteurMortEquipe].equipe==2)
                                    {
                                        vainqueur=2;
                                    }
                                    if (vainqueur==1)
                                    {
                                        classementEquipe(page,tabJoueur[equipe1[0]],tabJoueur[equipe1[1]],tabJoueur[equipe2[0]],tabJoueur[equipe2[1]]);
                                    }
                                    if (vainqueur==2)
                                    {
                                        classementEquipe(page,tabJoueur[equipe2[0]],tabJoueur[equipe2[1]],tabJoueur[equipe1[0]],tabJoueur[equipe1[1]]);
                                    }
                                }
                                else
                                {
                                    if (tabJoueur[0].mort==0)
                                    {
                                        classement4J(page,tabJoueur[0],tabJoueur[1],tabJoueur[2],tabJoueur[3]);
                                    }
                                    if (tabJoueur[1].mort==0)
                                    {
                                        classement4J(page,tabJoueur[1],tabJoueur[0],tabJoueur[2],tabJoueur[3]);
                                    }
                                    if (tabJoueur[2].mort==0)
                                    {
                                        classement4J(page,tabJoueur[2],tabJoueur[0],tabJoueur[1],tabJoueur[3]);
                                    }
                                    else
                                    {
                                        classement4J(page,tabJoueur[3],tabJoueur[0],tabJoueur[1],tabJoueur[2]);
                                    }
                                }
                            }
                            rest(5000);

                            resFin = menuFin(page);
                                if (resFin == 1)
                                {
                                    for(int r=0;r<nbJoueurs;r++)
                                    {
                                        if (tabJoueur[r].numeroClasse==1)
                                        {
                                            tabJoueur[r].pv=75;
                                        }
                                        if (tabJoueur[r].numeroClasse==2)
                                        {
                                            tabJoueur[r].pv=125;
                                        }
                                        if (tabJoueur[r].numeroClasse==3)
                                        {
                                            tabJoueur[r].pv=100;
                                        }
                                        if (tabJoueur[r].numeroClasse==4)
                                        {
                                            tabJoueur[r].pv=100;
                                        }
                                        if (tabJoueur[r].numeroClasse==5)
                                        {
                                            tabJoueur[r].pv=75;
                                        }
                                        tabJoueur[r].degats=0;
                                        tabJoueur[r].kills=0;
                                        tabJoueur[r].mort=0;
                                        tabJoueur[r].tourDodo=0;
                                        tabJoueur[r].tourHate=0;
                                        tabJoueur[r].tourPoison=0;
                                        tabJoueur[r].tourPeur=0;
                                        tabJoueur[r].tourParalysie=0;
                                        tabJoueur[r].tourBouclier=0;
                                        demande_placement(page,&tabJoueur[r],tableau_Cases,tableau_affichage_arbre,tabJoueur,r);

                                    }
                                }
                                if (resFin == 2)
                                {
                                    sortieJeu=1;
                                }
                                if (resFin == 3)
                                {
                                    sortieJeu=1;
                                    sortieMenu=1;
                                    test3=1;
                                }
                                rest(500);


                        }
                        if(((mouse_x>=(1100)&& mouse_x<=(1190))&& (mouse_y)>=(0)&& mouse_y<=(70))&&(mouse_b & 1))
                        {
                            while(test==1)
                            {
                                clear_bitmap(page);;
                                blit(fond,page,0,0,0,0,1200,711);
                                AffichageBouton(quitter,quitterInv,fond,0,0,400,100,350,125);
                                AffichageBouton(reprendre,reprendreInv,fond,0,0,400,250,350,125);
                                if (((mouse_x>=(400)&& mouse_x<=(750))&& (mouse_y)>=(250)&& mouse_y<=(375))&&(mouse_b & 1))
                                {
                                    test=0;
                                }
                                if (((mouse_x>=(200)&& mouse_x<=(750))&& (mouse_y)>=(100)&& mouse_y<=(225))&&(mouse_b & 1))
                                {
                                    sortieMenu=1;
                                    sortieJeu=1;
                                    test3=1;
                                    test=0;
                                }
                                show_mouse(page);;
                                blit(page,screen,0,0,0,0,1200,711);
                            }
                            test=1;
                        }
                        show_mouse(page);
                        blit(page,screen,0,0,0,0,1200,711);
                        time_t temps2=time(NULL);
                        unsigned long tempo = difftime(temps2,temps1);
                        if (tempo>=20)
                        {
                            temps1=time(NULL);
                            tabJoueur[j].pa=10;
                            if (tabJoueur[j].numeroClasse==1)///Pikachu
                            {
                                tabJoueur[j].pm=pikachuPm;
                            }
                            if (tabJoueur[j].numeroClasse==2)///Ronflex
                            {
                                tabJoueur[j].pm=ronflexPm;
                            }
                            if (tabJoueur[j].numeroClasse==3)///Lucario
                            {
                                tabJoueur[j].pm=lucarioPm;
                            }
                            if (tabJoueur[j].numeroClasse==4)///Alakazam
                            {
                                tabJoueur[j].pm=alakazamPm;
                            }
                            if (tabJoueur[j].numeroClasse==5)///Rondoudou
                            {
                                tabJoueur[j].pm=rondoudouPm;
                            }
                            if(tabJoueur[j].tourBouclier>0)
                            {
                                tabJoueur[j].tourBouclier--;
                            }
                            if(tabJoueur[j].tourDodo>0)
                            {
                                tabJoueur[j].tourDodo--;
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
                            if(tabJoueur[j].tourHate>0)
                            {
                                tabJoueur[j].tourHate--;
                                tempohate--;
                            }
                            j++;
                            rest(200);
                        }
                        if(((mouse_x>=(30*37)&& mouse_x<=((30*37)+130))&& (mouse_y)>=(620)&& mouse_y<=(620+115))&&(mouse_b & 1))
                        {
                            temps1=time(NULL);
                            tabJoueur[j].pa=10;
                            if (tabJoueur[j].numeroClasse==1)///Pikachu
                            {
                                tabJoueur[j].pm=pikachuPm;
                            }
                            if (tabJoueur[j].numeroClasse==2)///Ronflex
                            {
                                tabJoueur[j].pm=ronflexPm;
                            }
                            if (tabJoueur[j].numeroClasse==3)///Lucario
                            {
                                tabJoueur[j].pm=lucarioPm;
                            }
                            if (tabJoueur[j].numeroClasse==4)///Alakazam
                            {
                                tabJoueur[j].pm=alakazamPm;
                            }
                            if (tabJoueur[j].numeroClasse==5)///Rondoudou
                            {
                                tabJoueur[j].pm=rondoudouPm;
                            }
                            if(tabJoueur[j].tourBouclier>0)
                            {
                                tabJoueur[j].tourBouclier--;
                            }
                            if(tabJoueur[j].tourDodo>0)
                            {
                                tabJoueur[j].tourDodo--;
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
                            if(tabJoueur[j].tourHate>0)
                            {
                                tabJoueur[j].tourHate--;
                                tempohate--;
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
    }
    destroy_bitmap(page);

    return 0;
}
END_OF_MAIN();
