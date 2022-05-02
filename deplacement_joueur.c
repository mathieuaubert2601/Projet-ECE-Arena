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
        for(int x = (indice_ligne_ini * cote_X) ; x <= (indice_ligne_finale * cote_X) ; x = x + 2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_pikachu(buffer,indice,3,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_pikachu(buffer,indice,2,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y <= (indice_colonne_finale * cote_y) ; y = y + 2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_pikachu(buffer,indice,0,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_pikachu(buffer,indice,1,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
    }

    //Si le personnage est lucario
    if(personnage == 2)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x <= (indice_ligne_finale * cote_X) ; x = x + 2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_lucario(buffer,indice,3,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_lucario(buffer,indice,2,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y <= (indice_colonne_finale * cote_y) ; y = y + 2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_lucario(buffer,indice,0,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_lucario(buffer,indice,1,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
    }
    //Si le personnage est rondoudou
    if(personnage == 3)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x <= (indice_ligne_finale * cote_X) ; x = x + 2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_rondoudou(buffer,indice,3,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_rondoudou(buffer,indice,2,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y <= (indice_colonne_finale * cote_y) ; y = y + 2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_rondoudou(buffer,indice,0,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_rondoudou(buffer,indice,1,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
    }
    //Si le personnage est alakazam
    if(personnage == 4)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x <= (indice_ligne_finale * cote_X) ; x = x + 2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_alakazam(buffer,indice,3,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_alakazam(buffer,indice,2,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y <= (indice_colonne_finale * cote_y) ; y = y + 2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_alakazam(buffer,indice,0,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_alakazam(buffer,indice,1,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
    }
    //Si le personnage est ronflex
    if(personnage == 5)
    {
        for(int x = (indice_ligne_ini * cote_X) ; x <= (indice_ligne_finale * cote_X) ; x = x + 2 )
        {
            if(indice_ligne_finale > indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_ronflex(buffer,indice,3,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_ligne_finale < indice_ligne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_ronflex(buffer,indice,2,x,indice_colonne_ini);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
        for(int y = (indice_colonne_ini * cote_y) ; y <= (indice_colonne_finale * cote_y) ; y = y + 2 )
        {
            if(indice_colonne_finale > indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_ronflex(buffer,indice,0,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            if(indice_colonne_finale < indice_colonne_ini)
            {
                clear_bitmap(buffer);
                afficher_map(buffer);
                afficher_personnage_ronflex(buffer,indice,1,indice_ligne_ini,y);
                afficher_arbre(buffer);
                blit(buffer,screen,0,0,0,0,1200,711);
                rest(30);
            }
            indice ++ ;
            if(indice == 4)
            {
                indice = 0;
            }
        }
    }
}
