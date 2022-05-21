#include "header.h"

void information_Pikachu(BITMAP* page, BITMAP* fond)
{
    int sortie = 0;
    //déclaration des variables
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* info_pika = load_bitmap("pikachu/fichepik.bmp",NULL);
    BITMAP* pika1 = load_bitmap("pikachu/pikachuInfo1.bmp",NULL);
    BITMAP* pika2 = load_bitmap("pikachu/pikachu2.bmp",NULL);
    BITMAP* tableauBitmapPikachu[2] = {pika1,pika2};

    //Declaration Bitmap Pikachu sorts
    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);
    BITMAP* infoscageE = load_bitmap("pikachu/InfosCageEclair.bmp",NULL);
    BITMAP* fatF = load_bitmap("pikachu/FatalFoudre.bmp",NULL);
    BITMAP* fatFInv = load_bitmap("pikachu/FatalFoudreInv.bmp",NULL);
    BITMAP* infosfatF = load_bitmap("pikachu/InfosFatalFoudre.bmp",NULL);
    BITMAP* boulE = load_bitmap("pikachu/BouleElek.bmp",NULL);
    BITMAP* boulEInv = load_bitmap("pikachu/BouleElekInv.bmp",NULL);
    BITMAP* infosboulE = load_bitmap("pikachu/InfosBouleElek.bmp",NULL);
    BITMAP* coupJ = load_bitmap("pikachu/CoupJus.bmp",NULL);
    BITMAP* coupJInv = load_bitmap("pikachu/CoupJusInv.bmp",NULL);
    BITMAP* infoscoupJ = load_bitmap("pikachu/InfosCoupJus.bmp",NULL);
    BITMAP* vitEx = load_bitmap("pikachu/VitesseExtreme.bmp",NULL);
    BITMAP* vitExInv = load_bitmap("pikachu/VitesseExtremeInv.bmp",NULL);
    BITMAP* infosvitEx = load_bitmap("pikachu/InfosVitesseExtreme.bmp",NULL);

    //Boucle d'affichage du gif
    while(sortie!=1)
    {
        clear_bitmap(page);
        stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
        masked_blit(tableauBitmapPikachu[0],page,0,0,600,200,500,490);
        masked_blit(info_pika,page,0,0,50,0,571,670);
        AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
        AffichageSorts2(cageE,cageEInv,infoscageE,page,0,0,380,350,75,54,200,70);
        AffichageSorts2(fatF,fatFInv,infosfatF,page,0,0,380,425,75,54,200,70);
        AffichageSorts2(boulE,boulEInv,infosboulE,page,0,0,380,475,75,54,200,70);
        AffichageSorts2(coupJ,coupJInv,infoscoupJ,page,0,0,380,525,75,54,200,70);
        AffichageSorts2(vitEx,vitExInv,infosvitEx,page,0,0,380,590,75,54,200,70);

        //textprintf_ex(page,maPolice,0,0,makecol(255,255,0),-1,"%d","%d",mouse_x,mouse_y);
        show_mouse(page);
        if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
        blit(page,screen,0,0,0,0,1200,711);
        rest(75);

        clear_bitmap(page);
        stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
        masked_blit(tableauBitmapPikachu[1],page,0,0,600,200,500,500);
        masked_blit(info_pika,page,0,0,50,0,571,670);
        AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
        AffichageSorts2(cageE,cageEInv,infoscageE,page,0,0,380,350,75,54,200,70);
        AffichageSorts2(fatF,fatFInv,infosfatF,page,0,0,380,425,75,54,200,70);
        AffichageSorts2(boulE,boulEInv,infosboulE,page,0,0,380,475,75,54,200,70);
        AffichageSorts2(coupJ,coupJInv,infoscoupJ,page,0,0,380,525,75,54,200,70);
        AffichageSorts2(vitEx,vitExInv,infosvitEx,page,0,0,380,590,75,54,200,70);

        show_mouse(page);
        if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
        blit(page,screen,0,0,0,0,1200,711);
        rest(75);
    }
}

