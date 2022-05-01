#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

    t_joueur joueur1;

    int violetcity=0;
    int x = 20;
    int y = 80;
    int i = 0;

    ///D�claration des BITMAP
    BITMAP* fond = load_bitmap("fond1.bmp",NULL);
    BITMAP* fondMenu = load_bitmap("fondMenu.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");

    BITMAP* logo = load_bitmap("logo.bmp",NULL);

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);


    while(!key[KEY_ESC])
    {
        clear_bitmap(page);/*
        if (violetcity==0)
        {
            play_sample(musiqueFond,200,0,1000,1);
            violetcity++;
        }

        menuJeu(page,fondMenu,logo);
        if(((mouse_x>=(375)&& mouse_x<=(375+444))&& (mouse_y)>=(500)&& mouse_y<=(156+500))&&(mouse_b && 1))
        {
            menuNbJoueur(page,fondMenu,logo,&violetcity);
        }
        show_mouse(page);

        blit(page,screen,0,0,0,0,1200,711);
        //afficher_map(page);
        //afficher_arbre(page);
        //afficher_coordonnees(page);*/
        afficher_caractere(page);
        blit(page,screen,0,0,0,0,1200,711);
        rest(20);

    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
