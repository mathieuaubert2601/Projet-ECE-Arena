#include "header.h"

void ordreJoueurs2(t_joueur* tab[],int nbJoueurs,t_joueur* joueur1, t_joueur* joueur2)
{
    joueur1->numero=rand()%1;
    if(joueur1->numero==1)
    {
        joueur2->numero=0;
    }
    if(joueur1->numero==0)
    {
        joueur2->numero=1;
    }
    tab[joueur1->numero]=joueur1;
    tab[joueur2->numero]=joueur2;
}

void ordreJoueurs3(t_joueur* tab[],int nbJoueurs,t_joueur* joueur1, t_joueur* joueur2, t_joueur* joueur3)
{
    joueur1->numero=rand()%2;
    do
    {
        joueur2->numero=rand()%2;
    }while(joueur2->numero==joueur1->numero);

    do
    {
        joueur3->numero=rand()%2;
    }while(joueur3->numero==joueur1->numero || joueur3->numero == joueur2->numero);

    tab[joueur1->numero]=joueur1;
    tab[joueur2->numero]=joueur2;
    tab[joueur3->numero]=joueur3;
}

void ordreJoueurs4(t_joueur* tab[],int nbJoueurs,t_joueur* joueur1, t_joueur* joueur2,t_joueur* joueur3,t_joueur* joueur4)
{
    joueur1->numero=rand()%3;
    do
    {
        joueur2->numero=rand()%3;
    }while(joueur2->numero==joueur1->numero);

    do
    {
        joueur3->numero=rand()%3;
    }while(joueur3->numero==joueur1->numero || joueur3->numero == joueur2->numero);

    do
    {
        joueur4->numero=rand()%3;
    }while(joueur4->numero==joueur1->numero || joueur4->numero == joueur2->numero || joueur4->numero == joueur3->numero);

    tab[joueur1->numero]=joueur1;
    tab[joueur2->numero]=joueur2;
    tab[joueur3->numero]=joueur3;
    tab[joueur4->numero]=joueur4;
}
