#include "header.h"

void choisir_nom()
{
    int compteur=0;
    /*allegro_init();
    install_keyboard();
    install_mouse();*/
    BITMAP*clavier;
    BITMAP*page;
    BITMAP*fondMenu;
    BITMAP*logo;
    BITMAP*phrase1;
    BITMAP*choixpseudo;
    BITMAP*barreNom;
    makecol(255, 0, 255);
    clavier=load_bitmap("clavier.bmp",NULL);
    page=create_bitmap(SCREEN_W,SCREEN_H);
    fondMenu=load_bitmap("fondMenu.bmp",NULL);
    logo=load_bitmap("logo_pokemon_bien.bmp",NULL);
    choixpseudo=load_bitmap("choixpseudo.bmp",NULL);
    barreNom=load_bitmap("barreNom.bmp",NULL);

    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        draw_sprite(page,fondMenu,0,0);
        masked_blit(clavier,page,0,0,190,250,SCREEN_W,SCREEN_H);
        masked_blit(barreNom,page,0,0,190,463,SCREEN_W,SCREEN_H);
        masked_blit(logo,page,0,0,300,0,SCREEN_W,SCREEN_H);
        masked_blit(choixpseudo,page,0,0,160,100,SCREEN_W,SCREEN_H);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);



    }


    }



//END_OF_MAIN();


