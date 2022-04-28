 #include "header.h"

void initialisationAllegro()
{

allegro_init();

set_color_depth(desktop_color_depth());

if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,800,0,0))!=
0)

{
allegro_message("Pb de mode graphique") ;

allegro_exit();

exit(EXIT_FAILURE); }
}
