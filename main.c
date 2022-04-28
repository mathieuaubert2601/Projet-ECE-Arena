#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();

    ///Déclaration des BITMAP
    BITMAP* fond = load_bitmap("fond.bmp",NULL);
    BITMAP* lucario = load_bitmap("lucario.bmp",NULL);
    BITMAP* rondoudou = load_bitmap("rondoudou.bmp",NULL);
    BITMAP* pikachu = load_bitmap("pikachu.bmp",NULL);
    BITMAP* ronflex = load_bitmap("ronflex.bmp",NULL);
    BITMAP* alakazam = load_bitmap("alakazam.bmp",NULL);

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
