#include "header.h"

void afficher_personnage_pikachu(BITMAP* buffer,int compteur,int cote,int x,int y, t_joueur joueur)
{
    //déclaratation de la taille des cases

    //Déclaration des variables pour pikachu de face
    BITMAP* pikaFace1 = load_bitmap("pikachu/pikaFace1.bmp",NULL);
    BITMAP* pikaFace2 = load_bitmap("pikachu/pikaFace2.bmp",NULL);
    BITMAP* pikaFace3 = load_bitmap("pikachu/pikaFace3.bmp",NULL);
    BITMAP* pikaFace4 = load_bitmap("pikachu/pikaFace4.bmp",NULL);
    BITMAP* tab_pikaFace[4] = {pikaFace1,pikaFace2,pikaFace3,pikaFace4};

    //Déclaration des variables pour pikachu de derrière
    BITMAP* pikaArriere1 = load_bitmap("pikachu/pikaArriere1.bmp",NULL);
    BITMAP* pikaArriere2 = load_bitmap("pikachu/pikaArriere2.bmp",NULL);
    BITMAP* pikaArriere3 = load_bitmap("pikachu/pikaArriere3.bmp",NULL);
    BITMAP* pikaArriere4 = load_bitmap("pikachu/pikaArriere4.bmp",NULL);
    BITMAP* tab_pikaArriere[4] = {pikaArriere1,pikaArriere2,pikaArriere3,pikaArriere4};

    //Déclaration des variables pour pikachu de gauche
    BITMAP* pikaGauche1 = load_bitmap("pikachu/pikaGauche1.bmp",NULL);
    BITMAP* pikaGauche2 = load_bitmap("pikachu/pikaGauche2.bmp",NULL);
    BITMAP* pikaGauche3 = load_bitmap("pikachu/pikaGauche3.bmp",NULL);
    BITMAP* pikaGauche4 = load_bitmap("pikachu/pikaGauche4.bmp",NULL);
    BITMAP* tab_pikaGauche[4] = {pikaGauche1,pikaGauche2,pikaGauche3,pikaGauche4};

    //Déclaration des variables pour pikachu de droite
    BITMAP* pikaDroite1 = load_bitmap("pikachu/pikaDroite1.bmp",NULL);
    BITMAP* pikaDroite2 = load_bitmap("pikachu/pikaDroite2.bmp",NULL);
    BITMAP* pikaDroite3 = load_bitmap("pikachu/pikaDroite3.bmp",NULL);
    BITMAP* pikaDroite4 = load_bitmap("pikachu/pikaDroite4.bmp",NULL);
    BITMAP* tab_pikaDroite[4] = {pikaDroite1,pikaDroite2,pikaDroite3,pikaDroite4};

    BITMAP* rouge = load_bitmap("Statut/equipeRouge.bmp",NULL);
    BITMAP* bleu = load_bitmap("Statut/equipeBleue.bmp",NULL);
    BITMAP* vert = load_bitmap("Statut/equipeVerte.bmp",NULL);
    BITMAP* jaune = load_bitmap("Statut/equipeJaune.bmp",NULL);

    if(joueur.equipe == 1)
    {
        stretch_blit(rouge,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 2)
    {
        stretch_blit(bleu,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 3)
    {
        stretch_blit(vert,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 4)
    {
        stretch_blit(jaune,buffer,0,0,90,5,x,y+35,30,5);
    }


    if(cote == 0)
    {
        masked_stretch_blit(tab_pikaFace[compteur],buffer,0,0,tab_pikaFace[compteur]->w,tab_pikaFace[compteur]->h,x-10,y-10,(tab_pikaFace[compteur]->w)*1.5,(tab_pikaFace[compteur]->h)*1.5);
    }
    if(cote == 1)
    {
        masked_stretch_blit(tab_pikaArriere[compteur],buffer,0,0,tab_pikaArriere[compteur]->w,tab_pikaArriere[compteur]->h,x-10,y-10,(tab_pikaArriere[compteur]->w)*1.5,(tab_pikaArriere[compteur]->h)*1.5);
    }
    if(cote == 2)
    {
        masked_stretch_blit(tab_pikaGauche[compteur],buffer,0,0,tab_pikaGauche[compteur]->w,tab_pikaGauche[compteur]->h,x-10,y-10,(tab_pikaGauche[compteur]->w)*1.5,(tab_pikaGauche[compteur]->h)*1.5);
    }
    if(cote == 3)
    {
        masked_stretch_blit(tab_pikaDroite[compteur],buffer,0,0,tab_pikaDroite[compteur]->w,tab_pikaDroite[compteur]->h,x-10,y-10,(tab_pikaDroite[compteur]->w)*1.5,(tab_pikaDroite[compteur]->h)*1.5);
    }

}

void attaque_Pikachu(BITMAP* page)
{
    BITMAP* pika1 = load_bitmap("pikachu\pikaAttaque1.bmp",NULL);
    BITMAP* pika2 = load_bitmap("pikachu\pikaAttaque2.bmp",NULL);
    BITMAP* pika3 = load_bitmap("pikachu\pikaAttaque3.bmp",NULL);
    BITMAP* pika4 = load_bitmap("pikachu\pikaAttaque4.bmp",NULL);
    BITMAP* pika5 = load_bitmap("pikachu\pikaAttaque5.bmp",NULL);
    BITMAP* pika6 = load_bitmap("pikachu\pikaAttaque6.bmp",NULL);
    BITMAP* pika7 = load_bitmap("pikachu\pikaAttaque7.bmp",NULL);
    BITMAP* pika8 = load_bitmap("pikachu\pikaAttaque8.bmp",NULL);
    BITMAP* pika9 = load_bitmap("pikachu\pikaAttaque9.bmp",NULL);
    BITMAP* pika10 = load_bitmap("pikachu\pikaAttaque10.bmp",NULL);
    BITMAP* pika11 = load_bitmap("pikachu\pikaAttaque11.bmp",NULL);
    BITMAP* pika12 = load_bitmap("pikachu\pikaAttaque12.bmp",NULL);
    BITMAP* pika13 = load_bitmap("pikachu\pikaAttaque13.bmp",NULL);
    BITMAP* pika14 = load_bitmap("pikachu\pikaAttaque14.bmp",NULL);
    BITMAP* pika15 = load_bitmap("pikachu\pikaAttaque15.bmp",NULL);

    BITMAP* tab_attaque_pika[15] = {pika1,pika2,pika3,pika4,pika5,pika6,pika7,pika8,pika9,pika10,pika11,pika12,pika13,pika14,pika15};

    for (int i=0;i<15;i++)
    {
        clear_bitmap(page);
        printf("%d",i);
        blit(tab_attaque_pika[i],page,0,0,0,0,1200,711);

        blit(page,screen,0,0,0,0,1200,711);
        rest(30);
    }


}

void afficher_personnage_lucario(BITMAP* buffer,int compteur,int cote,int x,int y, t_joueur joueur)
{
    //Déclaration des variables pour lucario de face
    BITMAP* lucarioFace1 = load_bitmap("lucario/lucarioFace1.bmp",NULL);
    BITMAP* lucarioFace2 = load_bitmap("lucario/lucarioFace2.bmp",NULL);
    BITMAP* lucarioFace3 = load_bitmap("lucario/lucarioFace3.bmp",NULL);
    BITMAP* lucarioFace4 = load_bitmap("lucario/lucarioFace4.bmp",NULL);
    BITMAP* tab_lucarioFace[4] = {lucarioFace1,lucarioFace2,lucarioFace3,lucarioFace4};

    //Déclaration des variables pour lucario de derrière
    BITMAP* lucarioArriere1 = load_bitmap("lucario/lucarioArriere1.bmp",NULL);
    BITMAP* lucarioArriere2 = load_bitmap("lucario/lucarioArriere2.bmp",NULL);
    BITMAP* lucarioArriere3 = load_bitmap("lucario/lucarioArriere3.bmp",NULL);
    BITMAP* lucarioArriere4 = load_bitmap("lucario/lucarioArriere4.bmp",NULL);
    BITMAP* tab_lucarioArriere[4] = {lucarioArriere1,lucarioArriere2,lucarioArriere3,lucarioArriere4};

    //Déclaration des variables pour lucario de gauche
    BITMAP* lucarioGauche1 = load_bitmap("lucario/lucarioGauche1.bmp",NULL);
    BITMAP* lucarioGauche2 = load_bitmap("lucario/lucarioGauche2.bmp",NULL);
    BITMAP* lucarioGauche3 = load_bitmap("lucario/lucarioGauche3.bmp",NULL);
    BITMAP* lucarioGauche4 = load_bitmap("lucario/lucarioGauche4.bmp",NULL);
    BITMAP* tab_lucarioGauche[4] = {lucarioGauche1,lucarioGauche2,lucarioGauche3,lucarioGauche4};

    //Déclaration des variables pour lucario de droite
    BITMAP* lucarioDroite1 = load_bitmap("lucario/lucarioDroite1.bmp",NULL);
    BITMAP* lucarioDroite2 = load_bitmap("lucario/lucarioDroite2.bmp",NULL);
    BITMAP* lucarioDroite3 = load_bitmap("lucario/lucarioDroite3.bmp",NULL);
    BITMAP* lucarioDroite4 = load_bitmap("lucario/lucarioDroite4.bmp",NULL);
    BITMAP* tab_lucarioDroite[4] = {lucarioDroite1,lucarioDroite2,lucarioDroite3,lucarioDroite4};

    BITMAP* rouge = load_bitmap("Statut/equipeRouge.bmp",NULL);
    BITMAP* bleu = load_bitmap("Statut/equipeBleue.bmp",NULL);
    BITMAP* vert = load_bitmap("Statut/equipeVerte.bmp",NULL);
    BITMAP* jaune = load_bitmap("Statut/equipeJaune.bmp",NULL);


    if(joueur.equipe == 1)
    {
        stretch_blit(rouge,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 2)
    {
        stretch_blit(bleu,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 3)
    {
        stretch_blit(vert,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 4)
    {
        stretch_blit(jaune,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(cote == 0)
    {
        masked_stretch_blit(tab_lucarioFace[compteur],buffer,0,0,tab_lucarioFace[compteur]->w,tab_lucarioFace[compteur]->h,x-10,y-10,(tab_lucarioFace[compteur]->w)*1.5,(tab_lucarioFace[compteur]->h)*1.5);
    }
    if(cote == 1)
    {
        masked_stretch_blit(tab_lucarioArriere[compteur],buffer,0,0,tab_lucarioArriere[compteur]->w,tab_lucarioArriere[compteur]->h,x-10,y-10,(tab_lucarioArriere[compteur]->w)*1.5,(tab_lucarioArriere[compteur]->h)*1.5);
    }
    if(cote == 2)
    {
        masked_stretch_blit(tab_lucarioGauche[compteur],buffer,0,0,tab_lucarioGauche[compteur]->w,tab_lucarioGauche[compteur]->h,x-10,y-10,(tab_lucarioGauche[compteur]->w)*1.5,(tab_lucarioGauche[compteur]->h)*1.5);
    }
    if(cote == 3)
    {
        masked_stretch_blit(tab_lucarioDroite[compteur],buffer,0,0,tab_lucarioDroite[compteur]->w,tab_lucarioDroite[compteur]->h,x-10,y-10,(tab_lucarioDroite[compteur]->w)*1.5,(tab_lucarioDroite[compteur]->h)*1.5);
    }

}

void afficher_attaque_ronflex(BITMAP* buffer)
{
    BITMAP* attaqueRonflex1 = load_bitmap("ronflex/frame-01.bmp",NULL);
    BITMAP* attaqueRonflex2 = load_bitmap("ronflex/frame-02.bmp",NULL);
    BITMAP* attaqueRonflex3 = load_bitmap("ronflex/frame-03.bmp",NULL);
    BITMAP* attaqueRonflex4 = load_bitmap("ronflex/frame-04.bmp",NULL);
    BITMAP* attaqueRonflex5 = load_bitmap("ronflex/frame-05.bmp",NULL);
    BITMAP* attaqueRonflex6 = load_bitmap("ronflex/frame-06.bmp",NULL);
    BITMAP* attaqueRonflex7 = load_bitmap("ronflex/frame-07.bmp",NULL);
    BITMAP* attaqueRonflex8 = load_bitmap("ronflex/frame-08.bmp",NULL);
    BITMAP* attaqueRonflex9 = load_bitmap("ronflex/frame-09.bmp",NULL);
    BITMAP* attaqueRonflex10 = load_bitmap("ronflex/frame-10.bmp",NULL);
    BITMAP* attaqueRonflex11 = load_bitmap("ronflex/frame-11.bmp",NULL);
    BITMAP* attaqueRonflex12 = load_bitmap("ronflex/frame-12.bmp",NULL);
    BITMAP* attaqueRonflex13 = load_bitmap("ronflex/frame-13.bmp",NULL);
    BITMAP* attaqueRonflex14 = load_bitmap("ronflex/frame-14.bmp",NULL);
    BITMAP* attaqueRonflex15 = load_bitmap("ronflex/frame-15.bmp",NULL);
    BITMAP* attaqueRonflex16 = load_bitmap("ronflex/frame-16.bmp",NULL);
    BITMAP* attaqueRonflex17 = load_bitmap("ronflex/frame-17.bmp",NULL);
    BITMAP* attaqueRonflex18 = load_bitmap("ronflex/frame-18.bmp",NULL);
    BITMAP* attaqueRonflex19 = load_bitmap("ronflex/frame-19.bmp",NULL);
    BITMAP* attaqueRonflex20 = load_bitmap("ronflex/frame-20.bmp",NULL);
    BITMAP* attaqueRonflex21 = load_bitmap("ronflex/frame-21.bmp",NULL);
    BITMAP* attaqueRonflex22 = load_bitmap("ronflex/frame-22.bmp",NULL);
    BITMAP* attaqueRonflex23 = load_bitmap("ronflex/frame-23.bmp",NULL);
    BITMAP* attaqueRonflex24 = load_bitmap("ronflex/frame-24.bmp",NULL);
    BITMAP* attaqueRonflex25 = load_bitmap("ronflex/frame-25.bmp",NULL);

    BITMAP* tab[25] = {attaqueRonflex1,attaqueRonflex2,attaqueRonflex3,attaqueRonflex4,attaqueRonflex5,attaqueRonflex6,attaqueRonflex7,attaqueRonflex8,attaqueRonflex9,attaqueRonflex10,attaqueRonflex11,attaqueRonflex12,attaqueRonflex13,attaqueRonflex14,attaqueRonflex15,attaqueRonflex16,attaqueRonflex17,attaqueRonflex18,attaqueRonflex19,attaqueRonflex20,attaqueRonflex21,attaqueRonflex22,attaqueRonflex23,attaqueRonflex24,attaqueRonflex25};

    for(int i=0 ; i<25 ; i++)
    {
        stretch_blit(tab[i],buffer,0,0,tab[i]->w,tab[i]->h,0,0,1080,576);
        blit(buffer,screen,0,0,0,0,1200,711);
        rest(60);
    }
}

void afficher_attaque_rondoudou(BITMAP* buffer)
{
    BITMAP* attaquerondoudou1 = load_bitmap("rondoudou/rondoudouAttaque1.bmp",NULL);
    BITMAP* attaquerondoudou2 = load_bitmap("rondoudou/rondoudouAttaque2.bmp",NULL);
    BITMAP* attaquerondoudou3 = load_bitmap("rondoudou/rondoudouAttaque3.bmp",NULL);
    BITMAP* attaquerondoudou4 = load_bitmap("rondoudou/rondoudouAttaque4.bmp",NULL);
    BITMAP* attaquerondoudou5 = load_bitmap("rondoudou/rondoudouAttaque5.bmp",NULL);
    BITMAP* attaquerondoudou6 = load_bitmap("rondoudou/rondoudouAttaque6.bmp",NULL);
    BITMAP* attaquerondoudou7 = load_bitmap("rondoudou/rondoudouAttaque7.bmp",NULL);
    BITMAP* attaquerondoudou8 = load_bitmap("rondoudou/rondoudouAttaque8.bmp",NULL);
    BITMAP* attaquerondoudou9 = load_bitmap("rondoudou/rondoudouAttaque9.bmp",NULL);

    BITMAP* tab[9] = {attaquerondoudou1,attaquerondoudou2, attaquerondoudou3,attaquerondoudou4,attaquerondoudou5,attaquerondoudou6,attaquerondoudou7,attaquerondoudou8,attaquerondoudou9};
    for(int i=0 ; i<9 ; i++)
    {
        stretch_blit(tab[i],buffer,0,0,tab[i]->w,tab[i]->h,0,0,1080,576);
        blit(buffer,screen,0,0,0,0,1200,711);
        rest(60);
    }
}

void afficher_attaque_lucario(BITMAP* buffer)
{
    BITMAP* attaqueLucario1 = load_bitmap("lucario/frame-01.bmp",NULL);
    BITMAP* attaqueLucario2 = load_bitmap("lucario/frame-02.bmp",NULL);
    BITMAP* attaqueLucario3 = load_bitmap("lucario/frame-03.bmp",NULL);
    BITMAP* attaqueLucario4 = load_bitmap("lucario/frame-04.bmp",NULL);
    BITMAP* attaqueLucario5 = load_bitmap("lucario/frame-05.bmp",NULL);
    BITMAP* attaqueLucario6 = load_bitmap("lucario/frame-06.bmp",NULL);
    BITMAP* attaqueLucario7 = load_bitmap("lucario/frame-07.bmp",NULL);
    BITMAP* attaqueLucario8 = load_bitmap("lucario/frame-08.bmp",NULL);
    BITMAP* attaqueLucario9 = load_bitmap("lucario/frame-09.bmp",NULL);
    BITMAP* attaqueLucario10 = load_bitmap("lucario/frame-10.bmp",NULL);
    BITMAP* attaqueLucario11 = load_bitmap("lucario/frame-11.bmp",NULL);
    BITMAP* attaqueLucario12 = load_bitmap("lucario/frame-12.bmp",NULL);
    BITMAP* attaqueLucario13 = load_bitmap("lucario/frame-13.bmp",NULL);
    BITMAP* attaqueLucario14 = load_bitmap("lucario/frame-14.bmp",NULL);
    BITMAP* attaqueLucario15 = load_bitmap("lucario/frame-15.bmp",NULL);
    BITMAP* attaqueLucario16 = load_bitmap("lucario/frame-16.bmp",NULL);
    BITMAP* attaqueLucario17 = load_bitmap("lucario/frame-17.bmp",NULL);
    BITMAP* attaqueLucario18 = load_bitmap("lucario/frame-18.bmp",NULL);
    BITMAP* attaqueLucario19 = load_bitmap("lucario/frame-19.bmp",NULL);
    BITMAP* attaqueLucario20 = load_bitmap("lucario/frame-20.bmp",NULL);
    BITMAP* attaqueLucario21 = load_bitmap("lucario/frame-21.bmp",NULL);
    BITMAP* attaqueLucario22 = load_bitmap("lucario/frame-22.bmp",NULL);
    BITMAP* attaqueLucario23 = load_bitmap("lucario/frame-23.bmp",NULL);
    BITMAP* attaqueLucario24 = load_bitmap("lucario/frame-24.bmp",NULL);
    BITMAP* attaqueLucario25 = load_bitmap("lucario/frame-25.bmp",NULL);
    BITMAP* attaqueLucario26 = load_bitmap("lucario/frame-26.bmp",NULL);
    BITMAP* attaqueLucario27 = load_bitmap("lucario/frame-27.bmp",NULL);
    BITMAP* attaqueLucario28 = load_bitmap("lucario/frame-28.bmp",NULL);
    BITMAP* attaqueLucario29 = load_bitmap("lucario/frame-29.bmp",NULL);
    BITMAP* attaqueLucario30 = load_bitmap("lucario/frame-30.bmp",NULL);
    BITMAP* attaqueLucario31 = load_bitmap("lucario/frame-31.bmp",NULL);
    BITMAP* attaqueLucario32 = load_bitmap("lucario/frame-32.bmp",NULL);
    BITMAP* attaqueLucario33 = load_bitmap("lucario/frame-33.bmp",NULL);
    BITMAP* attaqueLucario34 = load_bitmap("lucario/frame-34.bmp",NULL);
    BITMAP* attaqueLucario35 = load_bitmap("lucario/frame-35.bmp",NULL);
    BITMAP* attaqueLucario36 = load_bitmap("lucario/frame-36.bmp",NULL);
    BITMAP* attaqueLucario37 = load_bitmap("lucario/frame-37.bmp",NULL);
    BITMAP* attaqueLucario38 = load_bitmap("lucario/frame-38.bmp",NULL);
    BITMAP* attaqueLucario39 = load_bitmap("lucario/frame-39.bmp",NULL);
    BITMAP* attaqueLucario40 = load_bitmap("lucario/frame-40.bmp",NULL);
    BITMAP* attaqueLucario41 = load_bitmap("lucario/frame-41.bmp",NULL);
    BITMAP* attaqueLucario42 = load_bitmap("lucario/frame-42.bmp",NULL);
    BITMAP* attaqueLucario43 = load_bitmap("lucario/frame-43.bmp",NULL);
    BITMAP* attaqueLucario44 = load_bitmap("lucario/frame-44.bmp",NULL);
    BITMAP* attaqueLucario45 = load_bitmap("lucario/frame-45.bmp",NULL);
    BITMAP* attaqueLucario46 = load_bitmap("lucario/frame-46.bmp",NULL);
    BITMAP* attaqueLucario47 = load_bitmap("lucario/frame-47.bmp",NULL);
    BITMAP* attaqueLucario48 = load_bitmap("lucario/frame-48.bmp",NULL);
    BITMAP* attaqueLucario49 = load_bitmap("lucario/frame-49.bmp",NULL);
    BITMAP* tab[49] = {attaqueLucario1,attaqueLucario2,attaqueLucario3,attaqueLucario4,attaqueLucario5,attaqueLucario6,attaqueLucario7,attaqueLucario8,attaqueLucario9,attaqueLucario10,attaqueLucario11,attaqueLucario12,attaqueLucario13,attaqueLucario14,attaqueLucario15,attaqueLucario16,attaqueLucario17,attaqueLucario18,attaqueLucario19,attaqueLucario20,attaqueLucario21,attaqueLucario22,attaqueLucario23,attaqueLucario24,attaqueLucario25,attaqueLucario26,attaqueLucario27,attaqueLucario28,attaqueLucario29,attaqueLucario30,attaqueLucario31,attaqueLucario32,attaqueLucario33,attaqueLucario34,attaqueLucario35,attaqueLucario36,attaqueLucario37,attaqueLucario38,attaqueLucario39,attaqueLucario40,attaqueLucario41,attaqueLucario42,attaqueLucario43,attaqueLucario44,attaqueLucario45,attaqueLucario46,attaqueLucario47,attaqueLucario48,attaqueLucario49};

    for(int i=0 ; i<49 ; i++)
    {
        stretch_blit(tab[i],buffer,0,0,tab[i]->w,tab[i]->h,0,0,1080,576);
        blit(buffer,screen,0,0,0,0,1200,711);
        rest(20);
    }
}

void afficher_attaque_alakazam(BITMAP* buffer)
{
    BITMAP* attaqueAlakazam1 = load_bitmap("alakazam/frame-01.bmp",NULL);
    BITMAP* attaqueAlakazam2 = load_bitmap("alakazam/frame-02.bmp",NULL);
    BITMAP* attaqueAlakazam3 = load_bitmap("alakazam/frame-03.bmp",NULL);
    BITMAP* attaqueAlakazam4 = load_bitmap("alakazam/frame-04.bmp",NULL);
    BITMAP* attaqueAlakazam5 = load_bitmap("alakazam/frame-05.bmp",NULL);
    BITMAP* attaqueAlakazam6 = load_bitmap("alakazam/frame-06.bmp",NULL);
    BITMAP* attaqueAlakazam7 = load_bitmap("alakazam/frame-07.bmp",NULL);
    BITMAP* attaqueAlakazam8 = load_bitmap("alakazam/frame-08.bmp",NULL);
    BITMAP* attaqueAlakazam9 = load_bitmap("alakazam/frame-09.bmp",NULL);
    BITMAP* attaqueAlakazam10 = load_bitmap("alakazam/frame-10.bmp",NULL);
    BITMAP* attaqueAlakazam11 = load_bitmap("alakazam/frame-11.bmp",NULL);
    BITMAP* attaqueAlakazam12 = load_bitmap("alakazam/frame-12.bmp",NULL);
    BITMAP* attaqueAlakazam13 = load_bitmap("alakazam/frame-13.bmp",NULL);
    BITMAP* attaqueAlakazam14 = load_bitmap("alakazam/frame-14.bmp",NULL);
    BITMAP* attaqueAlakazam15 = load_bitmap("alakazam/frame-15.bmp",NULL);
    BITMAP* attaqueAlakazam16 = load_bitmap("alakazam/frame-16.bmp",NULL);

    BITMAP* tab[16] = {attaqueAlakazam1,attaqueAlakazam2,attaqueAlakazam3,attaqueAlakazam4,attaqueAlakazam5,attaqueAlakazam6,attaqueAlakazam7,attaqueAlakazam8,attaqueAlakazam9,attaqueAlakazam10,attaqueAlakazam11,attaqueAlakazam12,attaqueAlakazam13,attaqueAlakazam14,attaqueAlakazam15,attaqueAlakazam16};

    for(int i=0 ; i<16 ; i++)
    {
        stretch_blit(tab[i],buffer,0,0,tab[i]->w,tab[i]->h,0,0,1080,576);
        blit(buffer,screen,0,0,0,0,1200,711);
        rest(60);
    }
}

void afficher_attaque_pikachu(BITMAP* buffer)
{
    BITMAP* pika1 = load_bitmap("pikachu/pikaAttaque1.bmp",NULL);
    BITMAP* pika2 = load_bitmap("pikachu/pikaAttaque2.bmp",NULL);
    BITMAP* pika3 = load_bitmap("pikachu/pikaAttaque3.bmp",NULL);
    BITMAP* pika4 = load_bitmap("pikachu/pikaAttaque4.bmp",NULL);
    BITMAP* pika5 = load_bitmap("pikachu/pikaAttaque5.bmp",NULL);
    BITMAP* pika6 = load_bitmap("pikachu/pikaAttaque6.bmp",NULL);
    BITMAP* pika7 = load_bitmap("pikachu/pikaAttaque7.bmp",NULL);
    BITMAP* pika8 = load_bitmap("pikachu/pikaAttaque8.bmp",NULL);
    BITMAP* pika9 = load_bitmap("pikachu/pikaAttaque9.bmp",NULL);
    BITMAP* pika10 = load_bitmap("pikachu/pikaAttaque10.bmp",NULL);
    BITMAP* pika11 = load_bitmap("pikachu/pikaAttaque11.bmp",NULL);
    BITMAP* pika12 = load_bitmap("pikachu/pikaAttaque12.bmp",NULL);
    BITMAP* pika13 = load_bitmap("pikachu/pikaAttaque13.bmp",NULL);
    BITMAP* pika14 = load_bitmap("pikachu/pikaAttaque14.bmp",NULL);
    BITMAP* pika15 = load_bitmap("pikachu/pikaAttaque15.bmp",NULL);
    BITMAP* tab_attaque_pika[15] = {pika1,pika2,pika3,pika4,pika5,pika6,pika7,pika8,pika9,pika10,pika11,pika12,pika13,pika14,pika15};

    for(int i=0 ; i<15 ; i++)
    {
        stretch_blit(tab_attaque_pika[i],buffer,0,0,tab_attaque_pika[i]->w,tab_attaque_pika[i]->h,0,0,1080,576);
        blit(buffer,screen,0,0,0,0,1200,711);
        rest(60);
    }

}
void afficher_personnage_ronflex(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur)
{
    //Déclaration des variables pour ronflex de face
    BITMAP* ronflexFace1 = load_bitmap("ronflex/ronflexFace1.bmp",NULL);
    BITMAP* ronflexFace2 = load_bitmap("ronflex/ronflexFace2.bmp",NULL);
    BITMAP* ronflexFace3 = load_bitmap("ronflex/ronflexFace3.bmp",NULL);
    BITMAP* ronflexFace4 = load_bitmap("ronflex/ronflexFace4.bmp",NULL);
    BITMAP* tab_ronflexFace[4] = {ronflexFace1,ronflexFace2,ronflexFace3,ronflexFace4};

    //Déclaration des variables pour ronflex de derrière
    BITMAP* ronflexArriere1 = load_bitmap("ronflex/ronflexArriere1.bmp",NULL);
    BITMAP* ronflexArriere2 = load_bitmap("ronflex/ronflexArriere2.bmp",NULL);
    BITMAP* ronflexArriere3 = load_bitmap("ronflex/ronflexArriere3.bmp",NULL);
    BITMAP* ronflexArriere4 = load_bitmap("ronflex/ronflexArriere4.bmp",NULL);
    BITMAP* tab_ronflexArriere[4] = {ronflexArriere1,ronflexArriere2,ronflexArriere3,ronflexArriere4};

    //Déclaration des variables pour ronflex de gauche
    BITMAP* ronflexGauche1 = load_bitmap("ronflex/ronflexGauche1.bmp",NULL);
    BITMAP* ronflexGauche2 = load_bitmap("ronflex/ronflexGauche2.bmp",NULL);
    BITMAP* ronflexGauche3 = load_bitmap("ronflex/ronflexGauche3.bmp",NULL);
    BITMAP* ronflexGauche4 = load_bitmap("ronflex/ronflexGauche4.bmp",NULL);
    BITMAP* tab_ronflexGauche[4] = {ronflexGauche1,ronflexGauche2,ronflexGauche3,ronflexGauche4};

    //Déclaration des variables pour ronflex de droite
    BITMAP* ronflexDroite1 = load_bitmap("ronflex/ronflexDroite1.bmp",NULL);
    BITMAP* ronflexDroite2 = load_bitmap("ronflex/ronflexDroite2.bmp",NULL);
    BITMAP* ronflexDroite3 = load_bitmap("ronflex/ronflexDroite3.bmp",NULL);
    BITMAP* ronflexDroite4 = load_bitmap("ronflex/ronflexDroite4.bmp",NULL);
    BITMAP* tab_ronflexDroite[4] = {ronflexDroite1,ronflexDroite2,ronflexDroite3,ronflexDroite4};


    BITMAP* rouge = load_bitmap("Statut/equipeRouge.bmp",NULL);
    BITMAP* bleu = load_bitmap("Statut/equipeBleue.bmp",NULL);
    BITMAP* vert = load_bitmap("Statut/equipeVerte.bmp",NULL);
    BITMAP* jaune = load_bitmap("Statut/equipeJaune.bmp",NULL);


    if(joueur.equipe == 1)
    {
        stretch_blit(rouge,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 2)
    {
        stretch_blit(bleu,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 3)
    {
        stretch_blit(vert,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 4)
    {
        stretch_blit(jaune,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(cote == 0)
    {
        masked_stretch_blit(tab_ronflexFace[compteur],buffer,0,0,tab_ronflexFace[compteur]->w,tab_ronflexFace[compteur]->h,x-10,y-10,(tab_ronflexFace[compteur]->w)*1.5,(tab_ronflexFace[compteur]->h)*1.5);
    }
    if(cote == 1)
    {
        masked_stretch_blit(tab_ronflexArriere[compteur],buffer,0,0,tab_ronflexArriere[compteur]->w,tab_ronflexArriere[compteur]->h,x-10,y-10,(tab_ronflexArriere[compteur]->w)*1.5,(tab_ronflexArriere[compteur]->h)*1.5);
    }
    if(cote == 2)
    {
        masked_stretch_blit(tab_ronflexGauche[compteur],buffer,0,0,tab_ronflexGauche[compteur]->w,tab_ronflexGauche[compteur]->h,x-10,y-10,(tab_ronflexGauche[compteur]->w)*1.5,(tab_ronflexGauche[compteur]->h)*1.5);
    }
    if(cote == 3)
    {
        masked_stretch_blit(tab_ronflexDroite[compteur],buffer,0,0,tab_ronflexDroite[compteur]->w,tab_ronflexDroite[compteur]->h,x-10,y-10,(tab_ronflexDroite[compteur]->w)*1.5,(tab_ronflexDroite[compteur]->h)*1.5);
    }

}

void afficher_personnage_rondoudou(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur)
{
    //Déclaration des variables pour rondoudou de face
    BITMAP* rondoudouFace1 = load_bitmap("rondoudou/rondoudouFace1.bmp",NULL);
    BITMAP* rondoudouFace2 = load_bitmap("rondoudou/rondoudouFace2.bmp",NULL);
    BITMAP* rondoudouFace3 = load_bitmap("rondoudou/rondoudouFace3.bmp",NULL);
    BITMAP* rondoudouFace4 = load_bitmap("rondoudou/rondoudouFace4.bmp",NULL);
    BITMAP* tab_rondoudouFace[4] = {rondoudouFace1,rondoudouFace2,rondoudouFace3,rondoudouFace4};

    //Déclaration des variables pour rondoudou de derrière
    BITMAP* rondoudouArriere1 = load_bitmap("rondoudou/rondoudouArriere1.bmp",NULL);
    BITMAP* rondoudouArriere2 = load_bitmap("rondoudou/rondoudouArriere2.bmp",NULL);
    BITMAP* rondoudouArriere3 = load_bitmap("rondoudou/rondoudouArriere3.bmp",NULL);
    BITMAP* rondoudouArriere4 = load_bitmap("rondoudou/rondoudouArriere4.bmp",NULL);
    BITMAP* tab_rondoudouArriere[4] = {rondoudouArriere1,rondoudouArriere2,rondoudouArriere3,rondoudouArriere4};

    //Déclaration des variables pour rondoudou de gauche
    BITMAP* rondoudouGauche1 = load_bitmap("rondoudou/rondoudouGauche1.bmp",NULL);
    BITMAP* rondoudouGauche2 = load_bitmap("rondoudou/rondoudouGauche2.bmp",NULL);
    BITMAP* rondoudouGauche3 = load_bitmap("rondoudou/rondoudouGauche3.bmp",NULL);
    BITMAP* rondoudouGauche4 = load_bitmap("rondoudou/rondoudouGauche4.bmp",NULL);
    BITMAP* tab_rondoudouGauche[4] = {rondoudouGauche1,rondoudouGauche2,rondoudouGauche3,rondoudouGauche4};

    //Déclaration des variables pour rondoudou de droite
    BITMAP* rondoudouDroite1 = load_bitmap("rondoudou/rondoudouDroite1.bmp",NULL);
    BITMAP* rondoudouDroite2 = load_bitmap("rondoudou/rondoudouDroite2.bmp",NULL);
    BITMAP* rondoudouDroite3 = load_bitmap("rondoudou/rondoudouDroite3.bmp",NULL);
    BITMAP* rondoudouDroite4 = load_bitmap("rondoudou/rondoudouDroite4.bmp",NULL);
    BITMAP* tab_rondoudouDroite[4] = {rondoudouDroite1,rondoudouDroite2,rondoudouDroite3,rondoudouDroite4};


    BITMAP* rouge = load_bitmap("Statut/equipeRouge.bmp",NULL);
    BITMAP* bleu = load_bitmap("Statut/equipeBleue.bmp",NULL);
    BITMAP* vert = load_bitmap("Statut/equipeVerte.bmp",NULL);
    BITMAP* jaune = load_bitmap("Statut/equipeJaune.bmp",NULL);


    if(joueur.equipe == 1)
    {
        stretch_blit(rouge,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 2)
    {
        stretch_blit(bleu,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 3)
    {
        stretch_blit(vert,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 4)
    {
        stretch_blit(jaune,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(cote == 0)
    {
        masked_stretch_blit(tab_rondoudouFace[compteur],buffer,0,0,tab_rondoudouFace[compteur]->w,tab_rondoudouFace[compteur]->h,x-10,y-10,(tab_rondoudouFace[compteur]->w)*1.5,(tab_rondoudouFace[compteur]->h)*1.5);
    }
    if(cote == 1)
    {
        masked_stretch_blit(tab_rondoudouArriere[compteur],buffer,0,0,tab_rondoudouArriere[compteur]->w,tab_rondoudouArriere[compteur]->h,x-10,y-10,(tab_rondoudouArriere[compteur]->w)*1.5,(tab_rondoudouArriere[compteur]->h)*1.5);
    }
    if(cote == 2)
    {
        masked_stretch_blit(tab_rondoudouGauche[compteur],buffer,0,0,tab_rondoudouGauche[compteur]->w,tab_rondoudouGauche[compteur]->h,x-10,y-10,(tab_rondoudouGauche[compteur]->w)*1.5,(tab_rondoudouGauche[compteur]->h)*1.5);
    }
    if(cote == 3)
    {
        masked_stretch_blit(tab_rondoudouDroite[compteur],buffer,0,0,tab_rondoudouDroite[compteur]->w,tab_rondoudouDroite[compteur]->h,x-10,y-10,(tab_rondoudouDroite[compteur]->w)*1.5,(tab_rondoudouDroite[compteur]->h)*1.5);
    }


}

void afficher_personnage_alakazam(BITMAP* buffer,int compteur,int cote,int x,int y,t_joueur joueur)
{
    //Déclaration des variables pour alakazam de face
    BITMAP* alakazamFace1 = load_bitmap("alakazam/alakazamFace1.bmp",NULL);
    BITMAP* alakazamFace2 = load_bitmap("alakazam/alakazamFace2.bmp",NULL);
    BITMAP* alakazamFace3 = load_bitmap("alakazam/alakazamFace3.bmp",NULL);
    BITMAP* alakazamFace4 = load_bitmap("alakazam/alakazamFace4.bmp",NULL);
    BITMAP* tab_alakazamFace[4] = {alakazamFace1,alakazamFace2,alakazamFace3,alakazamFace4};

    //Déclaration des variables pour alakazam de derrière
    BITMAP* alakazamArriere1 = load_bitmap("alakazam/alakazamArriere1.bmp",NULL);
    BITMAP* alakazamArriere2 = load_bitmap("alakazam/alakazamArriere2.bmp",NULL);
    BITMAP* alakazamArriere3 = load_bitmap("alakazam/alakazamArriere3.bmp",NULL);
    BITMAP* alakazamArriere4 = load_bitmap("alakazam/alakazamArriere4.bmp",NULL);
    BITMAP* tab_alakazamArriere[4] = {alakazamArriere1,alakazamArriere2,alakazamArriere3,alakazamArriere4};

    //Déclaration des variables pour alakazam de gauche
    BITMAP* alakazamGauche1 = load_bitmap("alakazam/alakazamGauche1.bmp",NULL);
    BITMAP* alakazamGauche2 = load_bitmap("alakazam/alakazamGauche2.bmp",NULL);
    BITMAP* alakazamGauche3 = load_bitmap("alakazam/alakazamGauche3.bmp",NULL);
    BITMAP* alakazamGauche4 = load_bitmap("alakazam/alakazamGauche4.bmp",NULL);
    BITMAP* tab_alakazamGauche[4] = {alakazamGauche1,alakazamGauche2,alakazamGauche3,alakazamGauche4};

    //Déclaration des variables pour alakazam de droite
    BITMAP* alakazamDroite1 = load_bitmap("alakazam/alakazamDroite1.bmp",NULL);
    BITMAP* alakazamDroite2 = load_bitmap("alakazam/alakazamDroite2.bmp",NULL);
    BITMAP* alakazamDroite3 = load_bitmap("alakazam/alakazamDroite3.bmp",NULL);
    BITMAP* alakazamDroite4 = load_bitmap("alakazam/alakazamDroite4.bmp",NULL);
    BITMAP* tab_alakazamDroite[4] = {alakazamDroite1,alakazamDroite2,alakazamDroite3,alakazamDroite4};


    BITMAP* rouge = load_bitmap("Statut/equipeRouge.bmp",NULL);
    BITMAP* bleu = load_bitmap("Statut/equipeBleue.bmp",NULL);
    BITMAP* vert = load_bitmap("Statut/equipeVerte.bmp",NULL);
    BITMAP* jaune = load_bitmap("Statut/equipeJaune.bmp",NULL);


    if(joueur.equipe == 1)
    {
        stretch_blit(rouge,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 2)
    {
        stretch_blit(bleu,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 3)
    {
        stretch_blit(vert,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(joueur.equipe == 4)
    {
        stretch_blit(jaune,buffer,0,0,90,5,x,y+35,30,5);
    }
    if(cote == 0)
    {
        masked_stretch_blit(tab_alakazamFace[compteur],buffer,0,0,tab_alakazamFace[compteur]->w,tab_alakazamFace[compteur]->h,x-10,y-10,(tab_alakazamFace[compteur]->w)*1.5,(tab_alakazamFace[compteur]->h)*1.5);
    }
    if(cote == 1)
    {
        masked_stretch_blit(tab_alakazamArriere[compteur],buffer,0,0,tab_alakazamArriere[compteur]->w,tab_alakazamArriere[compteur]->h,x-10,y-10,(tab_alakazamArriere[compteur]->w)*1.5,(tab_alakazamArriere[compteur]->h)*1.5);
    }
    if(cote == 2)
    {
        masked_stretch_blit(tab_alakazamGauche[compteur],buffer,0,0,tab_alakazamGauche[compteur]->w,tab_alakazamGauche[compteur]->h,x-10,y-10,(tab_alakazamGauche[compteur]->w)*1.5,(tab_alakazamGauche[compteur]->h)*1.5);
    }
    if(cote == 3)
    {
        masked_stretch_blit(tab_alakazamDroite[compteur],buffer,0,0,tab_alakazamDroite[compteur]->w,tab_alakazamDroite[compteur]->h,x-10,y-10,(tab_alakazamDroite[compteur]->w)*1.5,(tab_alakazamDroite[compteur]->h)*1.5);
    }

}

