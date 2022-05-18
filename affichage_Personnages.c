#include "header.h"

void afficher_personnage_pikachu(BITMAP* buffer,int compteur,int cote,int x,int y)
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

void afficher_personnage_lucario(BITMAP* buffer,int compteur,int cote,int x,int y)
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

void afficher_personnage_ronflex(BITMAP* buffer,int compteur,int cote,int x,int y)
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

void afficher_personnage_rondoudou(BITMAP* buffer,int compteur,int cote,int x,int y)
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

void afficher_personnage_alakazam(BITMAP* buffer,int compteur,int cote,int x,int y)
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

/*void choix_placement (BITMAP* buffer,t_joueur joueur,int nbJoueurs)
{
    FONT* maPolice  = load_font("police_ecriture/calibri.pcx",NULL,NULL);
    for (int z=0; z<nbJoueurs; z++)
    {
        if (tabJoueur[z].numeroClasse==1)///Pikachu
        {
            //Demande le placement
            textprintf_centre(buffer,maPolice,700,500,makecol(255,255,0),"%s choisit ton placement", joueur.pseudo);

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
}*/
