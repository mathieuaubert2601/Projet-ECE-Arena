#include "header.h"

void menuNbJoueur(BITMAP* page, BITMAP* fond,BITMAP* logo, int* violetCity)
{

    BITMAP* bouton2 = load_bitmap("boutons/boutonNb2.bmp",NULL);
    BITMAP* bouton2inv = load_bitmap("boutons/boutonInvNb2.bmp",NULL);
    BITMAP* bouton3 = load_bitmap("boutons/boutonNb3.bmp",NULL);
    BITMAP* bouton3inv = load_bitmap("boutons/boutonInvNb3.bmp",NULL);
    BITMAP* bouton4 = load_bitmap("boutons/boutonNb4.bmp",NULL);
    BITMAP* bouton4inv = load_bitmap("boutons/boutonInvNb4.bmp",NULL);
    BITMAP* quitter = load_bitmap("boutons/boutonQuitter.bmp",NULL);
    BITMAP* quitterInv = load_bitmap("boutons/boutonInvQuitter.bmp",NULL);
    BITMAP* phrase = load_bitmap("phrases/choixnombre.bmp",NULL);
    SAMPLE* musiqueFond = load_sample("musiques/VioletCity.wav");



    clear_bitmap(page);
    blit(fond,page,0,0,0,0,1200,711);
    masked_blit(logo,page,0,0,200,50,755,374);
    AffichageBouton(bouton2,bouton2inv,page,0,0,320,540,171,165);
    AffichageBouton(bouton3,bouton3inv,page,0,0,520,540,171,165);
    AffichageBouton(bouton4,bouton4inv,page,0,0,720,540,171,165);
    AffichageBouton(quitter,quitterInv,page,0,0,1000,50,181,59);
    masked_blit(phrase,page,0,0,280,430,652,74);
    show_mouse(page);
    blit(page,screen,0,0,0,0,1200,711);
}
