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

    int violetCity=0;


    //DÃ©claration du tableau de case :
    int tableau_Cases[18][36] = {
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L1
    {1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L2
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},//L3
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L4
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L5
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},//L6
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},//L7
    {0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},//L8
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},//L9
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L10
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L11
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L12
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L13
    {1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L14
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L15
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L16
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},//L17
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//L18
    };
    ///Declaration des BITMAP
    BITMAP* fondMenu = load_bitmap("fondMenu.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");
    BITMAP* lucario = load_bitmap("lucario/lucario1.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou/rondoudou1.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikachu/pikachu1.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex/ronflex1.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam/alakazam1.bmp",NULL);


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
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond, i);
                    }
                }
                if(((mouse_x>=(520)&& mouse_x<=(520+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 3 joueurs
                {
                    nbJoueurs = 3;
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond, i);
                    }
                }
                if(((mouse_x>=(720)&& mouse_x<=(720+171))&& (mouse_y)>=(540)&& mouse_y<=(165+540))&&(mouse_b && 1))///Choix 4 joueurs
                {
                    nbJoueurs = 4;
                    for(i=0; i<nbJoueurs; i++)
                    {
                        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,page,&tabJoueur[i],violetCity,musiqueFond,i);
                    }
                }
                if (i==nbJoueurs)
                {
                    while(!key[KEY_ESC])
                    {
                        afficher_map(page);
                        afficher_arbre(page);
                        afficher_commande(page, &tabJoueur[1]);
                        show_mouse(page);
                        blit(page,screen,0,0,0,0,1200,711);
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
