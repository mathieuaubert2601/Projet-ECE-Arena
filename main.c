#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();

    ///Déclaration des BITMAP
    BITMAP* fond = load_bitmap("fond1.bmp",NULL);
    BITMAP* lucario = load_bitmap("lucario1.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou1.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikatchu1.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex1.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam1.bmp",NULL);

    BITMAP* page=create_bitmap(1200,800);
    clear_bitmap(page);

    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        menu_classes(pikachu,ronflex,lucario,alakazam,rondoudou,fond,page);
        show_mouse(page);

        blit(page,screen,0,0,0,0,1200,800);
        rest(10);
    }
    destroy_bitmap(page);

    return 0;
}END_OF_MAIN();
