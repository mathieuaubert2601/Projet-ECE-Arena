 #include "header.h"
 void menu_classes (BITMAP* classe1, BITMAP* classe2, BITMAP* classe3, BITMAP* classe4, BITMAP* classe5, BITMAP* fond, BITMAP* page)
 {
    stretch_blit(fond,page,0,0,800,450,0,0,1200,800);
    masked_stretch_blit(classe1,page,0,0,283,190,-75,400,400,300);
    masked_stretch_blit(classe2,page,0,0,286,190,150,400,400,300);
    masked_stretch_blit(classe3,page,0,0,288,191,375,400,400,300);
    masked_stretch_blit(classe4,page,0,0,287,192,600,400,350,300);
    masked_stretch_blit(classe5,page,0,0,287,192,850,400,400,300);
    }
