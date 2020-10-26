#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen_ligne_fichier(FILE* fichier)
{
    int i = 0;
    char lettre;

    do
    {
        lettre = fgetc(fichier);
        if(lettre == '\n')
            i++;
    } while (lettre != EOF);
    
    return i;
}

void tri_iteratif(char *tableau[], int taille)
{
   char *temp; 
   int i, j;

   for (i = 0; i < taille; i++) 
    for (j = 0; j < taille; j++)
      if (strcmp(tableau[i], tableau[j]) < 0)
        {
          temp = tableau[i];
          tableau[i] = tableau[j];
          tableau[j] = temp;
        }
}
char lecturefichier(FILE* fichier , char **chainedechaine)
{
    int i = 0;
    int x = 0;
    char lettre;

    while(lettre != EOF)
    {
        while(lettre != '\n')
        {
            lettre = fgetc(fichier);
            chainedechaine[x][i] = lettre;
            i++;
        }
        x++;
    }
}

int main()
{
    char **chainedechaine = NULL;
    FILE* fichier = NULL;
    int x = 0;
    int y = 0;

    fichier = fopen("stock.txt", "r");
    
    chainedechaine = malloc(sizeof(char*) * ft_strlen_ligne_fichier(fichier));

    lecturefichier(fichier, chainedechaine);

    tri_iteratif(chainedechaine , ft_strlen_ligne_fichier(fichier));

    
    while(x <= ft_strlen_ligne_fichier(fichier));
        printf("%s", chainedechaine[x]);
        x++;

    




    


}