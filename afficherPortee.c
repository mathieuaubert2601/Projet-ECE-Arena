#include "header.h"

void afficherPorteeCirc (t_sorts sort1, t_joueur joueur, BITMAP* page)
{
    for (int y=0;y<36;y++)
    {
        for(int x =0;x<18;x++)
        {
            if (((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=sort1.pMin)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=sort1.pMax)))
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
            if ((joueur.ligne/32==x) && ((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=sort1.pMin)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=sort1.pMax)) || ((joueur.colonne/30==y) && ((abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)>=sort1.pMin)&&(abs((joueur.ligne/32)-x)+abs((joueur.colonne/30)-y)<=sort1.pMax))))
            {
                casebleu(page,y,x);
            }
        }
    }
}

