#include "header.h"

void ordreJoueurs(t_joueur ordreJoueur[],t_joueur tabJoueur[], int nbrJoueur)
{
    ///Déclaration des variables
    int quiCommence = rand()%nbrJoueur + 1;

    if(nbrJoueur == 2)
    {
        if(quiCommence == 1)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[1], sizeof(t_joueur) );
        }
        if(quiCommence == 2)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[0], sizeof(t_joueur) );
        }
    }
    if(nbrJoueur == 3)
    {
        if(quiCommence == 1)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[2], sizeof(t_joueur) );
        }
        if(quiCommence == 2)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[2], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[0], sizeof(t_joueur) );
        }
        if(quiCommence == 3)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[2], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[1], sizeof(t_joueur) );
        }

    }
    if(nbrJoueur == 4)
    {
        if(quiCommence == 1)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[2], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[3], &tabJoueur[3], sizeof(t_joueur) );

        }
        if(quiCommence == 2)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[2], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[3], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[3], &tabJoueur[0], sizeof(t_joueur) );

        }
        if(quiCommence == 3)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[2], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[3], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[3], &tabJoueur[1], sizeof(t_joueur) );

        }
        if(quiCommence == 4)
        {
            memcpy ( &ordreJoueur[0], &tabJoueur[3], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[1], &tabJoueur[0], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[2], &tabJoueur[1], sizeof(t_joueur) );
            memcpy ( &ordreJoueur[3], &tabJoueur[2], sizeof(t_joueur) );
        }

    }
}
