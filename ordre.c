#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE  30

char				**ft_split(char *str);

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
char **lecturefichier(int fd)
{
	char **tab_char;
	int x = 0;
	char file_str[BUFFER_SIZE + 1];

	while ((x = read(fd, file_str, BUFFER_SIZE)))
		file_str[x] = '\0';
	char *output = malloc(sizeof(char) * x);
	while ((x = read(fd, file_str, x)))
		output[x] = '\0';
	tab_char = ft_split(output);
	return (tab_char);

}

int main()
{
    int x = 0;
    int y = 0;
	int i = 0;

    int fd = open("stock.txt", O_RDONLY);
    
    char **chainedechaine = lecturefichier(fd);

	while(chainedechaine[i])
		i++;
    tri_iteratif(chainedechaine , chainedechaine[i]);


    while(x <= i)
	{
        printf("%s", chainedechaine[x]);
        x++;
	}
	free(chainedechaine);



    


}
