#include "header.h"

void information_Pikachu(BITMAP* page, BITMAP* fond)
{
    //d�claration des variables
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* info_pika = load_bitmap("pikachu/fichepik.bmp",NULL);
    BITMAP* pika1 = load_bitmap("pikachu/pikachuInfo1.bmp",NULL);
    BITMAP* pika2 = load_bitmap("pikachu/pikachu2.bmp",NULL);
    BITMAP* tableauBitmapPikachu[2] = {pika1,pika2};

    //Boucle d'affichage du gif
    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
        masked_blit(tableauBitmapPikachu[0],page,0,0,600,250,500,490);
        masked_blit(info_pika,page,0,0,50,50,571,670);
        AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,800);
        rest(75);

        clear_bitmap(page);
        stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
        masked_blit(tableauBitmapPikachu[1],page,0,0,600,250,500,500);
        masked_blit(info_pika,page,0,0,50,50,571,670);
        AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,800);
        rest(75);
    }
}

void information_Ronflex(BITMAP* page, BITMAP* fond)
{
    //d�claration des variables
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* info_ronf = load_bitmap("ronflex/ficheRonf.bmp",NULL);
    BITMAP* ronflex1 = load_bitmap("ronflex/frame1.bmp",NULL);
    BITMAP* ronflex2 = load_bitmap("ronflex/frame2.bmp",NULL);
    BITMAP* ronflex3 = load_bitmap("ronflex/frame3.bmp",NULL);
    BITMAP* ronflex4 = load_bitmap("ronflex/frame4.bmp",NULL);
    BITMAP* ronflex5 = load_bitmap("ronflex/frame5.bmp",NULL);
    BITMAP* ronflex6 = load_bitmap("ronflex/frame6.bmp",NULL);
    BITMAP* tableau_ronflex[6] = {ronflex1,ronflex2,ronflex3,ronflex4,ronflex5,ronflex6};

    //boucle d'affichage du gif
    while(!key[KEY_ESC])
    {
        for(int i=0;i<6;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
            masked_stretch_blit(info_ronf,page,0,0,373,450,50,50,571,670);
            masked_stretch_blit(tableau_ronflex[i],page,0,0,600,580,700,300,400,400);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,800);
            rest(100);
        }
    }
}

void information_Lucario(BITMAP* page, BITMAP* fond)
{
    //d�claration des variables
    BITMAP* info_luca = load_bitmap("lucario/ficheLu.bmp",NULL);
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
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
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
            masked_stretch_blit(tableau_lucario[i],page,0,0,192,192,500,75,700,700);
            masked_stretch_blit(info_luca,page,0,0,582,694,50,50,571,670);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,800);
            rest(75);
        }
    }
}


void information_Alakazam(BITMAP* page, BITMAP* fond)
{
    //d�claration des variables
    //BITMAP* info_al = load_bitmap("ronflex/ficheRonf.bmp",NULL);
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* alakazam1 = load_bitmap("alakazam/frame1.bmp",NULL);
    BITMAP* alakazam2 = load_bitmap("alakazam/frame2.bmp",NULL);
    BITMAP* alakazam3 = load_bitmap("alakazam/frame3.bmp",NULL);
    BITMAP* alakazam4 = load_bitmap("alakazam/frame4.bmp",NULL);
    BITMAP* alakazam5 = load_bitmap("alakazam/frame5.bmp",NULL);
    BITMAP* alakazam6 = load_bitmap("alakazam/frame6.bmp",NULL);
    BITMAP* alakazam7 = load_bitmap("alakazam/frame7.bmp",NULL);
    BITMAP* alakazam8 = load_bitmap("alakazam/frame8.bmp",NULL);
    BITMAP* alakazam9 = load_bitmap("alakazam/frame9.bmp",NULL);
    BITMAP* alakazam10 = load_bitmap("alakazam/frame10.bmp",NULL);
    BITMAP* alakazam11 = load_bitmap("alakazam/frame11.bmp",NULL);
    BITMAP* alakazam12 = load_bitmap("alakazam/frame12.bmp",NULL);
    BITMAP* alakazam13 = load_bitmap("alakazam/frame13.bmp",NULL);
    BITMAP* alakazam14 = load_bitmap("alakazam/frame14.bmp",NULL);
    BITMAP* alakazam15 = load_bitmap("alakazam/frame15.bmp",NULL);
    BITMAP* alakazam16 = load_bitmap("alakazam/frame16.bmp",NULL);
    BITMAP* alakazam17 = load_bitmap("alakazam/frame17.bmp",NULL);
    BITMAP* alakazam18 = load_bitmap("alakazam/frame18.bmp",NULL);
    BITMAP* alakazam19 = load_bitmap("alakazam/frame19.bmp",NULL);
    BITMAP* alakazam20 = load_bitmap("alakazam/frame20.bmp",NULL);
    BITMAP* alakazam21 = load_bitmap("alakazam/frame21.bmp",NULL);
    BITMAP* alakazam22 = load_bitmap("alakazam/frame22.bmp",NULL);
    BITMAP* alakazam23 = load_bitmap("alakazam/frame23.bmp",NULL);
    BITMAP* alakazam24 = load_bitmap("alakazam/frame24.bmp",NULL);
    BITMAP* alakazam25 = load_bitmap("alakazam/frame25.bmp",NULL);
    BITMAP* tableau_alakazam[17] = {alakazam1,alakazam2,alakazam3,alakazam4,alakazam5,alakazam6,alakazam7,alakazam8,alakazam9,alakazam10,alakazam11,alakazam12,alakazam13,alakazam14,alakazam15,alakazam16,alakazam17};

    //boucle d'affichage du gif
    while(!key[KEY_ESC])
    {
        for(int i=0;i<17;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
            masked_stretch_blit(tableau_alakazam[i],page,0,0,570,560,0,0,500,500);
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,800);
            rest(50);
        }
        for(int i=16;i>0;i--)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,800);
            masked_stretch_blit(tableau_alakazam[i],page,0,0,570,560,0,0,500,500);
            show_mouse(page);
            blit(page,screen,0,0,0,0,1200,800);
            rest(50);
        }
    }
}
