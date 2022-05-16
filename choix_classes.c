#include "header.h"
void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* page, t_joueur joueur[], int* violetCity, SAMPLE* musiqueFond, int nbJoueur, int tabCases[18][36], int t)
{
    int xRand ;
    int yRand ;
    do
    {
         xRand = rand()%35;
         yRand = rand()%17;
    }while(tabCases[yRand][xRand]==1);


    FONT* maPolice = load_font("police_ecriture/calibri.pcx",NULL,NULL);


    /*BITMAP* phrase1 = load_bitmap("phrases/phrase1.bmp",NULL);
    BITMAP* phrase2 = load_bitmap("phrases/phrase2.bmp",NULL);
    BITMAP* phrase3 = load_bitmap("phrases/phrase3.bmp",NULL);
    BITMAP* phrase4 = load_bitmap("phrases/phrase4.bmp",NULL);*/
    BITMAP* tabPhrases[4];
    BITMAP* corpsacorps = load_bitmap("CAC/corpsacorps.bmp",NULL);
    BITMAP* corpsacorpsInv = load_bitmap("CAC/corpsacorpsInv.bmp",NULL);
    BITMAP* infoscorps = load_bitmap("CAC/infoscorps.bmp",NULL);

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

    //Declaration Bitmap Ronflex sorts
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

    //Declaration Bitmap Alakazam sorts
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
    BITMAP* soin = load_bitmap("rondoudou/Soin.bmp",NULL);
    BITMAP* soinInv = load_bitmap("rondoudou/SoinInv.bmp",NULL);
    BITMAP* infossoin = load_bitmap("rondoudou/InfosSoin.bmp",NULL);

    ///Déclaration sorts
    t_sorts vitesseExtreme={0,0,0,80,2,0,3,0,7,3,0,0,vitEx,vitExInv,infosvitEx};
    t_sorts vitesseExtremeL={0,23,0,80,2,0,3,0,7,3,0,0,vitExL,vitExLInv,infosvitExL};
    t_sorts fatalFoudre={15,1,8,50,1,4,7,0,10,1,0,0,fatF,fatFInv,infosfatF};
    t_sorts bouleElek={10,2,5,75,1,3,5,2,6,2,0,0,boulE,boulEInv,infosboulE};
    t_sorts couDjus={6,3,4,90,1,2,5,0,3,3,0,0,coupJ,coupJInv,infoscoupJ};
    t_sorts cageEclair={0,4,0,25,3,2,4,0,7,3,3,0,cageE,cageEInv,infoscageE};
    t_sorts boulArmure={0,5,0,50,4,0,0,0,7,0,0,1,boulA,boulAInv,infosboulA};
    t_sorts reposS={100,6,25,60,4,0,0,0,10,0,1,2,repos,reposInv,infosrepos};
    t_sorts coupDboule={5,7,4,95,1,1,3,0,3,3,0,0,coupB,coupBInv,infoscoupB};
    t_sorts seismeS={9,8,15,50,1,1,4,0,10,3,0,0,seisme,seismeInv,infosseisme};
    t_sorts chargeS={0,9,0,50,2,0,5,0,7,3,0,0,charge,chargeInv,infoscharge};
    t_sorts rugissement={0,10,0,40,3,0,2,0,3,3,4,0,rugis,rugisInv,infosrugis};
    t_sorts aurasphere={12,11,5,75,1,3,6,0,6,1,0,0,aura,auraInv,infosaura};
    t_sorts closeCombat={15,12,3,60,1,1,3,0,6,3,0,0,closeC,closeCInv,infoscloseC};
    t_sorts hateS={0,13,0,70,2,0,0,0,4,0,0,0,hate,hateInv,infoshate};
    t_sorts toxicS={0,14,0,25,3,2,4,0,5,3,1,0,toxic,toxicInv,infostoxic};
    t_sorts psykoS={12,15,8,60,1,3,5,0,6,3,0,0,psyko,psykoInv,infospsyko};
    t_sorts teleportS={0,16,0,50,2,0,4,0,8,3,0,0,teleport,teleportInv,infosteleport};
    t_sorts autoSoinS={5,17,10,95,4,0,0,0,2,0,0,2,autoSoin,autoSoinInv,infosautoSoin};
    t_sorts vaguePsyS={7,18,5,80,1,2,8,0,5,1,0,0,vaguePsy,vaguePsyInv,infosvaguePsy};
    t_sorts torgnolesS={8,19,2,80,1,0,2,0,5,3,0,0,torgnoles,torgnolesInv,infostorgnoles};
    t_sorts soinS={50,20,10,75,2,0,2,0,10,3,0,3,soin,soinInv,infossoin};
    t_sorts berceuseS={0,21,0,50,2,0,3,0,6,3,2,0,berceuse,berceuseInv,infosberceuse};
    t_sorts corps={1,22,0,100,1,0,1,0,1,3,0,0,corpsacorps,corpsacorpsInv,infoscorps};

    t_sorts tabSorts[23]={vitesseExtreme,fatalFoudre,bouleElek,couDjus,cageEclair,boulArmure,reposS,coupDboule,seismeS,chargeS,rugissement,aurasphere,closeCombat,vitesseExtremeL,hateS,toxicS,psykoS,teleportS,autoSoinS,vaguePsyS,torgnolesS,soinS,berceuseS};

    SAMPLE* pikachuSon = load_sample("sons_pokemons/pikachu.wav");
    SAMPLE* ronflexSon = load_sample("sons_pokemons/ronflex.wav");
    SAMPLE* lucarioSon = load_sample("sons_pokemons/lucario.wav");
    SAMPLE* alakazamSon = load_sample("sons_pokemons/alakazam.wav");
    SAMPLE* rondoudouSon = load_sample("sons_pokemons/rondoudou.wav");

    t_classe pikachu;
    t_classe ronflex;
    t_classe lucario;
    t_classe alakazam;
    t_classe rondoudou;

    //Déclaration pikachu
    BITMAP* profilpik = load_bitmap("pikachu/profil.bmp",NULL);
    BITMAP* profilvertpik = load_bitmap("pikachu/profilvert.bmp",NULL);

    pikachu.classe = 1;
    strcpy(pikachu.nom,"Pikachu");
    pikachu.pm = 6;
    pikachu.pv = 75;
    pikachu.sonClasse = pikachuSon;
    pikachu.sort1=vitesseExtreme;
    pikachu.sort2=fatalFoudre;
    pikachu.sort3=bouleElek;
    pikachu.sort4=couDjus;
    pikachu.sort5=cageEclair;
    pikachu.profil=profilpik;
    pikachu.profilvert=profilvertpik;
    pikachu.corps=corps;

    //Déclaration ronflex
    BITMAP* profilronf = load_bitmap("ronflex/profil.bmp",NULL);
    BITMAP* profilvertronf = load_bitmap("ronflex/profilvert.bmp",NULL);

    ronflex.classe = 2;
    strcpy(ronflex.nom,"Ronflex");
    ronflex.pm = 2;
    ronflex.pv = 125;
    ronflex.sonClasse = ronflexSon;
    ronflex.sort1=boulArmure;
    ronflex.sort2=reposS;
    ronflex.sort3=coupDboule;
    ronflex.sort4=seismeS;
    ronflex.sort5=chargeS;
    ronflex.profil=profilronf;
    ronflex.profilvert=profilvertronf;
    ronflex.corps=corps;

    //Déclaration lucario
    BITMAP* profillu = load_bitmap("lucario/profil.bmp",NULL);
    BITMAP* profilvertlu = load_bitmap("lucario/profilvert.bmp",NULL);

    lucario.classe = 3;
    strcpy(lucario.nom,"Lucario");
    lucario.pm = 4;
    lucario.pv = 100;
    lucario.sonClasse = lucarioSon;
    lucario.sort1=rugissement;
    lucario.sort2=aurasphere;
    lucario.sort3=closeCombat;
    lucario.sort4=vitesseExtremeL;
    lucario.sort5=hateS;
    lucario.profil=profillu;
    lucario.profilvert=profilvertlu;
    lucario.corps=corps;

    //Déclaration alakazam
    BITMAP* profilal = load_bitmap("alakazam/profil.bmp",NULL);
    BITMAP* profilvertal = load_bitmap("alakazam/profilvert.bmp",NULL);

    alakazam.classe = 4;
    strcpy(alakazam.nom,"Alakazam");
    alakazam.pm = 3;
    alakazam.pv = 100;
    alakazam.sonClasse = alakazamSon;
    alakazam.sort1=cageEclair;
    alakazam.sort2=toxicS;
    alakazam.sort3=psykoS;
    alakazam.sort4=teleportS;
    alakazam.sort5=autoSoinS;
    alakazam.profil=profilal;
    alakazam.profilvert=profilvertal;
    alakazam.corps=corps;

    //Déclaration rondoudou
    BITMAP* profilron = load_bitmap("rondoudou/profil.bmp",NULL);
    BITMAP* profilvertron = load_bitmap("rondoudou/profilvert.bmp",NULL);

    rondoudou.classe = 5;
    strcpy(rondoudou.nom,"Rondoudou");
    rondoudou.pm = 5;
    rondoudou.pv = 75;
    rondoudou.sonClasse = rondoudouSon;
    rondoudou.sort1=vaguePsyS;
    rondoudou.sort2=torgnolesS;
    rondoudou.sort3=teleportS;
    rondoudou.sort4=soinS;
    rondoudou.sort5=berceuseS;
    rondoudou.profil=profilron;
    rondoudou.profilvert=profilvertron;
    rondoudou.corps=corps;

    int sortieClasses = 0;
    ///Déclaration des BITMAP
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);

    BITMAP* bouton1 = load_bitmap("boutons/boutonPik.bmp",NULL);
    BITMAP* boutonInv1 = load_bitmap("boutons/boutonInvPik.bmp",NULL);

    BITMAP* bouton2 = load_bitmap("boutons/boutonRonf.bmp",NULL);
    BITMAP* boutonInv2 = load_bitmap("boutons/boutonInvRonf.bmp",NULL);

    BITMAP* bouton3 = load_bitmap("boutons/boutonLu.bmp",NULL);
    BITMAP* boutonInv3 = load_bitmap("boutons/boutonInvLu.bmp",NULL);

    BITMAP* bouton4 = load_bitmap("boutons/boutonAl.bmp",NULL);
    BITMAP* boutonInv4 = load_bitmap("boutons/boutonInvAl.bmp",NULL);

    BITMAP* bouton5 = load_bitmap("boutons/boutonRon.bmp",NULL);
    BITMAP* boutonInv5 = load_bitmap("boutons/boutonInvRon.bmp",NULL);

    BITMAP* boutonI = load_bitmap("boutons/boutonInfos.bmp",NULL);
    BITMAP* boutonInvI = load_bitmap("boutons/boutonInvInfos.bmp",NULL);

    BITMAP* logo = load_bitmap("fond/logo.bmp",NULL);
    BITMAP* fond = load_bitmap("fond/fond1.bmp",NULL);
    BITMAP* fondMenu = load_bitmap("fond/fondMenu.bmp",NULL);

    rest(300);
    while(sortieClasses!=1)
    {
            ///Affichage des pok�mons
        stretch_blit(fond,page,0,0,640,360,0,0,1200,711);
        masked_stretch_blit(classe1,page,0,0,115,103,15,330,255,203);
        masked_stretch_blit(classe2,page,0,0,127,114,240,350,217,186);
        masked_stretch_blit(classe3,page,0,0,86,121,480,330,216,200);
        masked_stretch_blit(classe4,page,0,0,135,120,700,330,225,200);
        masked_stretch_blit(classe5,page,0,0,128,118,950,330,220,200);

        ///Affichage nom des pok�mons
        AffichageBouton(bouton1,boutonInv1,page,0,0,15,550,212,67);
        AffichageBouton(bouton2,boutonInv2,page,0,0,245,550,211,67);
        AffichageBouton(bouton3,boutonInv3,page,0,0,485,550,212,67);
        AffichageBouton(bouton4,boutonInv4,page,0,0,705,550,211,67);
        AffichageBouton(bouton5,boutonInv5,page,0,0,955,550,211,67);

        ///Affichage bouton infos
        AffichageBouton(boutonI,boutonInvI,page,0,0,68,625,100,50);
        AffichageBouton(boutonI,boutonInvI,page,0,0,300,625,100,50);
        AffichageBouton(boutonI,boutonInvI,page,0,0,550,625,100,50);
        AffichageBouton(boutonI,boutonInvI,page,0,0,765,625,100,50);
        AffichageBouton(boutonI,boutonInvI,page,0,0,1020,625,100,50);


        masked_stretch_blit(logo,page,0,0,755,374,300,5,600,300);

        textprintf_ex(page,maPolice,10,180,makecol(255,255,0),-1,"%s",joueur[t].pseudo);
        /*if(nbJoueur==0)
        {
            masked_stretch_blit(phrase1,page,0,0,phrase1->w,phrase1->h,5,50,300,38);
        }
        if(nbJoueur==1)
        {
            masked_stretch_blit(phrase2,page,0,0,phrase2->w,phrase2->h,5,50,300,38);
        }
        if(nbJoueur==2)
        {
            masked_stretch_blit(phrase3,page,0,0,phrase3->w,phrase3->h,5,50,300,38);
        }
        if(nbJoueur==3)
        {
            masked_stretch_blit(phrase4,page,0,0,phrase4->w,phrase4->h,5,50,300,38);
        }*/


        if(((mouse_x>=(68)&& mouse_x<=(68+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&& (mouse_b && 1))
        {
            information_Pikachu(page,fond);
        }
        if(((mouse_x>=(300)&& mouse_x<=(300+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
        {
            information_Ronflex(page,fond);
        }
        if(((mouse_x>=(550)&& mouse_x<=(550+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
        {
           information_Lucario(page,fond);
        }
        if(((mouse_x>=(765)&& mouse_x<=(765+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
        {
            information_Alakazam(page,fond);
        }
        if(((mouse_x>=(1020)&& mouse_x<=(1020+100))&& (mouse_y)>=(625)&& mouse_y<=(625+50))&&(mouse_b && 1))
        {
            information_Rondoudou(page,fond);
        }

        //Choix de Pikachu
        if((mouse_x>=(15) && mouse_x<=(227)) && (mouse_y)<=(617) && mouse_y>=(550))
        {
            if(mouse_b && 1)
            {
                joueur[t].classe=pikachu;
                joueur[t].pv = pikachu.pv;
                joueur[t].numero=nbJoueur;
                joueur[t].numeroClasse=1;
                joueur[t].colonne = xRand*30;
                joueur[t].ligne=yRand*32;
                //play_sample(joueur[t].classe.sonClasse,600,0,1000,0);
                sortieClasses=1;
            }
        }

        //Choix de Ronflex
        if((mouse_x<=(456) && mouse_x>=(245)) && (mouse_y)<=(617) && mouse_y>=(550))
        {
            if(mouse_b && 1)
            {
                joueur[t].classe=ronflex;
                joueur[t].pv = ronflex.pv;
                joueur[t].numero=nbJoueur;
                joueur[t].numeroClasse=2;
                joueur[t].colonne = xRand*30;
                joueur[t].ligne=yRand*32;
                //play_sample(joueur[t].classe.sonClasse,600,0,1000,0);
                sortieClasses=1;
            }
        }

        //Choix de Lucario
        if((mouse_x<=(697) && mouse_x>=(485)) && (mouse_y)<=(617) && mouse_y>=(550))
        {
            if(mouse_b && 1)
            {
                joueur[t].classe=lucario;
                joueur[t].pv = lucario.pv;
                joueur[t].numero=nbJoueur;
                joueur[t].numeroClasse=3;
                joueur[t].colonne = xRand*30;
                joueur[t].ligne=yRand*32;
                //play_sample(joueur[t].classe.sonClasse,600,0,1000,0);
                sortieClasses=1;
            }
        }

        //Choix d'Alakazam
        if((mouse_x<=(916) && mouse_x>=(705)) && (mouse_y)<=(617) && mouse_y>=(550))
        {
            if(mouse_b && 1)
            {
                joueur[t].classe=alakazam;
                joueur[t].pv = alakazam.pv;
                joueur[t].numero=nbJoueur;
                joueur[t].numeroClasse=4;
                joueur[t].colonne = xRand*30;
                joueur[t].ligne=yRand*32;
                //play_sample(joueur[t].classe.sonClasse,600,0,1000,0);
                sortieClasses=1;
            }
        }

        //Choix de Rondoudou
        if((mouse_x<=(1166) && mouse_x>=(955)) && (mouse_y)<=(617) && mouse_y>=(550))
        {
            if(mouse_b && 1)
            {
                joueur[t].classe=rondoudou;
                joueur[t].pv = rondoudou.pv;
                joueur[t].numero=nbJoueur;
                joueur[t].numeroClasse=5;
                joueur[t].colonne = xRand*30;
                joueur[t].ligne=yRand*32;
                //play_sample(joueur[t].classe.sonClasse,600,0,1000,0);
                sortieClasses=1;
            }
        }
        if(((mouse_x>=(1000)&& mouse_x<=(1000+181))&& (mouse_y)>=(50)&& mouse_y<=(59+50))&&(mouse_b && 1))
            {
                sortieClasses=1;
                menuNbJoueur(page,fondMenu,logo, violetCity);
            }


            /*for(int u;u<15;u++)
        {
            textprintf_ex(page,maPolice,100,200,makecol(255,255,0),-1,"%c",joueur[1].pseudo[u]);

        }*/
        textprintf_ex(page,maPolice,10,140,makecol(255,255,0),-1,"Choisis ta classe :");

        show_mouse(page);
        blit(page,screen,0,0,0,0,1200,711);
    }

 }
