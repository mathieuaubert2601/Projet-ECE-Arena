#include "header.h"

void information_Pikachu(BITMAP* info_Pikachu)
{
    //déclaration des variables
    BITMAP* pika1 = load_bitmap("pikachuInfo1.bmp",NULL);
    BITMAP* pika2 = load_bitmap("pikachuInfo2.bmp",NULL);
    BITMAP* tableauBitmapPikachu[2] = {pika1,pika2};

    //Boucle d'affichage du gif
    while(!key[KEY_ESC])
    {
        clear_bitmap(info_Pikachu);
        masked_blit(tableauBitmapPikachu[0],info_Pikachu,0,0,0,0,500,490);
        blit(info_Pikachu,screen,0,0,0,0,1200,800);
        rest(750);

        clear_bitmap(info_Pikachu);
        masked_blit(tableauBitmapPikachu[1],info_Pikachu,0,0,0,0,500,500);
        blit(info_Pikachu,screen,0,0,0,0,1200,800);
        rest(750);
    }
}

void information_Lucario(BITMAP* info_Lucario)
{
    //déclaration des variables
    BITMAP* lucario1 = load_bitmap("lucario/frame1.bmp",NULL);
    BITMAP* lucario2 = load_bitmap("lucario/frame2.bmp",NULL);
    BITMAP* lucario3 = load_bitmap("lucario/frame3.bmp",NULL);
    BITMAP* lucario4 = load_bitmap("lucario/frame4.bmp",NULL);
    BITMAP* lucario5 = load_bitmap("lucario/frame5.bmp",NULL);
    BITMAP* lucario6 = load_bitmap("lucario/frame6.bmp",NULL);
    BITMAP* lucario7 = load_bitmap("lucario/frame7.bmp",NULL);
    BITMAP* lucario8 = load_bitmap("lucario/frame8.bmp",NULL);
    BITMAP* lucario9 = load_bitmap("lucario/frame9.bmp",NULL);
    BITMAP* lucario10 = load_bitmap("lucario/frame10.bmp",NULL);
    BITMAP* lucario11 = load_bitmap("lucario/frame11.bmp",NULL);
    BITMAP* lucario12 = load_bitmap("lucario/frame12.bmp",NULL);
    BITMAP* lucario13 = load_bitmap("lucario/frame13.bmp",NULL);
    BITMAP* lucario14 = load_bitmap("lucario/frame14.bmp",NULL);
    BITMAP* lucario15 = load_bitmap("lucario/frame15.bmp",NULL);
    BITMAP* lucario16 = load_bitmap("lucario/frame16.bmp",NULL);
    BITMAP* lucario17 = load_bitmap("lucario/frame17.bmp",NULL);
    BITMAP* lucario18 = load_bitmap("lucario/frame18.bmp",NULL);
    BITMAP* lucario19 = load_bitmap("lucario/frame19.bmp",NULL);
    BITMAP* lucario20 = load_bitmap("lucario/frame20.bmp",NULL);
    BITMAP* lucario21 = load_bitmap("lucario/frame21.bmp",NULL);
    BITMAP* lucario22 = load_bitmap("lucario/frame22.bmp",NULL);
    BITMAP* lucario23 = load_bitmap("lucario/frame23.bmp",NULL);
    BITMAP* lucario24 = load_bitmap("lucario/frame24.bmp",NULL);
    BITMAP* lucario25 = load_bitmap("lucario/frame25.bmp",NULL);
    BITMAP* tableau_lucario[25] = {lucario1,lucario2,lucario3,lucario4,lucario5,lucario6,lucario7,lucario8,lucario9,lucario10,lucario11,lucario12,lucario13,lucario14,lucario15,lucario16,lucario17,lucario18,lucario19,lucario20,lucario21,lucario22,lucario23,lucario24,lucario25};

    //boucle d'affichage du gif
    while(!key[KEY_ESC])
    {
        for(int i=0;i<25;i++)
        {
            clear_bitmap(info_Lucario);
            masked_stretch_blit(tableau_lucario[i],info_Lucario,0,0,192,192,0,0,500,500);
            blit(info_Lucario,screen,0,0,0,0,1200,800);
            rest(100);
        }
    }
}
