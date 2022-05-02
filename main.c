#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");



    int violetcity=0;
    //int x = 20;
    //int y = 80;
    //int i = 0;


    //Declaration Bitmap Pikachu sorts
    BITMAP* cageE = load_bitmap("pikachu/CageEclair.bmp",NULL);
    BITMAP* cageEInv = load_bitmap("pikachu/CageEclairInv.bmp",NULL);
    BITMAP* fatF = load_bitmap("pikachu/FatalFoudre.bmp",NULL);
    BITMAP* fatFInv = load_bitmap("pikachu/FatalFoudreInv.bmp",NULL);
    BITMAP* boulE = load_bitmap("pikachu/BouleElek.bmp",NULL);
    BITMAP* boulEInv = load_bitmap("pikachu/BoulEInv.bmp",NULL);
    BITMAP* coupJ = load_bitmap("pikachu/CoupJus.bmp",NULL);
    BITMAP* coupJInv = load_bitmap("pikachu/CoupJusInv.bmp",NULL);
    BITMAP* vitEx = load_bitmap("pikachu/VitesseExtreme.bmp",NULL);
    BITMAP* vitExInv = load_bitmap("pikachu/VitesseExtremeInv.bmp",NULL);

    //Declaration Bitmap Ronflex sorts
    BITMAP* coupB = load_bitmap("ronflex/CoupBoule.bmp",NULL);
    BITMAP* coupBInv = load_bitmap("ronflex/CoupBouleInv.bmp",NULL);
    BITMAP* seisme = load_bitmap("ronflex/Seisme.bmp",NULL);
    BITMAP* seismeInv = load_bitmap("ronflex/SeismeInv.bmp",NULL);
    BITMAP* charge = load_bitmap("ronflex/Charge.bmp",NULL);
    BITMAP* chargeInv = load_bitmap("ronflex/ChargeInv.bmp",NULL);
    BITMAP* boulA = load_bitmap("ronflex/BoulArmure.bmp",NULL);
    BITMAP* boulAInv = load_bitmap("ronflex/BoulArmureInv.bmp",NULL);
    BITMAP* repos = load_bitmap("ronflex/Repos.bmp",NULL);
    BITMAP* reposInv = load_bitmap("ronflex/ReposInv.bmp",NULL);

    //Declaration Bitmap Lucario sorts
    BITMAP* rugis = load_bitmap("lucario/Rugissement.bmp",NULL);
    BITMAP* rugisInv = load_bitmap("lucario/RugissementInv.bmp",NULL);
    BITMAP* aura = load_bitmap("lucario/Aurasphere.bmp",NULL);
    BITMAP* auraInv = load_bitmap("lucario/AurasphereInv.bmp",NULL);
    BITMAP* closeC = load_bitmap("lucario/CloseCombat.bmp",NULL);
    BITMAP* closeCInv = load_bitmap("lucario/CloseCombatInv.bmp",NULL);
    BITMAP* vitExL = load_bitmap("lucario/VitesseExtreme.bmp",NULL);
    BITMAP* vitExLInv = load_bitmap("lucario/VitesseExtremeInv.bmp",NULL);
    BITMAP* hate = load_bitmap("lucario/Hate.bmp",NULL);
    BITMAP* hateInv = load_bitmap("lucario/HateInv.bmp",NULL);

    //Declaration Bitmap Alakazam sorts
    BITMAP* toxic = load_bitmap("alakazam/Toxic.bmp",NULL);
    BITMAP* toxicInv = load_bitmap("alakazam/ToxicInv.bmp",NULL);
    BITMAP* psyko = load_bitmap("alakazam/Psyko.bmp",NULL);
    BITMAP* psykoInv = load_bitmap("alakazam/PsykoInv.bmp",NULL);
    BITMAP* teleport = load_bitmap("alakazam/Teleport.bmp",NULL);
    BITMAP* teleportInv = load_bitmap("alakazam/TeleportInv.bmp",NULL);
    BITMAP* autoSoin = load_bitmap("alakazam/AutoSoin.bmp",NULL);
    BITMAP* autoSoinInv = load_bitmap("alakazam/AutoSoinInv.bmp",NULL);

    //Declaration Bitmap Rondoudou sorts
    BITMAP* berceuse = load_bitmap("rondoudou/Berceuse.bmp",NULL);
    BITMAP* berceuseInv = load_bitmap("rondoudou/BerceuseInv.bmp",NULL);
    BITMAP* vaguePsy = load_bitmap("rondoudou/VaguePsy.bmp",NULL);
    BITMAP* vaguePsyInv = load_bitmap("rondoudou/VaguePsyInv.bmp",NULL);
    BITMAP* torgnoles = load_bitmap("rondoudou/Torgnoles.bmp",NULL);
    BITMAP* torgnolesInv = load_bitmap("rondoudou/TorgnolesInv.bmp",NULL);
    BITMAP* soin = load_bitmap("rondoudou/Soin.bmp",NULL);
    BITMAP* soinInv = load_bitmap("rondoudou/SoinInv.bmp",NULL);

    ///Déclaration sorts
    t_sorts vitesseExtreme={0,0,0,80,2,0,3,0,7,0,0,0,vitEx,vitExInv};
    t_sorts vitesseExtremeL={0,0,0,80,2,0,3,0,7,0,0,0,vitExL,vitExLInv};
    t_sorts fatalFoudre={15,1,8,50,1,4,7,0,10,1,0,0,fatF,fatFInv};
    t_sorts bouleElek={10,2,5,75,1,3,5,2,6,2,0,0,boulE,boulEInv};
    t_sorts couDjus={6,3,4,90,1,2,5,0,3,3,0,0,coupJ,coupJInv};
    t_sorts cageEclair={0,4,0,25,3,2,4,0,7,3,3,0,cageE,cageEInv};
    t_sorts boulArmure={0,5,0,50,4,0,0,0,7,0,0,1,boulA,boulAInv};
    t_sorts reposS={100,6,25,60,4,0,0,0,10,0,1,2,repos,reposInv};
    t_sorts coupDboule={5,7,4,95,1,1,3,0,3,3,0,0,coupB,coupBInv};
    t_sorts seismeS={9,8,15,50,1,1,4,0,10,3,0,0,seisme,seismeInv};
    t_sorts chargeS={0,9,0,50,2,0,5,0,7,0,0,0,charge,chargeInv};
    t_sorts rugissement={0,10,0,40,2,0,2,0,3,3,4,0,rugis,rugisInv};
    t_sorts aurasphere={12,11,5,75,1,3,6,0,6,1,0,0,aura,auraInv};
    t_sorts closeCombat={15,12,3,60,1,1,3,0,6,3,0,0,closeC,closeCInv};
    t_sorts hateS={0,13,0,70,2,0,0,0,4,0,5,0,hate,hateInv};
    t_sorts toxicS={0,14,0,25,3,2,4,0,5,3,1,0,toxic,toxicInv};
    t_sorts psykoS={12,15,8,60,1,3,5,0,6,3,0,0,psyko,psykoInv};
    t_sorts teleportS={0,16,0,50,2,0,4,0,8,3,0,0,teleport,teleportInv};
    t_sorts autoSoinS={5,17,10,95,4,0,0,0,2,0,0,2,autoSoin,autoSoinInv};
    t_sorts vaguePsyS={7,18,5,80,1,2,8,0,5,1,0,0,vaguePsy,vaguePsyInv};
    t_sorts torgnolesS={8,19,2,80,1,0,2,0,5,3,0,0,torgnoles,torgnolesInv};
    t_sorts soinS={50,20,10,75,2,0,2,0,10,3,0,3,soin,soinInv};
    t_sorts berceuseS={0,21,0,50,2,0,3,0,6,3,2,0,berceuse,berceuseInv};

    t_sorts tabSorts[23]={vitesseExtreme,fatalFoudre,bouleElek,couDjus,cageEclair,boulArmure,reposS,coupDboule,seismeS,chargeS,rugissement,aurasphere,closeCombat,vitesseExtremeL,hateS,toxicS,psykoS,teleportS,autoSoinS,vaguePsyS,torgnolesS,soinS,berceuseS};

    //Déclaration du tableau de case :
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

    BITMAP* logo = load_bitmap("logo.bmp",NULL);

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);



    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        /*if (violetcity==0)
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
        blit(page,screen,0,0,0,0,1200,711);*/
        afficher_map(page);
        afficher_cases_non_obstacles(tableau_Cases,page);
        afficher_arbre(page);
        blit(page,screen,0,0,0,0,1200,711);
        rest(20);

    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
