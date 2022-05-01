#include "header.h"

void afficher_caractere(BITMAP* buffer)
{
    FONT* police = load_font("police_ecriture/texte.pcx",NULL,NULL);
    textprintf(buffer,police,150,150,makecol(255,255,255),"bonjour");

}