void information_Ronflex(BITMAP* page, BITMAP* fond)
{
    int sortie = 0;
    //déclaration des variables
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

    //Declarations BITMAP sorts
    BITMAP* coupB = load_bitmap("ronflex/CoupBoule.bmp",NULL);
    BITMAP* coupBInv = load_bitmap("ronflex/CoupBouleInv.bmp",NULL);
    BITMAP* infoscoupB = load_bitmap("ronflex/InfosCoupBoule.bmp",NULL);
    BITMAP* seisme = load_bitmap("ronflex/Seisme.bmp",NULL);
    BITMAP* seismeInv = load_bitmap("ronflex/SeismeInv.bmp",NULL);
    BITMAP* infosseisme = load_bitmap("ronflex/InfosSeisme.bmp",NULL);
    BITMAP* charge = load_bitmap("ronflex/Charge.bmp",NULL);
    BITMAP* chargeInv = load_bitmap("ronflex/ChargeInv.bmp",NULL);
    BITMAP* infoscharge = load_bitmap("ronflex/InfosCharge.bmp",NULL);
    BITMAP* boulA = load_bitmap("ronflex/BoulArmure.bmp",NULL);
    BITMAP* boulAInv = load_bitmap("ronflex/BoulArmureInv.bmp",NULL);
    BITMAP* infosboulA = load_bitmap("ronflex/InfosBoulArmure.bmp",NULL);
    BITMAP* repos = load_bitmap("ronflex/Repos.bmp",NULL);
    BITMAP* reposInv = load_bitmap("ronflex/ReposInv.bmp",NULL);
    BITMAP* infosrepos = load_bitmap("ronflex/InfosRepos.bmp",NULL);

    //boucle d'affichage du gif
    while(sortie!=1)
    {
        for(int i=0;i<6;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
            masked_stretch_blit(info_ronf,page,0,0,571,668,50,0,571,670);
            masked_stretch_blit(tableau_ronflex[i],page,0,0,600,580,700,275,400,400);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            AffichageSorts2(coupB,coupBInv,infoscoupB,page,0,0,380,330,75,54,200,70);
            AffichageSorts2(seisme,seismeInv,infosseisme,page,0,0,380,385,75,54,200,70);
            AffichageSorts2(charge,chargeInv,infoscharge,page,0,0,380,460,75,54,200,70);
            AffichageSorts2(boulA,boulAInv,infosboulA,page,0,0,380,530,75,54,200,70);
            AffichageSorts2(repos,reposInv,infosrepos,page,0,0,380,585,75,54,200,70);

            show_mouse(page);
            if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
            blit(page,screen,0,0,0,0,1200,711);
            rest(100);
        }
    }
}

void information_Lucario(BITMAP* page, BITMAP* fond)
{
    int sortie = 0;
    //déclaration des variables
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

    //Declaration Bitmap Lucario sorts
    BITMAP* rugis = load_bitmap("lucario/Rugissement.bmp",NULL);
    BITMAP* rugisInv = load_bitmap("lucario/RugissementInv.bmp",NULL);
    BITMAP* infosrugis = load_bitmap("lucario/InfosRugissement.bmp",NULL);
    BITMAP* aura = load_bitmap("lucario/Aurasphere.bmp",NULL);
    BITMAP* auraInv = load_bitmap("lucario/AurasphereInv.bmp",NULL);
    BITMAP* infosaura = load_bitmap("lucario/InfosAurasphere.bmp",NULL);
    BITMAP* closeC = load_bitmap("lucario/CloseCombat.bmp",NULL);
    BITMAP* closeCInv = load_bitmap("lucario/CloseCombatInv.bmp",NULL);
    BITMAP* infoscloseC = load_bitmap("lucario/InfosCloseCombat.bmp",NULL);
    BITMAP* vitExL = load_bitmap("lucario/VitesseExtreme.bmp",NULL);
    BITMAP* vitExLInv = load_bitmap("lucario/VitesseExtremeInv.bmp",NULL);
    BITMAP* infosvitExL = load_bitmap("lucario/InfosVitesseExtreme.bmp",NULL);
    BITMAP* hate = load_bitmap("lucario/Hate.bmp",NULL);
    BITMAP* hateInv = load_bitmap("lucario/HateInv.bmp",NULL);
    BITMAP* infoshate = load_bitmap("lucario/InfosHate.bmp",NULL);

    //boucle d'affichage du gif
    while(sortie!=1)
    {
        for(int i=0;i<25;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
            masked_stretch_blit(tableau_lucario[i],page,0,0,192,192,500,25,700,700);
            masked_stretch_blit(info_luca,page,0,0,582,694,50,0,571,670);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            AffichageSorts2(rugis,rugisInv,infosrugis,page,0,0,380,330,75,54,200,70);
            AffichageSorts2(aura,auraInv,infosaura,page,0,0,380,415,75,54,200,70);
            AffichageSorts2(closeC,closeCInv,infoscloseC,page,0,0,380,465,75,54,200,70);
            AffichageSorts2(vitExL,vitExLInv,infosvitExL,page,0,0,380,535,75,54,200,70);
            AffichageSorts2(hate,hateInv,infoshate,page,0,0,380,585,75,54,200,70);
            show_mouse(page);
            if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
            blit(page,screen,0,0,0,0,1200,711);
            rest(75);
        }
    }
}


