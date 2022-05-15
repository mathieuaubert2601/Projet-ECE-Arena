#include "header.h"

void deplacement_joueur(BITMAP* buffer, int indice_ligne_ini, int indice_colonne_ini, int personnage,int tableau_chemin_court[18][36],int tableau_affichage_arbre[18][32])
{
    //Déclaration de la taille de cases
    int cote_X = 30,cote_y = 32,indice = 0,case_x_tmp = indice_colonne_ini,case_y_tmp = indice_ligne_ini, case_x_prec = indice_colonne_ini, case_y_prec = indice_ligne_ini, changement = 0;

    //Si déplacement avec pikachu
    if(personnage == 1)
    {
        do
        {
            changement = 0;
            if(tableau_chemin_court[case_y_tmp][case_x_tmp+ 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i <= (case_x_tmp+ 1) * cote_X ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_pikachu(buffer,indice,3,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp + 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp - 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp][case_x_tmp - 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i >= (case_x_tmp - 1) * cote_X ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_pikachu(buffer,indice,2,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp - 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp + 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp + 1][case_x_tmp] == 30 )
            {
                for(int i = case_y_tmp * cote_y ; i <= (case_y_tmp + 1) * cote_y ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_pikachu(buffer,indice,0,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp + 1;
                tableau_chemin_court[case_y_tmp -1 ][case_x_tmp] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp - 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i >= (case_y_tmp - 1) * cote_y ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_pikachu(buffer,indice,1,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp - 1;
                tableau_chemin_court[case_y_tmp+1][case_x_tmp] = 2;
                changement = 1;
            }

        }
        while(changement == 1);

    }

    //Si le personnage est lucario
    if(personnage == 2)
    {
        do
        {
            changement = 0;
            if(tableau_chemin_court[case_y_tmp][case_x_tmp+ 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i <= (case_x_tmp+ 1) * cote_X ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_lucario(buffer,indice,3,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp + 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp - 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp][case_x_tmp - 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i >= (case_x_tmp - 1) * cote_X ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_lucario(buffer,indice,2,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp - 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp + 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp + 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i <= (case_y_tmp + 1) * cote_y ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_lucario(buffer,indice,0,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp + 1;
                tableau_chemin_court[case_y_tmp -1 ][case_x_tmp] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp - 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i >= (case_y_tmp - 1) * cote_y ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_lucario(buffer,indice,1,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp - 1;
                tableau_chemin_court[case_y_tmp+1][case_x_tmp] = 2;
                changement = 1;
            }

        }
        while(changement == 1);
    }
    //Si le personnage est rondoudou
    if(personnage == 3)
    {
        do
        {
            changement = 0;
            if(tableau_chemin_court[case_y_tmp][case_x_tmp+ 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i <= (case_x_tmp+ 1) * cote_X ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_rondoudou(buffer,indice,3,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp + 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp - 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp][case_x_tmp - 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i >= (case_x_tmp - 1) * cote_X ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_rondoudou(buffer,indice,2,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp - 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp + 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp + 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i <= (case_y_tmp + 1) * cote_y ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_rondoudou(buffer,indice,0,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp + 1;
                tableau_chemin_court[case_y_tmp -1 ][case_x_tmp] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp - 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i >= (case_y_tmp - 1) * cote_y ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_rondoudou(buffer,indice,1,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp - 1;
                tableau_chemin_court[case_y_tmp+1][case_x_tmp] = 2;
                changement = 1;
            }

        }
        while(changement == 1);
    }
    //Si le personnage est alakazam
    if(personnage == 4)
    {
        do
        {
            changement = 0;
            if(tableau_chemin_court[case_y_tmp][case_x_tmp+ 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i <= (case_x_tmp+ 1) * cote_X ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_alakazam(buffer,indice,3,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp + 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp - 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp][case_x_tmp - 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i >= (case_x_tmp - 1) * cote_X ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_alakazam(buffer,indice,2,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp - 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp + 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp + 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i <= (case_y_tmp + 1) * cote_y ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_alakazam(buffer,indice,0,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp + 1;
                tableau_chemin_court[case_y_tmp -1 ][case_x_tmp] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp - 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i >= (case_y_tmp - 1) * cote_y ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_alakazam(buffer,indice,1,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp - 1;
                tableau_chemin_court[case_y_tmp+1][case_x_tmp] = 2;
                changement = 1;
            }

        }
        while(changement == 1);
    }
    //Si le personnage est ronflex
    if(personnage == 5)
    {
        do
        {
            changement = 0;
            if(tableau_chemin_court[case_y_tmp][case_x_tmp+ 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i <= (case_x_tmp+ 1) * cote_X ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_ronflex(buffer,indice,3,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp + 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp - 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp][case_x_tmp - 1] == 30)
            {
                for(int i = case_x_tmp * cote_X ; i >= (case_x_tmp - 1) * cote_X ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_ronflex(buffer,indice,2,i,(case_y_tmp * 32));
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_x_tmp = case_x_tmp - 1;
                tableau_chemin_court[case_y_tmp][case_x_tmp + 1] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp + 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i <= (case_y_tmp + 1) * cote_y ; i++)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_ronflex(buffer,indice,0,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp + 1;
                tableau_chemin_court[case_y_tmp -1 ][case_x_tmp] = 2;
                changement = 1;
            }
            else if(tableau_chemin_court[case_y_tmp - 1][case_x_tmp] == 30)
            {
                for(int i = case_y_tmp * cote_y ; i >= (case_y_tmp - 1) * cote_y ; i--)
                {
                    clear_bitmap(buffer);
                    afficher_map(buffer);
                    afficher_personnage_ronflex(buffer,indice,1,case_x_tmp * 30,i);
                    afficher_tout_arbre(buffer,tableau_affichage_arbre);
                    blit(buffer,screen,0,0,0,0,1200,711);
                    rest(30);

                    indice ++;
                    if(indice == 4)
                    {
                        indice = 0;
                    }
                }
                case_y_tmp = case_y_tmp - 1;
                tableau_chemin_court[case_y_tmp+1][case_x_tmp] = 2;
                changement = 1;
            }

        }
        while(changement == 1);
    }
}
