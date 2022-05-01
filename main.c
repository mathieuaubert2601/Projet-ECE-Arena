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
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");
    BITMAP* lucario = load_bitmap("lucario/lucario1.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou/rondoudou1.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikachu/pikatchu1.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex/ronflex1.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam/alakazam1.bmp",NULL);

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
        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,fond,page,&joueur1,&violetcity,musiqueFond);
        show_mouse(page);

        blit(page,screen,0,0,0,0,1200,711);*/
        afficher_map(page);
        afficher_arbre(page);
        afficher_coordonnees(page);
        afficher_personnage_alakazam(page,i,0,x,y);
        rest(100);
        x = x+3;
        i++;
        if(i==4)
        {
            i=0;
        }

        blit(page,screen,0,0,0,0,1200,711);
    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