void information_Alakazam(BITMAP* page, BITMAP* fond)
{
    //déclaration des variables
    int sortie = 0;
    BITMAP* info_al = load_bitmap("alakazam/ficheAl.bmp",NULL);
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
    BITMAP* tableau_alakazam[17] = {alakazam1,alakazam2,alakazam3,alakazam4,alakazam5,alakazam6,alakazam7,alakazam8,alakazam9,alakazam10,alakazam11,alakazam12,alakazam13,alakazam14,alakazam15,alakazam16,alakazam17};

    //Declaration Bitmap Alakazam sorts
    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);
    BITMAP* infoscageE = load_bitmap("pikachu/InfosCageEclair.bmp",NULL);
    BITMAP* toxic = load_bitmap("alakazam/Toxic.bmp",NULL);
    BITMAP* toxicInv = load_bitmap("alakazam/ToxicInv.bmp",NULL);
    BITMAP* infostoxic = load_bitmap("alakazam/InfosToxic.bmp",NULL);
    BITMAP* psyko = load_bitmap("alakazam/Psyko.bmp",NULL);
    BITMAP* psykoInv = load_bitmap("alakazam/PsykoInv.bmp",NULL);
    BITMAP* infospsyko = load_bitmap("alakazam/InfosPsyko.bmp",NULL);
    BITMAP* teleport = load_bitmap("alakazam/Teleport.bmp",NULL);
    BITMAP* teleportInv = load_bitmap("alakazam/TeleportInv.bmp",NULL);
    BITMAP* infosteleport = load_bitmap("alakazam/InfosTeleport.bmp",NULL);
    BITMAP* autoSoin = load_bitmap("alakazam/AutoSoin.bmp",NULL);
    BITMAP* autoSoinInv = load_bitmap("alakazam/AutoSoinInv.bmp",NULL);
    BITMAP* infosautoSoin = load_bitmap("alakazam/InfosAutoSoin.bmp",NULL);

    //boucle d'affichage du gif
    while(sortie!=1)
    {
        for(int i=0;i<17;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
            masked_stretch_blit(tableau_alakazam[i],page,0,0,570,560,600,180,500,500);
            masked_stretch_blit(info_al,page,0,0,573,696,50,0,571,670);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            AffichageSorts2(cageE,cageEInv,infoscageE,page,0,0,380,320,75,54,200,70);
            AffichageSorts2(toxic,toxicInv,infostoxic,page,0,0,380,375,75,54,200,70);
            AffichageSorts2(psyko,psykoInv,infospsyko,page,0,0,380,435,75,54,200,70);
            AffichageSorts2(teleport,teleportInv,infosteleport,page,0,0,380,495,75,54,200,70);
            AffichageSorts2(autoSoin,autoSoinInv,infosautoSoin,page,0,0,380,570,75,54,200,70);
            show_mouse(page);
            if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
            blit(page,screen,0,0,0,0,1200,711);
            rest(50);
        }
        for(int i=16;i>0;i--)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
            masked_stretch_blit(tableau_alakazam[i],page,0,0,570,560,600,180,500,500);
            masked_stretch_blit(info_al,page,0,0,573,696,50,0,571,670);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            AffichageSorts2(cageE,cageEInv,infoscageE,page,0,0,380,320,75,54,200,70);
            AffichageSorts2(toxic,toxicInv,infostoxic,page,0,0,380,375,75,54,200,70);
            AffichageSorts2(psyko,psykoInv,infospsyko,page,0,0,380,435,75,54,200,70);
            AffichageSorts2(teleport,teleportInv,infosteleport,page,0,0,380,495,75,54,200,70);
            AffichageSorts2(autoSoin,autoSoinInv,infosautoSoin,page,0,0,380,570,75,54,200,70);
            show_mouse(page);
            if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
            blit(page,screen,0,0,0,0,1200,711);
            rest(50);
        }
    }
}


