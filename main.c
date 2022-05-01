#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

    t_joueur joueur1;

    int violetcity=0;

    ///Declaration des BITMAP
    BITMAP* fond = load_bitmap("fond1.bmp",NULL);
    BITMAP* fondMenu = load_bitmap("fondMenu.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");

    BITMAP* logo = load_bitmap("logo.bmp",NULL);

    BITMAP* page=create_bitmap(1200,711);
    clear_bitmap(page);

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

    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
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
        //afficher_coordonnees(page);

    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
