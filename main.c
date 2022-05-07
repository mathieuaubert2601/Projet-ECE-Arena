#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");


    t_joueur tabJoueur[4];
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

    int violetCity=0;

    int test=1;


    //DÃ©claration du tableau de case :
    int tableau_Cases[18][36];
    int tableau_affichage_arbre[18][36];

    //initialisation des tableaux
    mettre_arbre_ou_non(tableau_Cases);
    remettre_case_obstacle(tableau_Cases);
    lecture_fichier_matrice_map_arbre(tableau_affichage_arbre);

    ///Declaration des BITMAP
    BITMAP* fondMenu = load_bitmap("fondMenu.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");
    BITMAP* lucario = load_bitmap("lucario/lucario1.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou/rondoudou1.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikachu/pikachu1.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex/ronflex1.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam/alakazam1.bmp",NULL);

    BITMAP* fond = load_bitmap("fond/fondflou.bmp",NULL);
    BITMAP* quitter = load_bitmap("fond/Quitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("fond/QuitterInv.bmp",NULL);
    BITMAP* reprendre = load_bitmap("fond/Reprendre.bmp",NULL);
    BITMAP* reprendreInv = load_bitmap("fond/ReprendreInv.bmp",NULL);

    BITMAP* logo = load_bitmap("logo.bmp",NULL);

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);
    srand(time(NULL));

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
        if(((mouse_x>=(375)&& mouse_x<=(375+444))&& (mouse_y)>=(500)&& mouse_y<=(156+500))&&(mouse_b && 1))
        {
            rest(100);
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
                    for(int j=0; j<nbJoueurs; j++)
                    {
                        Saisir_nom(&tabJoueur[j],page);
                    }
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond, i, tableau_Cases);
                    }
                }
                if(((mouse_x>=(520)&& mouse_x<=(520+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 3 joueurs
                {
                    nbJoueurs = 3;
                    for(int j=0; j<nbJoueurs; j++)
                    {
                        Saisir_nom(&tabJoueur[j],page);
                    }
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond, i, tableau_Cases);
                    }
                }
                if(((mouse_x>=(720)&& mouse_x<=(720+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 4 joueurs
                {
                    nbJoueurs = 4;
                    for(int j=0; j<nbJoueurs; j++)
                    {
                        Saisir_nom(&tabJoueur[j],page);
                    }
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond,i, tableau_Cases);
                    }
                }
                if (i==nbJoueurs)
                {
                    time_t temps1=time(NULL);
                    while(!key[KEY_ESC])
                    {
                        if (j==nbJoueurs)
                        {
                            j=0;
                        }
                        tabJoueur[j].pa=10;
                        afficher_map(page);
                        for (int z=0; z<nbJoueurs; z++)
                        {
                            if (tabJoueur[z].numeroClasse==1)///Pikachu
                            {
                                afficher_personnage_pikachu(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                                tabJoueur[z].pm=pikachuPm;
                            }
                            if (tabJoueur[z].numeroClasse==2)///Ronflex
                            {
                                afficher_personnage_ronflex(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                                tabJoueur[z].pm=ronflexPm;
                            }
                            if (tabJoueur[z].numeroClasse==3)///Lucario
                            {
                                afficher_personnage_lucario(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                                tabJoueur[z].pm=lucarioPm;
                            }
                            if (tabJoueur[z].numeroClasse==4)///Alakazam
                            {
                                afficher_personnage_alakazam(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                                tabJoueur[z].pm=alakazamPm;
                            }
                            if (tabJoueur[z].numeroClasse==5)///Rondoudou
                            {
                                afficher_personnage_rondoudou(page,0,0,tabJoueur[z].colonne,tabJoueur[z].ligne);
                                tabJoueur[z].pm=rondoudouPm;
                            }
                        }
                        afficher_tout_arbre(page,tableau_affichage_arbre);
                        afficher_commande(page,tabJoueur,nbJoueurs,j);
                        if(((mouse_x>=(1100)&& mouse_x<=(1190))&& (mouse_y)>=(0)&& mouse_y<=(70))&&(mouse_b && 1))
                        {
                            while(test==1)
                            {
                                clear_bitmap(page);
                                blit(fond,page,0,0,0,0,1200,711);
                                AffichageBouton(quitter,quitterInv,fond,0,0,200,210,200,73);
                                AffichageBouton(reprendre,reprendreInv,fond,0,0,400,210,200,73);
                                if (((mouse_x>=(200)&& mouse_x<=(400))&& (mouse_y)>=(210)&& mouse_y<=(283))&&(mouse_b && 1))
                                {
                                    test=1;
                                }
                                show_mouse(page);
                                blit(page,screen,0,0,0,0,1200,711);
                            }
                        }
                        show_mouse(page);
                        blit(page,screen,0,0,0,0,1200,711);
                        time_t temps2=time(NULL);
                        if (difftime(temps2,temps1)>=15)
                        {
                            temps1=time(NULL);
                            j++;
                            rest(200);
                        }
                        if(((mouse_x>=(30*37)&& mouse_x<=((30*37)+130))&& (mouse_y)>=(620)&& mouse_y<=(620+115))&&(mouse_b && 1))
                        {
                            temps1=time(NULL);
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
}END_OF_MAIN();