void information_Rondoudou(BITMAP* page, BITMAP* fond)
{
    //déclaration des variables
    int sortie = 0;
    BITMAP* info_rond = load_bitmap("rondoudou/ficheRon.bmp",NULL);
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* rondoudou1 = load_bitmap("rondoudou/frame1.bmp",NULL);
    BITMAP* rondoudou2 = load_bitmap("rondoudou/frame2.bmp",NULL);
    BITMAP* rondoudou3 = load_bitmap("rondoudou/frame3.bmp",NULL);
    BITMAP* rondoudou4 = load_bitmap("rondoudou/frame4.bmp",NULL);
    BITMAP* rondoudou5 = load_bitmap("rondoudou/frame5.bmp",NULL);
    BITMAP* rondoudou6 = load_bitmap("rondoudou/frame6.bmp",NULL);
    BITMAP* rondoudou7 = load_bitmap("rondoudou/frame7.bmp",NULL);
    BITMAP* rondoudou8 = load_bitmap("rondoudou/frame8.bmp",NULL);
    BITMAP* rondoudou9 = load_bitmap("rondoudou/frame9.bmp",NULL);
    BITMAP* rondoudou10 = load_bitmap("rondoudou/frame10.bmp",NULL);
    BITMAP* rondoudou11 = load_bitmap("rondoudou/frame11.bmp",NULL);
    BITMAP* rondoudou12 = load_bitmap("rondoudou/frame12.bmp",NULL);
    BITMAP* rondoudou13 = load_bitmap("rondoudou/frame13.bmp",NULL);
    BITMAP* rondoudou14 = load_bitmap("rondoudou/frame14.bmp",NULL);
    BITMAP* rondoudou15 = load_bitmap("rondoudou/frame15.bmp",NULL);
    BITMAP* tableau_rondoudou[15] = {rondoudou1,rondoudou2,rondoudou3,rondoudou4,rondoudou5,rondoudou6,rondoudou7,rondoudou8,rondoudou9,rondoudou10,rondoudou11,rondoudou12,rondoudou13,rondoudou14,rondoudou15};

    //Declaration Bitmap Rondoudou sorts
    BITMAP* berceuse = load_bitmap("rondoudou/Berceuse.bmp",NULL);
    BITMAP* berceuseInv = load_bitmap("rondoudou/BerceuseInv.bmp",NULL);
    BITMAP* infosberceuse = load_bitmap("rondoudou/InfosBerceuse.bmp",NULL);
    BITMAP* vaguePsy = load_bitmap("rondoudou/VaguePsy.bmp",NULL);
    BITMAP* vaguePsyInv = load_bitmap("rondoudou/VaguePsyInv.bmp",NULL);
    BITMAP* infosvaguePsy = load_bitmap("rondoudou/InfosVaguePsy.bmp",NULL);
    BITMAP* torgnoles = load_bitmap("rondoudou/Torgnoles.bmp",NULL);
    BITMAP* torgnolesInv = load_bitmap("rondoudou/TorgnolesInv.bmp",NULL);
    BITMAP* infostorgnoles = load_bitmap("rondoudou/InfosTorgnoles.bmp",NULL);
    BITMAP* teleport = load_bitmap("alakazam/Teleport.bmp",NULL);
    BITMAP* teleportInv = load_bitmap("alakazam/TeleportInv.bmp",NULL);
    BITMAP* infosteleport = load_bitmap("alakazam/InfosTeleport.bmp",NULL);
    BITMAP* soin = load_bitmap("rondoudou/Soin.bmp",NULL);
    BITMAP* soinInv = load_bitmap("rondoudou/SoinInv.bmp",NULL);
    BITMAP* infossoin = load_bitmap("rondoudou/InfosSoin.bmp",NULL);

    //boucle d'affichage du gif
    while(sortie!=1)
    {
        for(int i=0;i<15;i++)
        {
            clear_bitmap(page);
            stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
            masked_stretch_blit(tableau_rondoudou[i],page,0,0,tableau_rondoudou[i]->w,tableau_rondoudou[i]->h,711,330,350,350);
            masked_stretch_blit(info_rond,page,0,0,581,706,50,50,571,670);
            AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
            AffichageSorts2(berceuse,berceuseInv,infosberceuse,page,0,0,375,370,75,54,200,70);
            AffichageSorts2(vaguePsy,vaguePsyInv,infosvaguePsy,page,0,0,375,437,75,54,200,70);
            AffichageSorts2(torgnoles,torgnolesInv,infostorgnoles,page,0,0,370,490,75,54,200,70);
            AffichageSorts2(teleport,teleportInv,infosteleport,page,0,0,375,550,75,54,200,70);
            AffichageSorts2(soin,soinInv,infossoin,page,0,0,375,610,75,54,200,70);
            show_mouse(page);
            if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortie=1;
            }
            blit(page,screen,0,0,0,0,1200,711);
            rest(150);
        }
    }
}
