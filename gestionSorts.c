#include "header.h"

void lancerSort(t_sorts sort1, t_joueur* joueurA, t_joueur* tabJoueurs[], int nombreJoueur, int tourJoueur)
{
    int totalTouche = 0;
    int touche=0;
    if (sort1.type == 1)
    {
        if (joueurA->pa>=sort1.nbrPa)
        {
            while((tourJoueur+1) != (joueurA->numero))
            {
                touche = sortAttaque(sort1,joueurA,tabJoueurs[tourJoueur+1]);
                totalTouche+=touche;
                tourJoueur++;
                if (tourJoueur == nombreJoueur-1)
                {
                    tourJoueur=0;
                }
            }
            if(totalTouche>=1)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else if (totalTouche<1)
            {
                ///Afficher aucun joueur dans la zone
            }
        }
        else if (joueurA->pa<sort1.nbrPa)
        {
            ///Afficher pas assez de PA
        }
    }
    if (sort1.type == 2)
    {
        sortMouvement(sort1,joueurA);
    }
    if (sort1.type == 3)
    {
        if (joueurA->pa>=sort1.nbrPa)
        {
            while((tourJoueur+1) != (joueurA->numero))
            {
                touche = sortStatut(sort1,joueurA,tabJoueurs[tourJoueur+1]);
                totalTouche+=touche;
                tourJoueur++;
                if (tourJoueur == nombreJoueur-1)
                {
                    tourJoueur=0;
                }
            }
            if(totalTouche>=1)
            {
                joueurA->pa-=sort1.nbrPa;
            }
            else if (totalTouche<1)
            {
                ///Afficher aucun joueur dans la zone
            }
        }
        else if (joueurA->pa<sort1.nbrPa)
        {
            ///Afficher pas assez de PA
        }
    }
    if (sort1.type == 4)
    {
        sortVie(sort1,joueurA);
    }
}

int sortAttaque(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB)
{
    int probabilite;
    int nombrePv;
    ///Attaque en zone
    if (sort1.typePortee == 1)
    {
        if (((joueurA->ligne-joueurB->ligne)+(joueurA->colonne-joueurB->colonne)>=sort1.pMin)&& ((joueurA->ligne-joueurB->ligne)+(joueurA->colonne-joueurB->colonne)<=sort1.pMax))
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                joueurB->pv -= nombrePv;
                if (joueurB->pv <0)
                {
                    joueurB->pv = 0;
                }
            }
            else if (probabilite>=sort1.chance)
            {
                ///Afficher sort raté
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    ///Attaque en ligne droite
    if (sort1.typePortee == 3)
    {
        if(1==1)
        {
            probabilite=rand() % 100 ;
            if (probabilite<sort1.chance)
            {
                nombrePv = sort1.degats + rand()%(sort1.plusMoins);
                joueurB->pv -= nombrePv;
                if (joueurB->pv <0)
                {
                    joueurB->pv = 0;
                }
            }
            else if (probabilite>=sort1.chance)
            {
                ///Afficher sort raté
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void sortMouvement(t_sorts sort1, t_joueur* joueurA)
{
    int caseChoisieLigne, caseChoisieColonne, sortie_mouv = 0,probabilite;
    if (sort1.numero==13)
    {
        probabilite=rand() % 100 ;
        if (probabilite<sort1.chance)
        {
            joueurA->tourHate = 2;
        }
        else if (probabilite>=sort1.chance)
        {
            ///Afficher sort raté
        }
        joueurA->pa-=sort1.nbrPa;
    }
    else
    {
        do
        {
            if (mouse_b && 1)
            {
                caseChoisieColonne = mouse_x/30;
                caseChoisieLigne = mouse_y/32;
            }
            if (mouse_b && 0)
            {
                sortie_mouv = 1;
            }
        }while ((((joueurA->ligne-caseChoisieLigne)+(joueurA->colonne-caseChoisieColonne)>=sort1.pMin)&& ((joueurA->ligne-caseChoisieLigne)+(joueurA->colonne-caseChoisieColonne)<=sort1.pMax))|| (sortie_mouv == 0));
        if (sortie_mouv == 0)
        {
            probabilite=rand() % 100 ;
            if (probabilite<sort1.chance)
            {
                joueurA->ligne= caseChoisieLigne;
                joueurA->colonne=caseChoisieColonne;
            }
            else if (probabilite>=sort1.chance)
            {
                ///Afficher sort raté
            }
            joueurA->pa-=sort1.nbrPa;
        }
    }

}

int sortStatut(t_sorts sort1, t_joueur* joueurA, t_joueur* joueurB)
{
    int probabilite;
    if (((joueurA->ligne-joueurB->ligne)+(joueurA->colonne-joueurB->colonne)>=sort1.pMin)&& ((joueurA->ligne-joueurB->ligne)+(joueurA->colonne-joueurB->colonne)<=sort1.pMax))
        {
            probabilite=rand() % 100;
            if (probabilite<sort1.chance)
            {
                if (sort1.typeStatus == 1)
                {
                    joueurB->tourPoison = 5;
                }
                if (sort1.typeStatus == 2)
                {
                    joueurB->tourDodo = 3;
                }
                if (sort1.typeStatus == 3)
                {
                    joueurB->tourParalysie = 2;
                }
                if (sort1.typeStatus == 4)
                {
                    joueurB->tourPeur = 1;
                }
            }
            else if (probabilite>=sort1.chance)
            {
                ///Afficher sort raté
            }
            return 1;
        }
        else
        {
            return 0;
        }
}

void sortVie(t_sorts sort1, t_joueur* joueurA)
{

}
