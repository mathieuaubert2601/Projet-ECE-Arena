#include "header.h"

void afficherPorteeCirc (t_sorts sort1, t_joueur joueur, BITMAP* page)
{
    for (int y=0;y<36;y++)
    {
        for(int x =0;x<17;x++)
        {
            if (((joueur.ligne-x)+(joueur.colonne-y)>=sort1.pMin)&& ((joueur.ligne-x)+(joueur.colonne-y)<=sort1.pMax))
            {
                casebleu(page,x,y);
            }
        }
    }
}
