#include "header.h"

void lecture_fichier_matrice_map_base(int matrice_a_remplir[18][36])
{
    //déclaration des variables
    FILE* fichier_a_lire = fopen("fichier_map/map_base.txt","r");
    int caractere_du_fichier;
    int i = 0, j = 0;
    //test d'ouverture du fichier
    if(fichier_a_lire == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    //lecture dans le fichier
    do
    {
        //On récupère le caractère dans le fichier
        caractere_du_fichier = fgetc(fichier_a_lire);
        if(caractere_du_fichier != EOF) //On met le caractère dans la matrice à remplir
        {
            if(caractere_du_fichier == '1')
            {
                matrice_a_remplir[i][j] = 1;
                j++;

            }
            else if (caractere_du_fichier == '0')
            {
                matrice_a_remplir[i][j] = 0;
                j++;
            }
            else if (caractere_du_fichier == '4')
            {
                matrice_a_remplir[i][j] = 4;
                j++;
            }
            if(j == 36)
            {
                j=0;
                i++;
            }
        }
    }
    while(caractere_du_fichier != EOF);

    //On ferme le fichier
    fclose(fichier_a_lire);
    fichier_a_lire = NULL;
}

void lecture_fichier_matrice_map_arbre(int matrice_a_remplir[18][36])
{

    //déclaration des variables
    FILE* fichier_a_lire = fopen("fichier_map/map_arbre.txt","r");
    int caractere_du_fichier;
    int i = 0, j = 0;
    //test d'ouverture du fichier
    if(fichier_a_lire == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    //lecture dans le fichier
    do
    {
        //On récupère le caractère dans le fichier
        caractere_du_fichier = fgetc(fichier_a_lire);
        if(caractere_du_fichier != EOF) //On met le caractère dans la matrice à remplir
        {
            if(caractere_du_fichier == '1')
            {
                matrice_a_remplir[i][j] = 1;
                j++;

            }
            else if (caractere_du_fichier == '0')
            {
                matrice_a_remplir[i][j] = 0;
                j++;
            }
            else if (caractere_du_fichier == '6')
            {
                matrice_a_remplir[i][j] = 6;
                j++;
            }
            if(j == 36)
            {
                j=0;
                i++;
            }
        }
    }
    while(caractere_du_fichier != EOF);

    //On ferme le fichier
    fclose(fichier_a_lire);
    fichier_a_lire = NULL;
}

void mettre_arbre_ou_non(int matrice_a_analyse[18][36])
{
    //On récupère
    lecture_fichier_matrice_map_base(matrice_a_analyse);

    //déclaration des variables
    int chance;
    FILE* matrice_enregistrer = fopen("fichier_map/map_arbre.txt","w+");

    //test d'ouverture du fichier
    if(matrice_enregistrer == NULL)
    {
        printf("erreur dans l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    //boucle pour placer des arbres dans la matrice aléatoirement
    for(int i = 0 ; i < 18 ; i++)
    {
        for(int j = 0 ; j < 36 ; j++)
        {
            if(matrice_a_analyse[i][j] == 4 && (matrice_a_analyse[i+1][j] != 1 && matrice_a_analyse[i-1][j] != 1 && matrice_a_analyse[i-1][j-1] != 1 && matrice_a_analyse[i][j-1] != 1 && matrice_a_analyse[i+1][j-1] != 1 && matrice_a_analyse[i-1][j+1] != 1 && matrice_a_analyse[i+1][j+1] != 1 && matrice_a_analyse[i][j+1] != 1 && matrice_a_analyse[i+1][j] != 6 && matrice_a_analyse[i-1][j] != 6 && matrice_a_analyse[i-1][j-1] != 6 && matrice_a_analyse[i][j-1] != 6 && matrice_a_analyse[i+1][j-1] != 6 && matrice_a_analyse[i-1][j+1] != 6 && matrice_a_analyse[i+1][j+1] != 6 && matrice_a_analyse[i][j+1] != 6))
            {
                chance = rand() % 10;
                if(chance == 1)
                {
                    matrice_a_analyse[i][j] = 6;
                }
            }
        }
    }

    //boucle pour mettre les cases 4 non modifiées à 0
    for(int i = 0 ; i < 18 ; i++)
    {
        for(int j = 0 ; j < 36 ; j++)
        {
            if(matrice_a_analyse[i][j] == 4)
            {
                matrice_a_analyse[i][j] = 0;
            }
        }
    }


    //enregistrement de la matrice dans le fichier
    for(int i = 0 ; i < 18 ; i++)
    {
        for(int j = 0 ; j < 36 ; j++)
        {
            if(matrice_a_analyse[i][j] == 1)
            {
                fputc('1',matrice_enregistrer);
            }
            else if(matrice_a_analyse[i][j] == 0)
            {
                fputc('0',matrice_enregistrer);
            }
            else if(matrice_a_analyse[i][j] == 6)
            {
                fputc('6',matrice_enregistrer);
            }
        }
        fputc('\n',matrice_enregistrer);
    }
    //fermeture du fichier
    fclose(matrice_enregistrer);
    matrice_enregistrer = NULL;

}

void remettre_case_obstacle(int matrice_A_Modifier[18][36])
{
    for(int i=0 ; i<18 ; i++)
    {
        for(int j=0 ; j<36 ; j++)
        {
            if(matrice_A_Modifier[i][j] == 6)
            {
                matrice_A_Modifier[i][j] = 1;
            }
        }
    }

}
