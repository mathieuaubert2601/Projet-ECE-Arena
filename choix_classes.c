 #include "header.h"
 void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page)
 {
    stretch_blit(fond,page,0,0,800,450,0,0,1200,800);
    masked_stretch_blit(classe1,page,0,0,283,190,-75,400,400,300);
    masked_stretch_blit(classe2,page,0,0,286,190,150,400,400,300);
    masked_stretch_blit(classe3,page,0,0,288,191,375,375,400,300);
    masked_stretch_blit(classe4,page,0,0,287,192,600,375,400,300);
    masked_stretch_blit(classe5,page,0,0,287,192,850,400,400,300);

    AffichageBouton(page,50,650,200,700,makecol(220,220,220));
    AffichageBouton(page,275,650,425,700,makecol(220,220,220));
    AffichageBouton(page,500,650,650,700,makecol(220,220,220));
    AffichageBouton(page,725,650,875,700,makecol(220,220,220));
    AffichageBouton(page,975,650,1125,700,makecol(220,220,220));

    textprintf_ex(page,font,90,670,makecol(0,0,0),-1," Pikachu ");
    textprintf_ex(page,font,310,670,makecol(0,0,0),-1," Ronflex ");
    textprintf_ex(page,font,540,670,makecol(0,0,0),-1," Lucario ");
    textprintf_ex(page,font,760,670,makecol(0,0,0),-1," Alakazam ");
    textprintf_ex(page,font,1000,670,makecol(0,0,0),-1," Rondoudou ");


    }
