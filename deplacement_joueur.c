#include "header.h"

void deplacement_joueur(BITMAP* buffer, int indice_ligne_finale, int indice_colonne_finale, int indice_ligne_ini, int indice_colonne_ini, int personnage)
{
    //Déclaration de la taille de cases
    int cote_X = 32;
    int cote_y = 30;
    int indice = 0 ;

    //Si déplacement avec pikachu
    if(personnage == 1)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x == (indice_ligne_finale * cote_X) ; x=x+2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                afficher_personnage_pikachu(buffer,indice,3,x,indice_colonne_ini);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                afficher_personnage_pikachu(buffer,indice,2,x,indice_colonne_ini);
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y == (indice_colonne_finale * cote_y) ; y=y+2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                afficher_personnage_pikachu(buffer,indice,3,indice_ligne_ini,y);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                afficher_personnage_pikachu(buffer,indice,2,indice_ligne_ini,y);
            }
        }
    }

    //Si le personnage est lucario
    if(personnage == 2)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x == (indice_ligne_finale * cote_X) ; x=x+2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                afficher_personnage_lucario(buffer,indice,3,x,indice_colonne_ini);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                afficher_personnage_lucario(buffer,indice,2,x,indice_colonne_ini);
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y == (indice_colonne_finale * cote_y) ; y=y+2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                afficher_personnage_lucario(buffer,indice,3,indice_ligne_ini,y);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                afficher_personnage_lucario(buffer,indice,2,indice_ligne_ini,y);
            }
        }
    }

}
