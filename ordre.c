#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE  1

char				**ft_split(char *str);

size_t get_file_len(char *filepath)
{
	long int			fd;
	long int			x;
	long int			file_len;
	char				buff[BUFFER_SIZE + 1];

	file_len = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((x = read(fd, buff, BUFFER_SIZE)))
	{
		buff[x] = '\0';
		file_len = file_len + x;
	}
	if (close(fd) == -1)
		return (0);
	return (file_len);
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
char **lecturefichier(char *filepath)
{
	char 		**tab_char;
	size_t 		file_len;
	long int 	x;
	long int 	fd;

	fd = open(filepath, O_RDONLY);
	file_len = get_file_len(filepath);
	char *output = malloc(sizeof(char) * file_len);
	while ((x = read(fd, output, file_len)))
		output[file_len] = '\0';
	tab_char = ft_split(output);
	free(output);
	close(fd);
	return (tab_char);

}

int main()
{
    int x = 0;
    int y = 0;
	int i = 0;
	char *filepath = "stock.txt";
    char **chainedechaine = lecturefichier(filepath);

	while(chainedechaine[i])
	{
		printf("chaine avant = %s\n" ,chainedechaine[i]);
		i++;
	}
    tri_iteratif(chainedechaine , chainedechaine[i]);
	i = 0;
	while(chainedechaine[i])
	{
		printf("chaine apres = %s\n" ,chainedechaine[i]);
		i++;
	}
	free(chainedechaine);



    


}
