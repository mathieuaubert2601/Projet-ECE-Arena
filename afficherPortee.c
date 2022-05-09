#include "header.h"

void afficherPorteeCirc (t_sorts sort1, t_joueur joueur, BITMAP* page)
{
    for (int y=0;y<36;y++)
    {
        for(int x =0;x<18;x++)
        {
            if (((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=4)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=7)))
            {
                casebleu(page,y,x);
            }
        }
    }
}

void afficherPorteeDroite (t_sorts sort1, t_joueur joueur, BITMAP* page)
{
    for (int y=0;y<36;y++)
    {
        for(int x =0;x<18;x++)
        {
            if ((joueur.ligne/32==x) && ((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=4)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=7)) || ((joueur.colonne/30==y) && ((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=4)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=7))))
            {
                casebleu(page,y,x);
            }
        }
    }
}

